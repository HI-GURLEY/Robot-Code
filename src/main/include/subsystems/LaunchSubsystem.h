#pragma once

#include "Constants.h"
#include <frc/DigitalOutput.h>
#include <frc/MotorSafety.h>
#include <frc/PowerDistribution.h>
#include <frc/Watchdog.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <units/voltage.h>

#include <cmath>

class LaunchSubsystem : public frc2::SubsystemBase {
public:
	LaunchSubsystem();

	/**
	 * @brief Spins the wheels for the launch mechanism
	 */
	void LaunchRing();

	/**
	 * @brief Spins the flywheels for the launch mechanism
	 * 		  at 12% speed for low goal
	 */
	void GentleRing();

	/**
	 * @brief Spins the lower wheel for the launch mechanism.
	 * Sends the ring for launch.
	 */
	void PushRing();

	/**
	 * @brief Runs the wheels in reverse to store the ring.
	 */
	void IntakeRing();

	/**
	 * @brief Stops the motors for the Launch Subsystem.
	 */
	void Stop();

private:
	// Motor Controllers
	rev::spark::SparkMax m_launchMotor;
	rev::spark::SparkMax m_pushMotor;
};