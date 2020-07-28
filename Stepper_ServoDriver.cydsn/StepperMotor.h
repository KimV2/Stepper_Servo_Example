/* ========================================
 *
 * Stepper Motor Example library code
 *
 * ========================================
*/

/* Purpose of this file is to provide the interface to the stepper motors 
 * within this project.  At this time, I'm not sure how to use C++ or 
 * function pointers for the defined pins; therefore, brut force was used
 * to control the two stepper motors independently.
 *
 * The file set for the servo uses the 
 * Modle, View, Controller framework:
 * The model is the .h file.
 * The view is the  "UI" file.
 * The controller is the "Drive" file.

 * The stepper motors use GPIO to control the magnetic field required to
 * turn the stepper.  The timing is based on the minimum magnetic field
 * required for a typical stepper and the progression of the fields to turn
 * the motor.
*/
#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

    /// Global Interface requirements
    extern char debugMsg[80];     // debugging requires a global defined buffer

    
    

    
    /**
     * \brief STEPPERMOTOR_COMMAND_SET
     *
     * At the command line any one of these characters do what is indicated
     * HELP is defined at the System Level
     *
    */
    enum STEPPERMOTOR_COMMAND_SET
    {
        // For Stepper 1
        STOP     = 's',  ///< Stops stepper 1;
        RIGHT10  = '=',  ///< move right  10 steps
        LEFT10   = '-',  ///< move left   10 steps
        RIGHT2   = '2',  ///< move right   2 steps
        LEFT2    = '1',  ///< move left    2 steps
        RIGHT100 = '9',  ///< move right 100 steps
        LEFT100  = '8',  ///< move left  100 steps
        POS_0    = 'V',  ///< move to Position_0
        POS_1    = '/',  ///< move to Position_1
        POS_2    = '.',  ///< move to Position_2
        POS_3    = ',',  ///< move to Position_3
        POS_4    = 'm',  ///< move to Position_4
        POS_5    = 'n',  ///< move to Position_5
        POS_6    = 'b',  ///< move to Position_6
        STEPPER_RESET    = ']',  ///<reset rotations to 0
        
        // For Stepper 2
        ROTATE_CCW10     = 'g',  ///< rotate the stepper CCW for 10 steps
        ROTATE_CW10      = 'f',  ///< rotate the stepper CW  for 10 steps
        ROTATE_CW_FN     = 'z',  ///< rotate CW  for a fixed number of steps
        ROTATE_CCW_FN    = 'x',  ///< rotate CCW for a fixed number of steps
        NUM_ROTATIONS    = '6',  ///< Print the number of rotations - Stepper 2
    };
        
    
    
    /** ************************************************************************ 
     * \brief  StepperDrive_Start
     * Set ALL steppers to Idle
     *
     * The code created for this project follow the PSoC components paradigm.
     * Example:  Instead of an init function, a "Start" function is provided.
     * The code is also making use of the Modle, View, Controller framework.  The
     * model portion of the framework is included within the Controller file.
     **************************************************************************
    */
    void StepperDrive_Start();

    /** ************************************************************************ 
     * \brief  StepperDrive_ExecuteCommand
     * Executes commands for both stepper 1 and stepper 2
     *
     * Return Value:
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
    int StepperDrive_ExecuteCommand(char command);

    /** ************************************************************************
     *  \brief StepperReset_Pin_Handler
     *  Interrupt handler for reseting the home position of stepper 1.
     *
     *  The interrupt is based on a limit switch or some hardware stop.  Which
     *  controls the safety of the system.
     **************************************************************************
    */
    void StepperReset_Pin_Handler( );
    
    /** ************************************************************************
     *  \brief Stepper1Drive_Idle
     *  Remove all power from stepper motor
     *
     *  Set the stepper to have no magnetic fields entergized. 
     **************************************************************************
    */
    void Stepper1Drive_Idle();
    void Stepper2Drive_Idle();

    /** ************************************************************************
     *  \brief Stepper1Drive_CounterClockwise
     *  Move the stepper one (1) step Counter Clock Wise (CCW)
     * 
     *  Control the rotation of the stepper.
     **************************************************************************
    */
    void Stepper1Drive_CounterClockwise();
    void Stepper2Drive_CounterClockwise();

     /** ************************************************************************
     *  \brief Stepper1Drive_Clockwise
     *  Move the stepper one (1) step Clock Wise (CW)
     * 
     *  Control the rotation of the stepper.
     **************************************************************************
    */
    void Stepper1Drive_Clockwise();
    void Stepper2Drive_Clockwise();

    /** ************************************************************************
     *  \brief Stepper1Drive_To
     *  Drive the stepper to a position.
     *
     * Move the stepper to a particular position between 0 and an absolute 
     * number.
     * The absolute number is defined by the particular system the stepper is
     * connected to.
     
     * No error checking for overdriving the stepper passt the systems 
     * abilities.
     **************************************************************************
    */
    void Stepper1Drive_To(int count);
    void Stepper2Drive_To(int count);
    
    
    
    
    /** ************************************************************************
     *  \brief Stepper_1_DriveReset
     *  Set the steppers home position to the current position
     *
     **************************************************************************
    */
    void Stepper_1_DriveReset();
    
    
    
    // Internal Stepper motor requirements
    extern int delay;      ///< Set the magnetic field operating time
    extern int direction;  ///< Stepper direction -1 - don't move, 0-CCW 1-CW
    extern int rotations_1;///< num of rotations for position movement abilities
    extern int rotations_2;///< num of rotations for position movement abilities
    
    // Predefined positions - dependent on system needs
    #define POSITION_0 (0)   
    #define POSITION_1 (180)
    #define POSITION_2 (292)
    #define POSITION_3 (422)
    #define POSITION_4 (542)
    #define POSITION_5 (672)
    #define POSITION_6 (782)
    
    /// Provide a small movement for CCW or for CW.
    #define SMALL_MOVEMENT (150)
    
#endif

/* [] END OF FILE */
