#include "RobotMap.h"

std::shared_ptr<Spark> RobotMap::motorDriveLeftFront;
std::shared_ptr<Spark> RobotMap::motorDriveRightFront;
std::shared_ptr<Spark> RobotMap::motorDriveLeftRear;
std::shared_ptr<Spark> RobotMap::motorDriveRightRear;
std::shared_ptr<SpeedControllerGroup> RobotMap::motorDriveGroupLeft;
std::shared_ptr<SpeedControllerGroup> RobotMap::motorDriveGroupRight;
std::shared_ptr<DifferentialDrive> RobotMap::robotDrive;

void RobotMap::init(){
	motorDriveLeftFront.reset(new Spark(0));
	motorDriveLeftRear.reset(new Spark(1));
	motorDriveRightFront.reset(new Spark(2));
	motorDriveRightRear.reset(new Spark(3));
	motorDriveGroupLeft.reset(new SpeedControllerGroup(*motorDriveLeftFront,*motorDriveLeftRear));
	motorDriveGroupRight.reset(new SpeedControllerGroup(*motorDriveRightFront,*motorDriveRightRear));
	robotDrive.reset(new DifferentialDrive(*motorDriveGroupLeft,*motorDriveGroupRight));
}
