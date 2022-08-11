#include <Subsystems/Drivebase.h>

void Drivebase::RobotInit()
{
    dbL.RestoreFactoryDefaults();
    dbLF.RestoreFactoryDefaults();
    dbR.RestoreFactoryDefaults();
    dbRF.RestoreFactoryDefaults();

    dbLF.Follow(dbL);
    dbRF.Follow(dbR);

    dbL.SetInverted(true);
    dbLF.SetInverted(true);
    dbR.SetInverted(false);
    dbRF.SetInverted(false);
    
    dbR.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    dbL.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    dbRF.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    dbLF.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    dbR.BurnFlash();
    dbRF.BurnFlash();
    dbL.BurnFlash();
    dbLF.BurnFlash();

    dbREncoder.SetPosition(0);
    dbLEncoder.SetPosition(0);
    dbRFEncoder.SetPosition(0);
    dbLFEncoder.SetPosition(0);
}

void Drivebase::RobotPeriodic()
{
    dbL.Set(primary.GetRawAxis(5) * .5);
    dbR.Set(primary.GetRawAxis(1) * .5);

    if (dbLEncoder.GetPosition() >= 10)
    {
        dbL.Set(0);
    }
    else
    {
        dbL.Set(0.1);
    }
        if (dbREncoder.GetPosition() >= 10)
    {
        dbR.Set(0);
    }
    else
    {
    dbR.Set(0.1);
    }
}

void Drivebase::DisabledInit()
{
    dbR.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    dbL.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    dbRF.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    dbLF.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}