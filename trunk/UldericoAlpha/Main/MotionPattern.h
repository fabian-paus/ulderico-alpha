#ifndef ULDERICO_ALPHA_MOTION_PATTERN_H_INCLUDED
#define ULDERICO_ALPHA_MOTION_PATTERN_H_INCLUDED

#include "InvaderAction.h"
#include "InvaderStep.h"

#include <vector>

namespace UldericoAlpha
{
	class MotionPattern
	{
	public:
		MotionPattern(bool iterative);

		void AddStep(InvaderAction invaderAction, int duration);

		InvaderAction GetAction();

		void SetNextAction();
	private:
		int m_position;
		bool m_iterative;
		std::vector<InvaderStep> m_invaderSteps;
		int m_actualDuration;
		InvaderAction m_actualInvaderAction;
	};
}

#endif // ULDERICO_ALPHA_MOTION_PATTERN_H_INCLUDED