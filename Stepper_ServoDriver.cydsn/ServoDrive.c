/* ========================================
 *
 * Servo Drive Example library code
 *
 * ========================================
*/

#include "project.h"
#include "stdio.h"
#include "ProjectDefs.h"
#include "ServoDrive.h"


/* ****************************************************************************
 * Set the servo to a known starting position
 *
******************************************************************************
*/
void ServoDrive_Start()
{
   PWM_1_WriteCompare(SERVO_START_POSITION);
}
    
/* ****************************************************************************
 * Move the servo to a known position
 *
******************************************************************************
*/
int ServoDrive_Extend()
{
    pos = SERVO_FIXED_EXTENSION_POINT;
    PWM_1_WriteCompare(pos);
    
#if DEBUG_LEVEL & 0x8000    
    sprintf(debugMsg, "%d\r\n", pos);
    UART_1_PutString(debugMsg);
#endif    
    return EXTEND;
}
    
/* ****************************************************************************
 *
 *  Move the servo to a known position
 *
******************************************************************************
*/
int ServoDrive_Retract()
{
    pos = SERVO_FIXED_RETRACTION_POINT;
    PWM_1_WriteCompare(pos);
    
#if DEBUG_LEVEL & 0x8000    
    sprintf(debugMsg, "%d\r\n", pos);
    UART_1_PutString(debugMsg); 
#endif 
    return RETRACT;
}

/* ****************************************************************************
 * Move the servo in small increments 
 *
******************************************************************************
*/
int ServoDrive_Out()
{
    pos += SERVO_FIXED_SMALL_MOVEMENT_VALUE;
    PWM_1_WriteCompare(pos);
    
#if DEBUG_LEVEL & 0x8000 
    sprintf(debugMsg, "%d\r\n", pos);              
    UART_1_PutString(debugMsg);
#endif 

    return OUT;
}

/* ****************************************************************************
 *  Move the servo in small increments 
 *
******************************************************************************
*/
int ServoDrive_In()
{
    pos -= SERVO_FIXED_SMALL_MOVEMENT_VALUE;
    PWM_1_WriteCompare(pos);
    
#if DEBUG_LEVEL & 0x8000     
    sprintf(debugMsg, "%d\r\n", pos);
    UART_1_PutString(debugMsg);
#endif 

    return IN;
}


/* [] END OF FILE */
