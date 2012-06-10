#ifndef ULDERICO_ALPHA_INVADER_STEP_H_INCLUDED
#define ULDERICO_ALPHA_INVADER_STEP_H_INCLUDED

#include "InvaderAction.h"

namespace UldericoAlpha
{
	class InvaderStep
	{
	public:
		InvaderStep(InvaderAction invaderAction, int duration);

		InvaderAction GetInvaderAction() { return m_invaderAction; };

		int GetDuration() { return m_duration; };
	private:
		InvaderAction m_invaderAction;
		int m_duration;
	};
}

#endif // ULDERICO_ALPHA_INVADER_STEP_H_INCLUDED