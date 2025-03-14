#include "commands/TeleIntake.h"

TeleIntake::TeleIntake(frc::XboxController* controller, IntakeSubsystem* subsystem)
	: m_controller(controller)
	, m_intake(subsystem) {
	AddRequirements({ subsystem });
}

void TeleIntake::Initialize() { }

void TeleIntake::Execute() {
	if (m_controller->GetBButton()) {
		m_intake->IntakeRing();
	} else if (m_controller->GetAButton()) {
		wait = wait + 1;
		if (wait >= 15) {
			m_intake->ExpellRing();
		}
	} else {
		wait = 0;
		m_intake->StopIntake();
	}
	m_intake->PivotIntake((0.5 * m_controller->GetLeftTriggerAxis()), (0.80 * m_controller->GetRightTriggerAxis()));
}

void TeleIntake::End(bool interrupted) { }

bool TeleIntake::IsFinished() { return false; }