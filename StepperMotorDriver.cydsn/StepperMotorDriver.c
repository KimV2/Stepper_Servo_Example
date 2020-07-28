/* ========================================
 *
 * Stepper Motor Driver Example library code
 *
 * ========================================
*/

#include "project.h"
#include "stdio.h"
#include "ProjectDefs.h"
#include "StepperMotor.h"


// Combination Stepper Function Definitions

/* ****************************************************************************
 * StepperDrive_Start
 * Set the Steppers to no power consumed 
 *
******************************************************************************
*/
void StepperDrive_Start()
{
    Stepper1Drive_Idle();
    Stepper2Drive_Idle();
}


// ////////////////////////////////////////////////////////////////////////////
//
// STEPPER 1 definitions
//
// ////////////////////////////////////////////////////////////////////////////

/* ****************************************************************************
 *  StepperReset_Pin_Handler
 *  Handle the interrupt from the hardware.
 *
 *  Set stepper 1 home location to the current position
 *  
******************************************************************************
*/
CY_ISR( StepperReset_Pin_Handler )
{
#if DEBUG_LEVEL & 0x8000     
    UART_1_PutString("Interrupt Hit\r\n");
#endif

    rotations_1 = 0;
    StepperReset_Pin_ClearInterrupt();
}

/* ****************************************************************************
 *   Stepper1Drive_To
 *   Move Stepper 1 to a specific position from 0 to N.
 *   N is based on the design.
 *   Out of bounds positions are NOT checked
******************************************************************************
*/
void Stepper1Drive_To(int position)
{
    // Determine if we are before or past the actual position that is wanted.
    if (rotations_1 >= position)
    {
        // We are past
        while (rotations_1 >= position)
        {
            Stepper1Drive_CounterClockwise();
        } 
    }
    else
    {
        // We are before
        while (rotations_1 <= position)
        {
            Stepper1Drive_Clockwise();
        } 
    }
}
/* ****************************************************************************
 *  Stepper1Drive_Idle
 *  Remove all power from stepper motor
******************************************************************************
*/
void Stepper1Drive_Idle()
{
    A_Write(0);
    B_Write(0);
    C_Write(0);
    D_Write(0);
}


/* ****************************************************************************
 *  Stepper1Drive_CounterClockwise
 *  Move the stepper one (1) step CCW
******************************************************************************
*/
void Stepper1Drive_CounterClockwise()
{
    rotations_1--;
#if DEBUG_LEVEL & 0x8000     
    sprintf(debugMsg, "Rotations %d\r\n", rotations_1);
    UART_1_PutString(debugMsg);
#endif

    A_Write(HIGH);
    B_Write(LOW);
    C_Write(HIGH);
    D_Write(LOW);
    CyDelay(delay);


    A_Write(HIGH);
    B_Write(LOW);
    C_Write(LOW);
    D_Write(HIGH);
    CyDelay(delay);

    A_Write(LOW);
    B_Write(HIGH);
    C_Write(LOW);
    D_Write(HIGH);
    CyDelay(delay);

    A_Write(LOW);
    B_Write(HIGH);
    C_Write(HIGH);
    D_Write(LOW);
    CyDelay(delay);
   
}

/* ****************************************************************************
 *  Stepper1Drive_Clockwise
 *  Move the stepper one (1) step CW
******************************************************************************
*/
void Stepper1Drive_Clockwise()
{
    rotations_1++;
#if DEBUG_LEVEL & 0x8000     
    sprintf(debugMsg, "Rotations %d\r\n", rotations_1);
    UART_1_PutString(debugMsg);
#endif

    A_Write(LOW);
    B_Write(HIGH);
    C_Write(HIGH);
    D_Write(LOW);
    CyDelay(delay);

    A_Write(LOW);
    B_Write(HIGH);
    C_Write(LOW);
    D_Write(HIGH);
    CyDelay(delay);

    A_Write(HIGH);
    B_Write(LOW);
    C_Write(LOW);
    D_Write(HIGH);
    CyDelay(delay);

    A_Write(HIGH);
    B_Write(LOW);
    C_Write(HIGH);
    D_Write(LOW);
    CyDelay(delay);
}


//#############################################################################
// ////////////////////////////////////////////////////////////////////////////
//
// STEPPER 2 definitions
//
// ////////////////////////////////////////////////////////////////////////////
//#############################################################################

/* ****************************************************************************
 *  Stepper2Drive_Idle
 *  Set the stepper so no power is consumed
******************************************************************************
*/
void Stepper2Drive_Idle()
{
    A_1_Write(0);
    B_1_Write(0);
    C_1_Write(0);
    D_1_Write(0);
}

/* ****************************************************************************
 *  Stepper2Drive_CounterClockwise
 *  Move the stepper one (1) step CCW
******************************************************************************
*/
void Stepper2Drive_CounterClockwise()
{
    rotations_2--;
#if DEBUG_LEVEL & 0x8000 
    sprintf(debugMsg, "Rotations %d\r\n", rotations_2);
    UART_1_PutString(debugMsg);
#endif

    A_1_Write(HIGH);
    B_1_Write(LOW);
    C_1_Write(HIGH);
    D_1_Write(LOW);
    CyDelay(delay);


    A_1_Write(HIGH);
    B_1_Write(LOW);
    C_1_Write(LOW);
    D_1_Write(HIGH);
    CyDelay(delay);

    A_1_Write(LOW);
    B_1_Write(HIGH);
    C_1_Write(LOW);
    D_1_Write(HIGH);
    CyDelay(delay);

    A_1_Write(LOW);
    B_1_Write(HIGH);
    C_1_Write(HIGH);
    D_1_Write(LOW);
    CyDelay(delay);
    
}





/* ****************************************************************************
 *  Stepper2Drive_Clockwise
 *  Move the stepper one (1) step CW
******************************************************************************
*/
void Stepper2Drive_Clockwise()
{
    rotations_2++;
#if DEBUG_LEVEL & 0x8000     
    sprintf(debugMsg, "Rotations %d\r\n", rotations_2);
    UART_1_PutString(debugMsg);
#endif

    A_1_Write(LOW);
    B_1_Write(HIGH);
    C_1_Write(HIGH);
    D_1_Write(LOW);
    CyDelay(delay);

    A_1_Write(LOW);
    B_1_Write(HIGH);
    C_1_Write(LOW);
    D_1_Write(HIGH);
    CyDelay(delay);

    A_1_Write(HIGH);
    B_1_Write(LOW);
    C_1_Write(LOW);
    D_1_Write(HIGH);
    CyDelay(delay);

    A_1_Write(HIGH);
    B_1_Write(LOW);
    C_1_Write(HIGH);
    D_1_Write(LOW);
    CyDelay(delay);
}



/* [] END OF FILE */
