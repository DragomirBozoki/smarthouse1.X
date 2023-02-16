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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC18F87K22
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
/*
                         Main application
 */

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
void obrada_zahteva();
void static unlockcompareFingerprints();
void static regFingerprints();
void static menu();
void static fingerprintOptions();
void static checknoFingerprints();
void static deleteFingerprint();

void obrada_zahreva(void)
{               
        
    uint8_t c;
    c = EUSART1_Read();  
        switch(c)
        {
            case '1':
                unlockcompareFingerprints();
                break;
            
            default:
                printf("Invalid input! \n");
                break;
        }
}
void unlockcompareFingerprints(void)
{
    char s2;
    static bool flag = 0;
    
    printf("===CompareFingerprint====\n");
    strcpy(&s2,"<C>UnlockCompareFp</C>"); 
                
    char i;
    int len = strlen(&s2);             
    for (i = 0; i < len; i++)
    {
        EUSART1_Write(i);     
    }
    if(EUSART2_is_rx_ready())
    {
        s2 = EUSART2_Read();
        EUSART1_Write(s2);
        
        if(s2 != "<R>FAIL</R>")
        {   
            printf("Welcome! \n");
            EUSART1_Write(s2);
            flag = 1;
        }
    
    
        if(flag == 1)
        {
            menu();
        }
        else
        {
            printf("Fingerprints did not match!\n");
        }
    }    
}
    
void regFingerprints()
{
    char s2;
    printf("===Register Fingerprint====\n");
    strcpy(&s2,"<C>RegisterFingerprint</C>"); 
                
    char i;
    int len = strlen(&s2);             
    for (i = 0; i < len; i++)
    {
        EUSART1_Write(i);     
    }
    if(EUSART2_is_rx_ready())
    {
        s2 = EUSART2_Read();
        EUSART1_Write(s2);
    }

}

void fingerpritnsOptions()
{   
    
    printf("1. Register new Fingerprint \n");
    printf("2. Check Number of Registered Fingerprints \n");
    printf("3. Delete fingerprint \n");
    printf("Enter number: \n");
    while(!EUSART1_is_rx_ready());
        
    uint8_t c;
    c = EUSART1_Read();  
        switch(c)
        {
            case '1':
                unlockcompareFingerprints();
                break;
            
            case '2':
                checknoFingerprints();
                break;
                
            case '3':
                deleteFingerprint();
                break;
                
            default:
                printf("Invalid input! \n");
                break;
        }

}

void menu()
{
    uint8_t c;
    printf("1. Turn Alarm ON \n");
    printf("2. Turn Alarm OFF \n");
    printf("3. Fingerprints Options \n");
    printf("Enter number: \n");
    while(!EUSART1_is_rx_ready())
            
    if(EUSART1_is_rx_ready())
    {        
        c = EUSART1_Read();  
        switch(c)
        {
            case '1':
                printf("Turn Alarm ON...\n");
                break;
            
            case '2':
                printf("Turn Alarm OFF... \n");
                break;
            case '3':
                fingerprintOptions();
                break;
        }
    }
    
    
}

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    //Disable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptDisable();
    /**
    cekaj na zahtev
    ako zahtev - stanje = parsiraj zahtev
    u suprotnom cekaj
    ako zahtev dobar - ocitaj senzor
    ako zahtev nije dobar predhodni korak
    ocitan senzor - interpetiraj rezultate
    ako ocitavanje ne uspe jos jednom
    ako nije dobra interpetacija ponovo procitaj podatak
    ako je dobar posalji odgovor 
    ako je uspeo da posaje 
    */ 
    
    // napraviti stanja i switch case momente 
    // kad primim nesto na uart promeni stanje
    // SWITCH CASE STANJE
    
    
    bool flag = 1;
    char s;
    // EUSART2 WRITE IF EUSART 1 READ    
    while (1)
    {   
        
        printf("1. Compare Fingerprints\n");
        printf("2. Turn Off\n");
        printf("Input number: \n"); 
        while(!EUSART1_is_rx_ready())
            
        if(EUSART1_is_rx_ready())
        {        
            obrada_zahteva();
        }
    }
}
/**
 End of File
*/
