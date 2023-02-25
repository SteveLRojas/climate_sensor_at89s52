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

// // Data Display Relation
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

void mDelaymS(unsigned int n)                              // Delay in mS
{
    while ( n )
    {
        //mDelayuS( 1000 );
        mDelay10uS(100);
        -- n;
    }
}

void VFD_putc(char c)
{
    //__delay_us(100);
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
    //__delay_us(1000);
    mDelay10uS(100);
}

void VFD_printf(char* str)
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

void inline VFD_init()
{
    VFD_putcmd(CMD_CRET);
    VFD_putcmd(CMD_CLR);
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
        RTC_DATA_PIN = address & 0x01;
        mDelay10uS(1);
        RTC_SCLK_PIN = 1;
        mDelay10uS(1);
        RTC_SCLK_PIN = 0;
        address = address >> 1;
    }
    RTC_DATA_PIN = 1;
    for(unsigned char d = 0; d < 8; ++d)
    {
        data = data >> 1;
        mDelay10uS(1);
        RTC_SCLK_PIN = 1;
        data = data | (((unsigned char)RTC_DATA_PIN) << 7);
        mDelay10uS(1);
        RTC_SCLK_PIN = 0;
    }
    RTC_CE_PIN = 0;
    return data;
}

void inline DHT_start_signal()
{
    DHT_DATA = 0;
    //__delay_ms(1);
    mDelay10uS(100);
    //DD_DHT_DATA = 1;
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
    
        //__delay_us(40);
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
    
        //__delay_us(40);
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
    
        //__delay_us(40);
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

void main(void)
{
    // Init AT89S52 Pins
    DHT_DATA = 1;       // Enable pull-up resistor
    LED_TEST = 0;       // Test blinky init
    RTC_CE_PIN = 0;     // Disable timekeeper chip 
    RTC_SCLK_PIN = 0;   // Idle SCLK low
    RTC_DATA_PIN = 1;   // For safety
 
    //__delay_ms(10);
    mDelaymS(10);
    VFD_init();
    VFD_printf("Howdy!");
    //__delay_ms(1000);
    mDelaymS(1000);

    //set seconds
    RTC_Write(CMD_W_SEC, 0x56);
    //set minutes
    RTC_Write(CMD_W_MIN, 0x34);
    //set hours
    RTC_Write(CMD_W_HOUR, 0x12);
    //set days
    RTC_Write(CMD_W_DATE, 0x11);
    //set months
    RTC_Write(CMD_W_MONTH, 0x11);
    //set years
    RTC_Write(CMD_W_YEAR, 0x11);

    while(1)
    {    
        VFD_init();

        // READ & DISP - TEMP & HUMIDITY
        // DHT_read_data();
        // humidity[4]=0x00;
        // humidity[3] = RH % 10 + 0x30;
        // humidity[2] = '.';
        // RH = RH / 10;
        // humidity[1] = RH % 10 + 0x30;
        // RH = RH / 10;
        // humidity[0] = RH % 10 + 0x30;

        // temperature[0] = '+';
        // if(T & 0x8000)
        //     temperature[0] = '-';
        // T = T & 0x7FFF;
        // temperature[5]=0x00;
        // temperature[4] = T % 10 + 0x30;
        // temperature[3] = '.';
        // T = T / 10;
        // temperature[2] = T % 10 + 0x30;
        // T = T / 10;
        // temperature[1] = T % 10 + 0x30;

        // VFD_init();
        // VFD_padding(offsetRH);
        // VFD_printf("Humidity: ");
        // VFD_printf(humidity);
        // //__delay_ms(1000);
        // mDelaymS(1000);
        // LED_TEST = 0;

        // VFD_init();
        // VFD_padding(offsetT);
        // VFD_printf("Temperature: ");
        // VFD_printf(temperature);
        // // __delay_ms(1000);
        // mDelaymS(1000);
        // LED_TEST = 1;


        // READ & DISP - TIME & DATE
        twoDigits = RTC_Read(CMD_R_MIN);
        mDelay10uS(1);
        //P2 = RTC_Read(CMD_R_MIN);
        time[5]=0x00;
        time[4] = (twoDigits & 0x0F) + 0x30;          // Low minute digit
        time[3] = ((twoDigits >> 4) & 0x07) + 0x30;   // High minute digit 
        time[2] = ':';
        twoDigits = RTC_Read(CMD_R_HOUR);
        mDelay10uS(1);
        //P2 = RTC_Read(CMD_R_SEC);
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

        VFD_init();
        VFD_padding(offsetTime);
        VFD_printf("Time: ");
        VFD_printf(time);
        //__delay_ms(1000);
        mDelaymS(1000);
        LED_TEST = 0;

        VFD_init();
        VFD_padding(offsetDate);
        VFD_printf("Date: ");
        VFD_printf(date);
        // __delay_ms(1000);
        mDelaymS(1000);
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
