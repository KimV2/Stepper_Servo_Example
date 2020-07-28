/* ========================================
 *
 * Servo Drive Example library code
 *
 * ========================================
*/

/*
 * The purpose of this file is to provide the interface to a Servo motor 
 * within this project.  
 *
 * The file set for the servo uses the 
 * Modle, View, Controller framework:
 * The model is the .h file.
 * The view is the  "UI" file.
 * The controller is the "Drive" file.

 * The servo motor uses PWM to control the comparitor of the servo motor and
 * the repition timing of the pulses to provide a smooth transition from one
 * position to another.  This design makes use of limits for both ends of the
 * servo to provide an example of end to end but also absolute positioning.
 */
#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

    /// Global Interface requirements
    extern char debugMsg[80];     // debugging requires a global defined buffer

    /**
     * \brief SERVO_COMMAND_SET
     *
     * At the command line any one of these characters do what is indicated
     * HELP is defined at the System Level
     *
    */
    enum SERVO_COMMAND_SET
    {
        EXTEND  = 'e',  ///< moves the servo one way - defined as extends
        RETRACT = 'r',  ///< moves the servo the other way - defined as retracts
        OUT     = 'o',  ///< moves the servo small increments one way - (extends)
        IN      = 'i'   ///< moves the servo small increments one way - (retracts)
    };
    
    /** ************************************************************************ 
     * \brief ServoDrive_Start
     * Set the servo to minimum value (retracted for this project)
     *
     **************************************************************************
    */
    void ServoDrive_Start();

    /** ************************************************************************ 
     * \brief  ServoDrive_ExecuteCommand
     * Executes commands for the servo
     *
     * Positive values indicate the command was successfully executed.
     * A negative value indicates the command was not executed successfully.
     * Zero indicates no matching command structure was found - nothing executed
     * The value provides additional information for debug and normal execution.
     *
     * The value provided for getting help (h) is a special case.  Help provides
     * zero (0).  This allows all command structures to provide help to the user
     * for multi-control systems.
     **************************************************************************
    */
    int ServoDrive_ExecuteCommand(char command);

    
    
    
    /** ************************************************************************
     *  \brief ServoDrive_Extend
     * Control the servo to extend to a predetermined spot
     *
     * The predetermined spot can be a particular spot in the rotation or used
     * as an end stop to not have the servo bind
     **************************************************************************
    */
    int ServoDrive_Extend();

    /** ************************************************************************
     *  \brief ServoDrive_Retract
     * Control the servo to extend to a predetermined spot
     *
     * The predetermined spot can be a particular spot in the rotation or used
     * as an end stop to not have the servo bind
     **************************************************************************
    */
    int ServoDrive_Retract();

    /** ************************************************************************
     *  \brief ServoDrive_Out
     *  Control the servo to move out a fixed amount of PWM
     *
     * The value of the fixed amount is defined by:
     * SERVO_FIXED_SMALL_MOVEMENT_VALUE.
     * There is no check against endstop values .
     **************************************************************************
    */
    int ServoDrive_Out();

    /** ************************************************************************
     *  \brief ServoDrive_In
     *  Control the servo to move out a fixed amount of PWM
     *
     * The value of the fixed amount is defined by:
     * SERVO_FIXED_SMALL_MOVEMENT_VALUE.
     * There is no check against endstop values .
     **************************************************************************
    */
    int ServoDrive_In();
   
        
    
    // Internal Servo Drive Requirements
    extern unsigned int pos; ///< Position of the servo 1000 - 2000 min/max

    /// This happens to be an endpoint but is NOT required to be
    #define SERVO_START_POSITION             (1000) ///< Just a number
    
    /// This happens to be half rotation of the servo, but doesn't have to be
    #define SERVO_FIXED_EXTENSION_POINT      (1500) ///< Just a number
    
    #define SERVO_FIXED_RETRACTION_POINT     (1000)  ///< Just a number
    #define SERVO_FIXED_SMALL_MOVEMENT_VALUE (50)    ///< Just a number
        

#endif

/* [] END OF FILE */
