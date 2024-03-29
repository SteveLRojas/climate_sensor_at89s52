//                     /\         /\__
//                   // \       (  0 )_____/\            __
//                  // \ \     (vv          o|          /^v\
//                //    \ \   (vvvv  ___-----^        /^^/\vv\
//              //  /     \ \ |vvvvv/               /^^/    \v\
//             //  /       (\\/vvvv/              /^^/       \v\
//            //  /  /  \ (  /vvvv/              /^^/---(     \v\
//           //  /  /    \( /vvvv/----(O        /^^/           \v\
//          //  /  /  \  (/vvvv/               /^^/             \v|
//        //  /  /    \( vvvv/                /^^/               ||
//       //  /  /    (  vvvv/                 |^^|              //
//      //  / /    (  |vvvv|                  /^^/            //
//     //  / /   (    \vvvvv\          )-----/^^/           //
//    // / / (          \vvvvv\            /^^^/          //
//   /// /(               \vvvvv\        /^^^^/          //
//  ///(              )-----\vvvvv\    /^^^^/-----(      \\
// //(                        \vvvvv\/^^^^/               \\
///(                            \vvvv^^^/                 //
//                                \vv^/         /        //
//                                             /<______//
//                                            <<<------/
//                                             \<
//                                              \
//****************************************************
//* Climate Sensor with Calendar for AT89S52         *
//* Copyright (C) 2023 all rights reserved           *
//*     Esteban Looser and Jakob Grootens.           *
//*                                                  *
//*                                                  *
//****************************************************

#include <at89x52.h>

__sfr __at(0xFF) nothing;

void mDelay10uS(unsigned int n);              // Delay in uS
void mDelaymS(unsigned int n);              // Delay in mS

// PORTS - Display
#define VFD_CS P3_3
#define VFD_WR P3_2
#define VFD_DATA P1

// Button Module
#define BTN_1 P2_7
#define BTN_2 P2_6
#define BTN_3 P2_5
#define BTN_4 P2_4
#define BTN_5 P2_3
#define BTN_6 P2_2
#define BTN_7 P2_1
#define BTN_8 P2_0
#define BTN_DATA P2

// PORTS - Timekeeper
#define RTC_CE_PIN  P3_4
#define RTC_DATA_PIN P3_5
#define RTC_SCLK_PIN P3_6

// PORTS - Digital Humidity & Temp Sensor 
#define DHT_DATA P3_7

// PORTS - Other
#define LED_TEST P0_0

// Display Commands
#define CMD_CLR 0x0E
#define CMD_CRET 0x0D
#define CMD_ESC 0x1B
#define CMD_RST 0x49

// Data Display Relationships
#define DISP_LEN        20 
#define RH_DISP_LEN     14
#define RH_MAX_OFFSET   (DISP_LEN - RH_DISP_LEN)
#define T_DISP_LEN      18
#define T_MAX_OFFSET    (DISP_LEN - T_DISP_LEN)
#define TIME_DISP_LEN   11
#define TIME_MAX_OFFSET (DISP_LEN - TIME_DISP_LEN)
#define DATE_DISP_LEN   16
#define DATE_MAX_OFFSET (DISP_LEN - DATE_DISP_LEN)

// Timekeeper Commands
#define CMD_R_SEC   0x81
#define CMD_R_MIN   0x83
#define CMD_R_HOUR  0x85
#define CMD_R_DATE  0x87
#define CMD_R_MONTH 0x89
#define CMD_R_DAY   0x8B
#define CMD_R_YEAR  0x8D
#define CMD_W_SEC   0x80
#define CMD_W_MIN   0x82
#define CMD_W_HOUR  0x84
#define CMD_W_DATE  0x86
#define CMD_W_MONTH 0x88
#define CMD_W_DAY   0x8A
#define CMD_W_YEAR  0x8C

// Globals
unsigned int RH;
unsigned int T;

unsigned char offsetRH = 0;
char dirRH = 1;
unsigned char offsetT = 0;
char dirT = 1;
unsigned char offsetTime = 0;
char dirTime = 1;
unsigned char offsetDate = 0;
char dirDate = 1;

unsigned char humidity[5];
unsigned char temperature[6];
unsigned char time[6]; // HH:MM'\0'
unsigned char date[11]; // DD.MM.YYYY'\0'

unsigned char twoDigits;

void mDelay10uS(unsigned int n)  // Delay in units of 10 uS
{
    while ( n )
    {
        ++ nothing;
        -- n;
    }
}

void mDelaymS(unsigned int n)   // Delay in mS
{
    while ( n )
    {
        mDelay10uS(100);
        -- n;
    }
}

void VFD_putc(char c)
{
    mDelay10uS(10);
    VFD_CS = 0;
    VFD_DATA = c;
    VFD_WR = 0;
    VFD_WR = 1;
    VFD_CS = 1;
    return;
}

// Adds delay for the command
void inline VFD_putcmd(char cmd)
{
    VFD_putc(cmd);
    mDelay10uS(100);
}

void VFD_print(char* str)
{
    unsigned char i = 0;
    while(str[i])
    {
        VFD_putc(str[i]);
        i++;
    }
}

void inline VFD_padding(unsigned char offset)
{
    while(offset != 0)
    {
        VFD_putc(' ');
        offset--;
    }
}

void inline VFD_clear()
{
    VFD_putcmd(CMD_CRET);
    VFD_putcmd(CMD_CLR);
}

void inline VFD_reset()
{
    VFD_putcmd(CMD_ESC);
    VFD_putcmd(CMD_RST);
    VFD_clear();
}

void RTC_Write(unsigned char address, unsigned char data)
{
    RTC_CE_PIN = 1;
    //address = address & 0xF7;
    //address = address | 0x80;
    for(unsigned char i = 0; i < 8; ++i)
    {
        RTC_DATA_PIN = address & 0x01;
        mDelay10uS(1);
        RTC_SCLK_PIN = 1;
        mDelay10uS(1);
        RTC_SCLK_PIN = 0;
        address = address >> 1;
    }
    for(unsigned char i = 0; i < 8; ++i)
    {
        RTC_DATA_PIN = data & 0x01;
        mDelay10uS(1);
        RTC_SCLK_PIN = 1;
        mDelay10uS(1);
        RTC_SCLK_PIN = 0;
        data = data >> 1;
    }
    RTC_CE_PIN = 0;
}

unsigned char RTC_Read(unsigned char address)
{
    unsigned char data;
    RTC_CE_PIN = 1;
    //address = address | 0x81;
    for(unsigned char i = 0; i < 8; ++i)
    {
        mDelay10uS(1);
        RTC_SCLK_PIN = 0;
        RTC_DATA_PIN = address & 0x01;
        address = address >> 1;
        mDelay10uS(1);
        RTC_SCLK_PIN = 1;
    }
    RTC_DATA_PIN = 1;
    for(unsigned char d = 0; d < 8; ++d)
    {
        RTC_SCLK_PIN = 1;
        mDelay10uS(1);
        RTC_SCLK_PIN = 0;
        mDelay10uS(1);
        data = data >> 1;
        data = data | (((unsigned char)RTC_DATA_PIN) << 7);
    }
    RTC_CE_PIN = 0;
    return data;
}

void RTC_set_time()
{
    // Wait for user to lift Time Edit button
    while(!BTN_2);

    // Display the editable time
    VFD_clear();
    VFD_print("Set Time: ");
    VFD_print(time);

    // Accept input until Time Edit button is pressed again
    while(BTN_2)
    {
        if (!BTN_4) // Up Hr Pressed
        {
            while (!BTN_4); // Wait for release
            ++time[1];
            if (time[1] > 0x39)
            {
                time[1] = 0x30;
                ++time[0];
            }
            if ((time[0] > 0x31) && (time[1] > 0x33)) // Wrap to 00
            {
                time[0] = 0x30;
                time[1] = 0x30;
            }
        }
        else if (!BTN_3) // Down Hr Pressed
        {
            while (!BTN_3); // Wait for release
            --time[1];
            if (time[1] < 0x30)
            {
                time[1] = 0x39;
                --time[0];
            }
            if (time[0] < 0x30) // Wrap to 23
            {
                time[0] = 0x32;
                time[1] = 0x33;
            }
        }
        else if (!BTN_6) // Up Min Pressed
        {
            while (!BTN_6); // Wait for release
            ++time[4];
            if (time[4] > 0x39)
            {
                time[4] = 0x30;
                ++time[3];
            }
            if (time[3] > 0x35) // Wrap to 00
            {
                time[3] = 0x30;
                time[4] = 0x30;
            }
        }
        else if (!BTN_5) // Down Min Pressed
        {
            while (!BTN_5); // Wait for release
            --time[4];
            if (time[4] < 0x30)
            {
                time[4] = 0x39;
                --time[3];
            }
            if (time[3] < 0x30) // Wrap to 59
            {
                time[3] = 0x35;
                time[4] = 0x39;
            }
        }
        else
        {
            continue;
        }

        // Display the edited time
        VFD_clear();
        VFD_print("Set Time: ");
        VFD_print(time);
    }

    // Wait for Time Edit button to be lifted again
    while(!BTN_2);

    // Set new time and resume
    RTC_Write(CMD_W_SEC, 0x00);
    RTC_Write(CMD_W_MIN, ((time[3] << 4) | (time[4] & 0x0F)));
    RTC_Write(CMD_W_HOUR, ((time[0] << 4) | (time[1] & 0x0F)));
}

void RTC_set_date()
{
    // Wait for user to lift Date Edit button
    while(!BTN_1);

    // Display the editable Date
    VFD_clear();
    VFD_print("Set Date: ");
    VFD_print(date);

    // Accept input until Date Edit button is pressed again
    while(BTN_1)
    {
        if (!BTN_4) // Up Date Pressed
        {
            while (!BTN_4); // Wait for release
            ++date[1];
            if (date[1] > 0x39)
            {
                date[1] = 0x31;
                ++date[0];
            }
            if (date[0] > 0x32 && date[1] > 0x31) // Wrap to 01
            {
                date[0] = 0x30;
                date[1] = 0x31;
            }
        }
        else if (!BTN_3) // Down Date Pressed
        {
            while (!BTN_3); // Wait for release
            --date[1];
            if ((date[1] < 0x30) || ((date[0] < 0x31) && (date[1] < 0x31))) // 1,-1 or 0,0
            {
                date[1] = 0x39;
                --date[0];
            }
            if (date[0] < 0x30) // Wrap to 31
            {
                date[0] = 0x33;
                date[1] = 0x31;
            }
        }
        else if (!BTN_6) // Up Month Pressed
        {
            while (!BTN_6); // Wait for release
            ++date[4];
            if (date[4] > 0x39)
            {
                date[4] = 0x30;
                ++date[3];
            }
            if (date[3] > 0x30 && date[4] > 0x32) // Wrap to 01
            {
                date[3] = 0x30;
                date[4] = 0x31;
            }
        }
        else if (!BTN_5) // Down Month Pressed
        {
            while (!BTN_5); // Wait for release
            --date[4];
            if ((date[4] < 0x30) || ((date[3] < 0x31) && (date[4] < 0x31))) // 1,-1 or 0,0
            {
                date[4] = 0x39;
                --date[3];
            }
            if (date[3] < 0x30) // Wrap to 12
            {
                date[3] = 0x31;
                date[4] = 0x32;
            }
        }
        else if (!BTN_8) // Up Year Pressed
        {
            while (!BTN_8); // Wait for release
            ++date[9];
            if (date[9] > 0x39)
            {
                date[9] = 0x30;
                ++date[8];
            }
            if (date[8] > 0x39) // Wrap to 00
            {
                date[8] = 0x30;
                date[9] = 0x30;
            }
        }
        else if (!BTN_7) // Down Year Pressed
        {
            while (!BTN_7); // Wait for release
            --date[9];
            if (date[9] < 0x30)
            {
                date[9] = 0x39;
                --date[8];
            }
            if (date[8] < 0x30) // Wrap to 99
            {
                date[8] = 0x39;
                date[9] = 0x39;
            }
        }
        else
        {
            continue;
        }
        
        // Display the edited Date
        VFD_clear();
        VFD_print("Set Date: ");
        VFD_print(date);
    }

    // Wait for Date Edit button to be lifted again
    while(!BTN_1);

    // Set new Date and resume
    RTC_Write(CMD_W_YEAR,  ((date[8] << 4) | (date[9] & 0x0F)));
    RTC_Write(CMD_W_MONTH, ((date[3] << 4) | (date[4] & 0x0F)));
    RTC_Write(CMD_W_DATE,  ((date[0] << 4) | (date[1] & 0x0F)));
}


void inline DHT_start_signal()
{
    DHT_DATA = 0;
    mDelay10uS(100);
    DHT_DATA = 1;
    //__delay_us(1);
}

// Reads Humidity, Temp, Checksum from sensor
void inline DHT_read_data()
{
	unsigned char chksum;

	DHT_start_signal(); // Host send start signal        
    while(DHT_DATA)
    {
        // Pull up and wait for sensor's response
    }
    while(!DHT_DATA)
    {
        // Sensor send out response
    }
    while(DHT_DATA)
    {
        // Sensor pulls up - get ready to output signal
    }

    // Read humidity
    for(unsigned char i = 0; i < 16; i++)
    {
        while(!DHT_DATA);	//wait for pulse to begin
    
        mDelay10uS(4);
        //LED_TEST = DHT_DATA;
        RH = RH << 1;
        if(DHT_DATA)
        {
            RH = RH | 1;
        }
        
        while(DHT_DATA);	//wait for pulse to end (if it hasnt already)
    }

    // Read temp
    for(unsigned char i = 0; i < 16; i++)
    {
        while(!DHT_DATA);
    
        mDelay10uS(4);
        //LED_TEST = DHT_DATA;
        T = T << 1;
        if(DHT_DATA)
        {
            T = T | 1;
        }
        
        while(DHT_DATA);
    }
    
    // Read checksum
    for(unsigned char i = 0; i < 8; i++)
    {
        while(!DHT_DATA);
    
        mDelay10uS(4);
        //LED_TEST = DHT_DATA;
        chksum = chksum << 1;
        if(DHT_DATA)
        {
            chksum = chksum | 1;
        }
        
        while(DHT_DATA);
    }
          
    // Verify checksum
    unsigned char res = (RH & 0xFF) + (RH >> 8) + (T & 0xFF) + (T >> 8);
    if (res != chksum)
    {
        RH = 0xDEAD;
        T = 0xBEEF;
    }
}

// wait_for_edit_1s
void wait_and_see()
{
    for(unsigned int d = 0; d < 10; ++d)
    {
        mDelaymS(100);
        if(!BTN_2)
        {
            RTC_set_time();
            return;
        }
        if(!BTN_1)
        {
            RTC_set_date();
            return;
        }
    }
}

void main(void)
{
    // Init AT89S52 Pins
    DHT_DATA = 1;       // Enable pull-up resistor
    LED_TEST = 0;       // Test blinky init
    RTC_CE_PIN = 0;     // Disable timekeeper chip 
    RTC_SCLK_PIN = 0;   // Idle SCLK low
    RTC_DATA_PIN = 1;   // For safety
    BTN_DATA = 0xFF;    //Enable button pullups
 
    mDelaymS(10);
    VFD_reset();
    VFD_print("Howdy!");
    mDelaymS(1000);

    //set seconds
    // RTC_Write(CMD_W_SEC, 0x56);
    // //set minutes
    // RTC_Write(CMD_W_MIN, 0x34);
    // //set hours
    // RTC_Write(CMD_W_HOUR, 0x12);
    // //set days
    // RTC_Write(CMD_W_DATE, 0x11);
    // //set months
    // RTC_Write(CMD_W_MONTH, 0x11);
    // //set years
    // RTC_Write(CMD_W_YEAR, 0x11);

    while(1)
    {    
        VFD_clear();

        // READ & DISP - TEMP & HUMIDITY
        DHT_read_data();
        humidity[4]=0x00;
        humidity[3] = RH % 10 + 0x30;
        humidity[2] = '.';
        RH = RH / 10;
        humidity[1] = RH % 10 + 0x30;
        RH = RH / 10;
        humidity[0] = RH % 10 + 0x30;

        temperature[0] = '+';
        if(T & 0x8000)
            temperature[0] = '-';
        T = T & 0x7FFF;
        temperature[5]=0x00;
        temperature[4] = T % 10 + 0x30;
        temperature[3] = '.';
        T = T / 10;
        temperature[2] = T % 10 + 0x30;
        T = T / 10;
        temperature[1] = T % 10 + 0x30;

        VFD_clear();
        VFD_padding(offsetRH);
        VFD_print("Humidity: ");
        VFD_print(humidity);
        wait_and_see();
        LED_TEST = 0;

        VFD_clear();
        VFD_padding(offsetT);
        VFD_print("Temperature: ");
        VFD_print(temperature);
        wait_and_see();
        LED_TEST = 1;


        // READ & DISP - TIME & DATE
        twoDigits = RTC_Read(CMD_R_MIN);
        mDelay10uS(1);
        time[5]=0x00;
        time[4] = (twoDigits & 0x0F) + 0x30;          // Low minute digit
        time[3] = ((twoDigits >> 4) & 0x07) + 0x30;   // High minute digit 
        time[2] = ':';
        twoDigits = RTC_Read(CMD_R_HOUR);
        mDelay10uS(1);
        time[1] = (twoDigits & 0x0F) + 0x30;          // Low hour digit
        time[0] = ((twoDigits >> 4) & 0x03) + 0x30;   // High hour digit

        date[10]=0x00;
        twoDigits = RTC_Read(CMD_R_YEAR);
        mDelay10uS(1);
        date[9] = (twoDigits & 0x0F) + 0x30;    // Singles year
        date[8] = ((twoDigits >> 4)) + 0x30;    // Tens year
        date[7] = '0';
        date[6] = '2';
        date[5] = '.';
        twoDigits = RTC_Read(CMD_R_MONTH);
        mDelay10uS(1);
        date[4] = (twoDigits & 0x0F) + 0x30;    // Low month
        date[3] = ((twoDigits >> 4)) + 0x30;    // High month
        date[2] = '.';
        twoDigits = RTC_Read(CMD_R_DATE);
        mDelay10uS(1);
        date[1] = (twoDigits & 0x0F) + 0x30;    // Low date 
        date[0] = ((twoDigits >> 4)) + 0x30;    // High date

        VFD_clear();
        VFD_padding(offsetTime);
        VFD_print("Time: ");
        VFD_print(time);
        wait_and_see();
        LED_TEST = 0;

        VFD_clear();
        VFD_padding(offsetDate);
        VFD_print("Date: ");
        VFD_print(date);
        wait_and_see();
        LED_TEST = 1;


        // UPDATE OFFSETS
        offsetRH = offsetRH + dirRH;
        if (offsetRH == RH_MAX_OFFSET)
            dirRH = -1;
        if (offsetRH == 0)
            dirRH = 1;
        
        offsetT = offsetT + dirT;
        if (offsetT == T_MAX_OFFSET)
            dirT = -1;
        if (offsetT == 0)
            dirT = 1;

        offsetTime = offsetTime + dirTime;
        if (offsetTime == TIME_MAX_OFFSET)
            dirTime = -1;
        if (offsetTime == 0)
            dirTime = 1;
        
        offsetDate = offsetDate + dirDate;
        if (offsetDate == DATE_MAX_OFFSET)
            dirDate = -1;
        if (offsetDate == 0)
            dirDate = 1;
    }
    return;
}
