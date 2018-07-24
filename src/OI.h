#pragma once

#include <WPILib.h>

class OI {
private:
	std::shared_ptr<frc::Joystick> joystickDriver;

public:
	OI();

	std::shared_ptr<frc::Joystick> getJoystickDriver();
	double getDriverRawAxis(int axis);
};
