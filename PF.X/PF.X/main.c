/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F46K40
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include<stdio.h>
#include "ESTADO.h"
/*
                         Main application
 */
char INTEPT=0;
int pp=0;
bool tengo_dato_serial;
char ok;
int CC=0;
int select=1;
char bloque[2];
void SPI_W(unsigned int datos);
unsigned int convertedValue;
void fin_adc();
int adc12bits;
void ready_fun();
int datos;
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    //ADPCH=channel_ANB0;
    SPI1_Open(SPI1_DEFAULT);
    RB4=1;
    RE0=1;
//    adc12bits=convertedValue<<2;
//    datos=0x1000|adc12bits;
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    ADPCH=channel_ANA0;

    TMR2_Start();
    ADCC_SetADIInterruptHandler(fin_adc);
    recepcion rece;
//    EUSART1_Receive_ISR(ready_fun);
    inicializarRecepcion(&rece);
  
    while (1)
    {
        //ok=tengocambiodefdM(&rece);
        if(EUSART1_is_rx_ready()){
            PalabraRecepcion(EUSART1_Read(),&rece);
            //tengo_dato_serial=0;
        }
        if (tengocambiodefdM(&rece)){
            // no se como sea su lOgica del contador si estA mal un cambio de este estilo la puede daniar. 
            select=retorneNumero(&rece);
        }
        if(INTEPT){
            INTEPT=0;
            CC++;
        }
        if(CC>=select){
            CC=0;
            //printf("\n");
            SPI_W(convertedValue);
            //printf("%d",convertedValue);
            EUSART1_Write(convertedValue>>8);
            EUSART1_Write(convertedValue &0x00FF);
        }
    } 
}
void fin_adc(){
    ADPCH=channel_ANA0;
    convertedValue=(adc_result_t)((ADRESH << 8) + ADRESL);
    PIR4bits.TMR2IF=0;
    INTEPT=1;
    PIR1bits.ADIF=0;
}
void SPI_W(unsigned int convertedValue){
//    int kk=0x10;
//    int xd=(kk)|((datos>>6)&(0x000F));
//    bloque[1]=((datos<<2)&(0x00FC));
//    bloque[0]=xd;
    int adc12bits=convertedValue<<2;
    int data= 0b0001000000000000|adc12bits;
    //data=0x0CFFF;
    bloque[1]=(char)(0x00FF&data);
    bloque[0]=(char)(0x00FF&(data>>8));
    RE0=0;
    SPI1_WriteBlock(&bloque[0],2);
    RE0=1;
    RB4=0;
    RB4=1;
}
void ready_fun(){
    tengo_dato_serial=true;
}

/**
 End of File
*/