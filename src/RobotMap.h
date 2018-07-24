#pragma once

#include <WPILib.h>

class RobotMap {
public:
	static void init();

	static std::shared_ptr<frc::Spark> motorDriveLeftFront;
	static std::shared_ptr<frc::Spark> motorDriveRightFront;
	static std::shared_ptr<frc::Spark> motorDriveLeftRear;
	static std::shared_ptr<frc::Spark> motorDriveRightRear;
	static std::shared_ptr<frc::SpeedControllerGroup> motorDriveGroupLeft;
	static std::shared_ptr<frc::SpeedControllerGroup> motorDriveGroupRight;
	static std::shared_ptr<frc::DifferentialDrive> robotDrive;
};
