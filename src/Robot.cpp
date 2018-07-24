#include "Robot.h"

#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Commands/Autonomous/StillAutoCommand.h"
#include "Commands/TimedArcadeDriveCommand.h"

std::shared_ptr<DriveSubsystem> Robot::driveSubsystem;
std::shared_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	printf("Hello, CRC 2018!\n");
	printf("Team Mulan RobotCode 2018\n");
	printf("WPILib Command-Based C++ Framework, Soha Jin\n");

	RobotMap::init();
	driveSubsystem.reset(new DriveSubsystem());
	oi.reset(new OI());

	dashboardChooser.AddDefault("Do nothing", new StillAutoCommand());
	dashboardChooser.AddObject("Go straight", new TimedArcadeDriveCommand(0.4, 0, 3.2));
	frc::SmartDashboard::PutData("Auto Modes", &dashboardChooser);
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	commandAutonomousSelected = dashboardChooser.GetSelected();

	if (commandAutonomousSelected != nullptr) {
		commandAutonomousSelected->Start();
	}
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (commandAutonomousSelected != nullptr) {
		commandAutonomousSelected->Cancel();
		commandAutonomousSelected = nullptr;
	}
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {}

START_ROBOT_CLASS(Robot)
