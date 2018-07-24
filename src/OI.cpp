#include "OI.h"

OI::OI() {
	joystickDriver.reset(new Joystick(0));
}

std::shared_ptr<Joystick> OI::getJoystickDriver(){
	return joystickDriver;
}

double OI::getDriverRawAxis(int axis){
	return joystickDriver->GetRawAxis(axis);
}
