#include "subsystems/IntakeSubsystem.h"

using namespace IntakeConstants;

IntakeSubsystem::IntakeSubsystem()
	: m_intakePivot { kIntakePivot }
	, m_intakeMotor { kIntakeMotor } { }

/*
 * Intake functions
 */
void IntakeSubsystem::IntakeRing() { m_intakeMotor.Set(1); }

void IntakeSubsystem::ExpellRing() { m_intakeMotor.Set(-1); }

void IntakeSubsystem::StopInake() { m_intakeMotor.Set(0); }

void IntakeSubsystem::PivotIntake(double upSpeed, double downSpeed) { }
