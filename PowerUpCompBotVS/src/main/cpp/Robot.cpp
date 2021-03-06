// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<MotionProfile> Robot::motionProfile;
std::shared_ptr<Arm> Robot::arm;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<Climber> Robot::climber;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driveTrain.reset(new DriveTrain());
    motionProfile.reset(new MotionProfile());
    arm.reset(new Arm());
    intake.reset(new Intake());
    climber.reset(new Climber());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS


	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

/*	// Add commands to Autonomous Sendable Chooser
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	chooser.AddObject("Pos1Switch", new Pos1Switch());
	chooser.AddObject("Pos2SwitchLeft", new Pos2SwitchLeft());
	chooser.AddObject("Pos2SwitchRight", new Pos2SwitchRight());
	chooser.AddObject("Pos3Switch", new Pos3Switch());
	chooser.AddObject("CrossTheLine", new CrossTheLine());
	chooser.AddObject("DoNothing", new DoNothing());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
*/
	chooser.AddObject("Pos1Switch", "Pos1Switch");
	chooser.AddObject("Pos2Switch", "Pos2Switch");
	chooser.AddObject("Pos3Switch", "Pos3Switch");
	chooser.AddObject("CrossTheLine", "CrossTheLine");
	chooser.AddObject("DoNothing", "DoNothing");
	frc::SmartDashboard::PutData("Auto Modes", &chooser);

	//cs::UsbCamera camera1 = CameraServer::GetInstance()->StartAutomaticCapture(1);
	//camera1.SetResolution(120, 120);
	//camera1.SetFPS(25);



	cs::UsbCamera camera0 = CameraServer::GetInstance()->StartAutomaticCapture(0);
		camera0.SetResolution(250, 250);
		camera0.SetFPS(35);



}


/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

}

void Robot::AutonomousInit() {

	/*
	 * Keep trying to get driverstation information.
	 */

	while(gameData.length() < 3){
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	}

	/*
	 * Use information from driverstation and auto chooser
	 * to complete autonomous.
	 */

	std::string selectedAuto;

	selectedAuto = chooser.GetSelected();

	std::cout << "GameData:" << gameData <<std::endl;

	if(selectedAuto == "Pos1Switch"){
		if(gameData.length() == 3){
			if(gameData.at(0) == 'L') {
				autonomousCommand = new Pos1Switch();
			}
			else
				autonomousCommand = new CrossTheLine();
		}
		else
			autonomousCommand = new CrossTheLine();
	}

	if (selectedAuto == "Pos2Switch"){
		if(gameData.length() == 3){
			if(gameData.at(0) == 'L') {
				autonomousCommand = new Pos2SwitchLeft();
			}
			else
				autonomousCommand = new Pos2SwitchRight();
		}
		else
			autonomousCommand = new CrossTheLine();
	}

	if(selectedAuto == "Pos3Switch"){
			if(gameData.length() == 3){
				if(gameData.at(0) == 'R') {
					autonomousCommand = new Pos3Switch();
				}
				else
					autonomousCommand = new CrossTheLine();
			}
			else
				autonomousCommand = new CrossTheLine();
		}

	if(selectedAuto == "CrossTheLine"){
		autonomousCommand = new CrossTheLine();
	}

	if(selectedAuto == "DoNothing"){
		autonomousCommand = new DoNothing();
	}

	//autonomousCommand = chooser.GetSelected();
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();

}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();

	/*Put data to the smart dashboard*/

	frc::SmartDashboard::PutNumber("L_CLError", RobotMap::driveTrainLeftFront->GetClosedLoopError(0));
	frc::SmartDashboard::PutNumber("R_CLError", RobotMap::driveTrainRightFront->GetClosedLoopError(0));
	frc::SmartDashboard::PutNumber("L_Pos", RobotMap::driveTrainLeftFront->GetSelectedSensorPosition(0));
	frc::SmartDashboard::PutNumber("R_Pos", RobotMap::driveTrainRightFront->GetSelectedSensorPosition(0));
	frc::SmartDashboard::PutNumber("L_Speed", RobotMap::driveTrainLeftFront->GetSelectedSensorVelocity(0));
	frc::SmartDashboard::PutNumber("R_Speed", RobotMap::driveTrainRightFront->GetSelectedSensorVelocity(0));
	//frc::SmartDashboard::PutNumber("Arm_V", RobotMap::armArmPositionSensor->Get());
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.


	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();

	frc::SmartDashboard::PutNumber("L_CLError", RobotMap::driveTrainLeftFront->GetClosedLoopError(0));
	frc::SmartDashboard::PutNumber("R_CLError", RobotMap::driveTrainRightFront->GetClosedLoopError(0));
	frc::SmartDashboard::PutNumber("L_Pos", RobotMap::driveTrainLeftFront->GetSelectedSensorPosition(0));
	frc::SmartDashboard::PutNumber("R_Pos", RobotMap::driveTrainRightFront->GetSelectedSensorPosition(0));
	frc::SmartDashboard::PutNumber("L_Speed", RobotMap::driveTrainLeftFront->GetSelectedSensorVelocity(0));
	frc::SmartDashboard::PutNumber("R_Speed", RobotMap::driveTrainRightFront->GetSelectedSensorVelocity(0));
	//frc::SmartDashboard::PutNumber("Arm_V", RobotMap::armArmPositionSensor->Get());

}

START_ROBOT_CLASS(Robot);

