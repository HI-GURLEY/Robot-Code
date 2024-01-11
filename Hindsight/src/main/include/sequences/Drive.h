#pragma once

#include <frc/PowerDistribution.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/Commands.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/ScheduleCommand.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/button/CommandXboxController.h>

#include <cmath>

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"

class Drive : public frc2::CommandHelper<frc2::CommandBase, Drive> {
public:
	/**
	 * @brief Drive and controls
	 * 
	 * Control Types
	 * =============
	 * 
	 * 0 - Tank
	 * 1 - Arcade
	 * 2 - Mecanum
	 * 3 - Mecanum Tank
	 * 
	 * @param[in] subsystem The sybystem from the DriveSubsytem to be used in controls
	 * @param[in] controlType An integer to set the control scheme used by the xbox controllers
	 */
	explicit Drive(DriveSubsystem* subsystem, int controlType);

	void Initialize() override;

	void Execute() override;

	void End(bool interrupted) override;

	bool IsFinished() override;

private:
	DriveSubsystem* m_drive;

	// The driver's controller.
	frc2::CommandXboxController m_driverController { OIConstants::kDriverControllerPort };
};