/* ========================================
 *
 * Servo and Stepper Motor Example system interaction library code
 *
 * ========================================
*/
/*
 * The code created for this project follow the PSoC components paradigm.
 * Example:  Instead of an init function, a "Start" function is provided.
 * The code is also making use of the Modle, View, Controller framework.  The
 * model portion of the framework is included within the Controller file.
*/

#include "project.h"
#include "stdio.h"
#include "ProjectDefs.h"
#include "StepperMotor.h"
#include "ServoDrive.h"


// Provide a way to get clutter from the screen
void ClearScreen();

// Provide a debug message buffer
char debugMsg[80];
uint8 i2cBuffer[10];
int numBytesAvailable = 0;

extern CY_ISR( StepperReset_Pin_Handler );

int main(void)
{
    // 'h' is for help within all controllers 
    // making it innocuous if there is a bug
    char command = HELP;

    CyGlobalIntEnable; /* Enable global interrupts. */

    // KimsI2C_SetBuffer(sizeof(i2cBuffer), 1, (void*) i2cBuffer);
    
    
    // Init all   
    UART_1_Start();
    PWM_1_Start();
    VDAC8_1_Start();
    Opamp_1_Start();
    StepperDrive_Start();
    ServoDrive_Start();
    
    
   
    
    // Start the interrupt handler
    SRP_StartEx(StepperReset_Pin_Handler);
    
    

    // Tell the user we are alive
    ClearScreen();
    UART_1_PutString("UART Started\r\n");
    
    
    // Start interacting with the world
    while (1)
    {
        unsigned char rxStatus;
        
        
        // This is the CLI area
        // See if the user wants to manually control the system.
        rxStatus = UART_1_ReadRxStatus();
        if (rxStatus & UART_1_RX_STS_FIFO_NOTEMPTY)
        {
            command = UART_1_GetChar();
            UART_1_PutCRLF(command);        
            
            int executionValue = StepperDrive_ExecuteCommand(command);     
            
            // See if the Stepper did the command
            if (0 == executionValue)
            {
                // Nobody has executed the command yet
                executionValue = ServoDrive_ExecuteCommand(command);
            }
            
                     
            // a non-executed command is silent, so provide 
            // feedback to the developer that the command wasn't executed
            if ( (0 == executionValue)  && (command != HELP) )
            {
                UART_1_PutString("Command NOT executed");
            }
            
            Stepper1Drive_Idle();
            Stepper2Drive_Idle();
            
        }
    }
}

// Move all the previous stuff from the UI Screen
void ClearScreen()
{
    unsigned int cntr = 0;
    
    for ( ; cntr < 80; cntr++)
    {
        UART_1_PutString("\r\n");
    }
    
    // Look in "ProjectDefs.h" to get the character for help
    UART_1_PutString("press 'h' for Help\r\n");
}

/* [] END OF FILE */
