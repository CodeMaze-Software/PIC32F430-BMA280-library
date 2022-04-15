/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include <string.h>
#include <stdio.h>

//#include "bma_280.h"
#include "bma_4xx.h"

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
#define configCPU_CLOCK_HZ     (80000000UL)            
#define us_SCALE               (configCPU_CLOCK_HZ/2000000) 

#define LED_On()               LED1_Set()
#define LED_Off()              LED1_Clear()

char tab[32];

char hello_str[] = "BMA xxx example\r\n";

/*
 * Funkcja opó?niaj?ca
 */
static inline void __attribute__((always_inline)) delay_us(uint32_t usDelay ) 
{ 
    register unsigned int startCnt = _CP0_GET_COUNT(); 
    register unsigned int waitCnt = usDelay * us_SCALE; 
 
    while( _CP0_GET_COUNT() - startCnt < waitCnt ); 
}

/*
 * Dodatkowa inicjalizacja SPI1
 */
void InitIO(void) {

    SPI1CON = 0;
    SPI1BUF;
    SPI1CONbits.CKP = 1;
    SPI1CONbits.MSTEN = 1;
    SPI1CONbits.MODE16 = 1;
    SPI1BRG = 80; 
    SPI1CONbits.ON = 1; 
    SPI1STATbits.SPIROV = 0; 
}


int main ( void )
{
    /* Inicjalizacja modulów */
    SYS_Initialize ( NULL );
    
    /*Inicjalizacja SPI*/
    InitIO();
    
    //bma4xx_init(0,0,0);
 
    UART1_Write(hello_str, strlen(hello_str)); 

    memset(tab, 0 ,sizeof(tab));
    
    
    while ( true )
    {
 
        
        /*
         * Pomocnicza funkcja delay
         */
        delay_us(1000000);
        
        UART1_Write((char*)"Loop", strlen("Loop"));
            
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

