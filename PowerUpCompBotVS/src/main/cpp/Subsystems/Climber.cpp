// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Climber.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/ClimberStop.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Climber::Climber() : frc::Subsystem("Climber") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    climberRelease = RobotMap::climberClimberRelease;
    climberPullMotor = RobotMap::climberClimberPullMotor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Climber::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

       // SetDefaultCommand(new ClimberStop());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Climber::Periodic() {
    // Put code here to be run every loop

}


// Put methods for controlling this subsystem
// here. Call these from Commands.
/*
 * Activates a motor to pull the climer release pin
 *
 * */
void Climber::pinRelease(){
	climberRelease->Set(-0.2); //Check whether this should be positive or negative
}
/*
 * Stops the climer release motor
 * */
void Climber::pinStop(){
	climberRelease->Set(0.0);
}
/*
 * Starts the motor to climb up.
 */
void Climber::climbUp(){
	climberPullMotor->Set(0.5); //Check whether this should be positive or negative
}
/*
 * Stops the climbing motor
 */
void Climber::climbStop(){
	climberPullMotor->Set(0.0);
}

