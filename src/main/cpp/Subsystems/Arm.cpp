#include "Subsystems/Arm.h"

void Arm::RobotInit()
{
    leverControl.RestoreFactoryDefaults();

    leverControl.SetInverted(false);

    leverControl.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    leverControl.BurnFlash();

    leverControlEncoder.SetPosition(0);
}


void Arm::RobotPeriodic()
{
    if (primary.GetRawButton(2))
    {
        //leverControl.Set(primary.GetRawButton(true));

        if (leverControlEncoder.GetPosition() >= 5)
        {
            leverControl.Set(0);
        }
        else
        {
            leverControl.Set(.2);
        }
    }
     if (primary.GetRawButton(1))
    {
        //leverControl.Set(primary.GetRawButton(true));

        if (leverControlEncoder.GetPosition() <= 0)
        {
            leverControl.Set(0);
        }
        else
        {
            leverControl.Set(-.2);
        }
    }
}

void Arm::DisabledInit()
{
    leverControl.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}