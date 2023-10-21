/*
 * File:   main.c
 * Author: Administrator
 *
 * Created on June 18, 2021, 11:21 AM
 */

#define KHz *1000UL
#define MHz *1000000UL
#define _XTAL_FREQ (4 MHz)
#include <xc.h>
#include <pic16f84a.h>

#pragma config FOSC = XT  // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT enabled)
#pragma config CP = OFF   // Flash Program Memory Code Protection bit (Code protection off)

// PORTS - Display
#define VFD_CS RA3
#define DD_VFD_CS TRISA3
#define VFD_WR RA2
#define DD_VFD_WR TRISA2
#define VFD_DATA PORTB
#define DD_VFD_DATA TRISB

// PORTS - Digital Humidity & Temp Sensor 
#define DHT_DATA RA1
#define DD_DHT_DATA TRISA1

// Display Commands
#define CMD_CLR 0x0E
#define CMD_CRET 0x0D

unsigned int RH;
unsigned char offsetRH = 0;
char dirRH = 1;
unsigned int T;
unsigned char offsetT = 0;
char dirT = 1;

void VFD_putc(char c)
{
    __delay_us(100);
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
    __delay_us(1000);
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

// Reads Humidity, Temp, Checksum from sensor
void inline DHT_read_data()
{
    // Read humidity
    for(unsigned char i = 0; i < 16; i++)
    {
        while(!DHT_DATA);
    
        __delay_us(40);
        RH = RH << 1;
        if(DHT_DATA)
        {
            RH = RH | 1;
        }
        
        while(DHT_DATA);
    }
   
    // Read temp
    for(unsigned char i = 0; i < 16; i++)
    {
        while(!DHT_DATA);
    
        __delay_us(40);
        T = T << 1;
        if(DHT_DATA)
        {
            T = T | 1;
        }
        
        while(DHT_DATA);
    }
    
    // Read checksum
    unsigned char chksum;
    for(unsigned char i = 0; i < 8; i++)
    {
        while(!DHT_DATA);
    
        __delay_us(40);
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

void inline DHT_start_signal()
{
    DD_DHT_DATA = 0;
    DHT_DATA = 0;
    __delay_ms(1);
    DD_DHT_DATA = 1;
    DHT_DATA = 1;
    __delay_us(1);
}

void main(void)
{
    DD_VFD_CS = 0;
    DD_VFD_WR = 0;
    DD_VFD_DATA = 0x00;
    DD_DHT_DATA = 1;    // Set DHT Data as input
    DHT_DATA = 1;       // Enable pull-up resistor
 
    __delay_ms(10);
    VFD_init();
    VFD_printf("Howdy!");
    __delay_ms(1000);
    
    while(1)
    {
        VFD_init();
               
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
        __delay_ms(1000);

        VFD_init();
        VFD_padding(offsetT);
        VFD_printf("Temperature: ");
        VFD_printf(temperature);
        __delay_ms(1000);
        
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
