#pragma once

#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>

#include "Subsystems/DriveSubsystem.h"

#include "OI.h"
#include "RobotMap.h"

class Robot : public frc::TimedRobot {
public:
	static std::shared_ptr<DriveSubsystem> driveSubsystem;
	static std::shared_ptr<OI> oi;

	void RobotInit() override;
	void RobotPeriodic() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	frc::Command* commandAutonomousSelected = nullptr;
	frc::SendableChooser<frc::Command*> dashboardChooser;
};
