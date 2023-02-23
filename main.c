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

// PORTS - Digital Humidity & Temp Sensor 
#define DHT_DATA P3_7

#define LED_TEST P3_6

// Display Commands
#define CMD_CLR 0x0E
#define CMD_CRET 0x0D

unsigned int RH;
unsigned char offsetRH = 0;
char dirRH = 1;
unsigned int T;
unsigned char offsetT = 0;
char dirT = 1;

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

// void RTC_Write(unsigned char address, unsigned char data)
// {
//     RTC_CE_PIN = 1;
//     address = address << 1;
//     address = address | 0x80;
//     for(unsigned char i = 0; i < 8; ++i)
//     {
//         RTC_DATA_PIN = address & 0x01;
//         mDelay10uS(1);
//         RTC_SCLK_PIN = 1;
//         mDelay10uS(1);
//         RTC_SCLK_PIN = 0;
//         address = address >> 1;
//     }
//     for(unsigned char i = 0; i < 8; ++i)
//     {
//         RTC_DATA_PIN = data & 0x01;
//         mDelay10uS(1);
//         RTC_SCLK_PIN = 1;
//         mDelay10uS(1);
//         RTC_SCLK_PIN = 0;
//         data = data >> 1;
//     }
//     RTC_CE_PIN = 0;
// }

// unsigned char RTC_Read(unsigned char address)
// {
//     unsigned char data;
//     RTC_CE_PIN = 1;
//     address = address << 1;
//     address = address | 0x81;
//     for(unsigned char i = 0; i < 8; ++i)
//     {
//         RTC_DATA_PIN = address & 0x01;
//         mDelay10uS(1);
//         RTC_SCLK_PIN = 1;
//         mDelay10uS(1);
//         RTC_SCLK_PIN = 0;
//         address = address >> 1;
//     }
//     RTC_DATA_PIN = 1;
//     for(unsigned char d = 0; d < 8; ++d)
//     {
//         data = data >> 1;
//         mDelay10uS(1);
//         RTC_SCLK_PIN = 1;
//         data = data | (((unsigned char)RTC_DATA_PIN) << 7);
//         mDelay10uS(1);
//         RTC_SCLK_PIN = 0;
//     }
//     RTC_CE_PIN = 0;
//     return data;
// }

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
    DHT_DATA = 1;       // Enable pull-up resistor

    LED_TEST = 0;
 
    //__delay_ms(10);
    mDelaymS(10);
    VFD_init();
    VFD_printf("Howdy!");
    //__delay_ms(1000);
    mDelaymS(1000);
    
    while(1)
    {
        VFD_init();
               
        DHT_read_data();

        char humidity[5];
        humidity[4]=0x00;
        humidity[3] = RH % 10 + 0x30;
        humidity[2] = '.';
        RH = RH / 10;
        humidity[1] = RH % 10 + 0x30;
        RH = RH / 10;
        humidity[0] = RH % 10 + 0x30;

        char temperature[6];
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

        VFD_init();
        VFD_padding(offsetRH);
        VFD_printf("Humidity: ");
        VFD_printf(humidity);
        //__delay_ms(1000);
        mDelaymS(1000);
        LED_TEST = 0;

        VFD_init();
        VFD_padding(offsetT);
        VFD_printf("Temperature: ");
        VFD_printf(temperature);
        // __delay_ms(1000);
        mDelaymS(1000);
        LED_TEST = 1;

        offsetRH = offsetRH + dirRH;
        if (offsetRH == 6)
            dirRH = -1;
        if (offsetRH == 0)
            dirRH = 1;
        
        offsetT = offsetT + dirT;
        if (offsetT == 2)
            dirT = -1;
        if (offsetT == 0)
            dirT = 1;
    }
    return;
}
