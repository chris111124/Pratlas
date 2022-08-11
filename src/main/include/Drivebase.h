#pragma once
#include <rev/CANSparkMax.h>
//#include "Robot.h"
#include <frc/Joystick.h>

class Drivebase
{
public:
    void RobotInit();
    void RobotPeriodic();
    void DisabledInit();
private:
    rev::CANSparkMax dbL = rev::CANSparkMax(1, rev::CANSparkMax::MotorType::kBrushed);
    rev::CANSparkMax dbR = rev::CANSparkMax(3, rev::CANSparkMax::MotorType::kBrushed);
    rev::CANSparkMax dbLF = rev::CANSparkMax(2, rev::CANSparkMax::MotorType::kBrushed);
    rev::CANSparkMax dbRF = rev::CANSparkMax(4, rev::CANSparkMax::MotorType::kBrushed);
    frc::Joystick primary{ 0 };
    rev::SparkMaxRelativeEncoder dbLEncoder = dbL.GetEncoder();
    rev::SparkMaxRelativeEncoder dbREncoder = dbR.GetEncoder();
    rev::SparkMaxRelativeEncoder dbLFEncoder = dbLF.GetEncoder();
    rev::SparkMaxRelativeEncoder dbRFEncoder = dbRF.GetEncoder();    
};

