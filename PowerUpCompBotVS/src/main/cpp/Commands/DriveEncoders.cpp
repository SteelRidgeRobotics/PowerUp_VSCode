// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DriveEncoders.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

DriveEncoders::DriveEncoders(double left, double right): frc::Command() {
    m_left = left;
    m_right = right;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	m_done = false;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void DriveEncoders::Initialize() {
	std::cout << "DriveForward!" << std::endl;
	SetTimeout(3.0);
	m_done = false;
	Robot::driveTrain->encoderReset();
}

// Called repeatedly when this Command is scheduled to run
void DriveEncoders::Execute() {
Robot::driveTrain->encoderPosition(m_left, m_right);
Robot::driveTrain->isMove();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveEncoders::IsFinished() {
    return m_done || IsTimedOut();
}

// Called once after isFinished returns true
void DriveEncoders::End() {
Robot::driveTrain->encoderDone();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveEncoders::Interrupted() {
End();
}
