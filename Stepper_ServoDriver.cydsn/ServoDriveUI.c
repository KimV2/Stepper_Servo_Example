/* ========================================
 *
 * Servo Drive UI Example library code
 *
 * ========================================
*/

#include "project.h"
#include "stdio.h"
#include "ProjectDefs.h"
#include "ServoDrive.h"


// Provide s default position to start from
unsigned int pos = SERVO_START_POSITION;
 
/* ************************************************************************
* Execute commands for the Servo
*
**************************************************************************
*/
int ServoDrive_ExecuteCommand(char command)
{
    int rVal = 0;
    
    switch (command)
    {
        case HELP:  //====================================================
            UART_1_PutString("----- Servo Drive Commands ----------------" \
                "----------\r\n");
            UART_1_PutString("e - extend servo\r\n");
            UART_1_PutString("r - retract servo\r\n");
            UART_1_PutString("o - out (extend) a little\r\n");
            UART_1_PutString("i - in (retract) a little\r\n");
            rVal = CMD_NOT_EXECUTED;
        break;
    
        case EXTEND:  //====================================================
            rVal = ServoDrive_Extend();
        break;
            
        case  RETRACT:  //====================================================
           rVal = ServoDrive_Retract();
        break;
    
        case OUT:  //====================================================
            rVal = ServoDrive_Out();
        break;
     
        case IN:  //====================================================
            rVal = ServoDrive_In();
        break;

        default:  //====================================================
            rVal = CMD_NOT_EXECUTED;
        break;
    
    }
    
    return rVal;
}


/* [] END OF FILE */
