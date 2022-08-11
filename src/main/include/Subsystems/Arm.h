#pragma once
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>

class Arm
{
public:
    void RobotInit();
    void RobotPeriodic();
    void DisabledInit();
private:
    rev::CANSparkMax leverControl = rev::CANSparkMax(11, rev::CANSparkMax::MotorType::kBrushless);
    frc::Joystick primary{ 0 };
    rev::SparkMaxRelativeEncoder leverControlEncoder = leverControl.GetEncoder();
};