/* ========================================
 *
 * Stepper Motor UI Example library code
 *
 * ========================================
*/

#include "project.h"
#include "limits.h"
#include "stdio.h"
#include "ProjectDefs.h"
#include "StepperMotor.h"

// The magnetic field will be set to the maximum speed.
int delay = 2;    // 2ms of delay to get the magnetic field established

// Stepper direction -1 - don't move, 0 and 1 are directions.
int direction = -1;

// Keep track of the number of rotations for position movement capabilities
int rotations_1 = 0;
int rotations_2 = 0;

// Don't let the developer use the command executor independently
// Execute commands for the specific stepper, provided to allow better
// modularity
static int Stepper1_ExecutedCommand(char command);
static int Stepper2_ExecutedCommand(char command);

/* ************************************************************************
* Let the command go to one or both of the Executors
* Set the steppers home position to the current position
*
**************************************************************************
*/
int StepperDrive_ExecuteCommand(char command)
{
    int rVal = Stepper1_ExecutedCommand(command);
   
    if (0 == rVal)
    {
        // Stepper1 didn't execut the command. Let stepper 2 try.
        rVal = Stepper2_ExecutedCommand(command);
    }
    
    return rVal;
}
  
/** ************************************************************************
* Modularity support for Stepper 1 Executor
*
****************************************************************************
*/
int Stepper1_ExecutedCommand(char command)
{
    int rVal = INT_MIN;


    switch (command)
    {
        case HELP:  //=======================================
            UART_1_PutString("----- Stepper 1 Commands -------------" \
                "-------------\r\n");
            UART_1_PutString("s - Stop\r\n");
            UART_1_PutString("= - move right  10 steps\r\n");
            UART_1_PutString("- - move left   10 steps\r\n");
            UART_1_PutString("2 - move right   2 steps\r\n");
            UART_1_PutString("1 - move left    2 steps\r\n");
            UART_1_PutString("9 - move right 100 steps\r\n");
            UART_1_PutString("8 - move left  100 steps\r\n");
            UART_1_PutString("b - move to Position_1\r\n");
            UART_1_PutString("n - move to Position_2\r\n");
            UART_1_PutString("m - move to Position_3\r\n");
            UART_1_PutString(", - move to Position_4\r\n");
            UART_1_PutString(". - move to Position_5\r\n");
            UART_1_PutString("/ - move to Position_6\r\n");
            UART_1_PutString("] - reset rotations to 0\r\n");
            UART_1_PutString("\r\n");
            rVal = CMD_NOT_EXECUTED;
        break;
        
        case STOP:  //====================================================
    
            Stepper1Drive_Idle();
            direction = -1;
            rVal ++;
        break;
            
        case RIGHT10:  //====================================================
        {
            int loop = 10;
            do
            {
                Stepper1Drive_CounterClockwise();
                loop--;
            }
            while(loop);
            rVal ++;
        }
        break;
        
        case  LEFT10:  //====================================================
        {
            int loop = 10;
            do
            {
                Stepper1Drive_Clockwise();
                loop--;
            }
            while(loop);
            rVal ++;
        }
        break;
        
        case RIGHT2:  //====================================================
        {
            int loop = 2;
            do
            {
                Stepper1Drive_CounterClockwise();
                loop--;
            }
            while(loop);
            rVal ++;
        }
        break;
        
        case LEFT2:  //====================================================
        {
            int loop = 2;
            do
            {
                Stepper1Drive_Clockwise();
                loop--;
            }
            while(loop);
            rVal ++;
        }
        break;
        
        case RIGHT100:  //====================================================
        {
            int loop = 100;
            do
            {
                Stepper1Drive_CounterClockwise();
                loop--;
            }
            while(loop);
            rVal ++;
        }
        break;
        
        case LEFT100:  //====================================================
        {
            int loop = 100;
            do
            {
                Stepper1Drive_Clockwise();
                loop--;
            }
            while(loop);
            rVal ++;
        }
        break;
        
        case POS_0:  //====================================================
            Stepper1Drive_To(POSITION_0);
            rVal ++;
        break;
        
        case POS_1:  //====================================================
            Stepper1Drive_To(POSITION_1);
            rVal ++;
        break;
        
        case POS_2:  //====================================================
            Stepper1Drive_To(POSITION_2);
            rVal ++;
        break;
            
        case POS_3:  //====================================================
            Stepper1Drive_To(POSITION_3);
            rVal ++;
        break;
        
        case POS_4:  //====================================================
            Stepper1Drive_To(POSITION_4);
            rVal ++;
        break;
        
        case POS_5:  //====================================================
            Stepper1Drive_To(POSITION_5);
            rVal ++;
        break;

        case POS_6:  //====================================================
            Stepper1Drive_To(POSITION_6);
            rVal ++;
        break;
        
        case STEPPER_RESET:  //====================================================
           rotations_1 = 0;
           rVal ++;
        break;
        
        default:  //====================================================
            direction = -1;
            rVal = CMD_NOT_EXECUTED;
        break;
    }
    return rVal;
}

/** ************************************************************************
*  Modularity support for Stepper 1 Executor
*
****************************************************************************
*/
int Stepper2_ExecutedCommand(char command)
{
    int rVal = INT_MIN;


    switch (command)
    {
        case HELP:
    
            UART_1_PutString("----- Stepper2 Commands ---------------------" \
                "------\r\n");
            UART_1_PutString("g - rotate the stepper CCW for 10 steps\r\n");
            UART_1_PutString("f - rotate the stepper CW  for 10 steps\r\n"); 
            UART_1_PutString("z - rotate the stepper CW  for a fixed number of steps\r\n"); 
            UART_1_PutString("x - rotate the stepper CCW for a fixed number of steps\r\n"); 
            UART_1_PutString("\r\n"); 
            rVal = CMD_NOT_EXECUTED;
        break;
        
        case ROTATE_CCW10:  //======================================= 
        {
            int loop = 10;
            do
            {
                Stepper2Drive_CounterClockwise();
                loop--;
            }
            while(loop);
            rVal ++;
        }
        break;
    
        case ROTATE_CW10:  //======================================= 
        {
            int loop = 10;
            do
            {
                Stepper2Drive_Clockwise();
                loop--;
            }
            while(loop);
            rVal ++;
        }
        break;
        
        case ROTATE_CW_FN:  //======================================= 
        {
            int loop = SMALL_MOVEMENT;
            do
            {
                Stepper2Drive_Clockwise();
                loop--;
            }
            while(loop);
            rVal ++;
        }
        break;
        
        case ROTATE_CCW_FN:  //======================================= 
        {
            int loop = SMALL_MOVEMENT;
            do
            {
                Stepper2Drive_CounterClockwise();
                loop--;
            }
            while(loop);
            rVal ++;
        }
        break;
        
        case NUM_ROTATIONS:  //======================================= 
            sprintf(debugMsg, "%d\r\n", rotations_2);
            UART_1_PutString(debugMsg);
        break;
            
        default:  //======================================= 
            rVal = CMD_NOT_EXECUTED;
        break;
    }
    
    Stepper2Drive_Idle();
    return rVal;
}


/** *************************************************************************
*  Set the home position for Stepper 1 to where it is currently positioned
*
****************************************************************************
*/
void Stepper_1_DriveReset()
{
    rotations_1 = 0;
}


/* [] END OF FILE */
