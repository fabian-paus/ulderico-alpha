#include "MotionPattern.h"

namespace UldericoAlpha
{
	MotionPattern::MotionPattern(bool iterative)
		:m_iterative(iterative),
		 m_actualDuration(0),
		 m_actualInvaderAction(InvaderAction_MoveRight),
		 m_position(0)
	{}

	void MotionPattern::AddStep(InvaderAction invaderAction, int duration)
	{
		InvaderStep invaderStep(invaderAction, duration);
		if(m_invaderSteps.empty())
		{
			m_actualDuration = duration;
			m_actualInvaderAction = invaderAction;
			m_invaderSteps.push_back(invaderStep);
		}
		else
		{
			m_invaderSteps.push_back(invaderStep);
		}
	}

	InvaderAction MotionPattern::GetAction()
	{
		//Abfragen ob die Aktion abgelaufen ist
		if(m_actualDuration == 0)
			SetNextAction();
		if(m_actualDuration > 0)
			m_actualDuration--;
		return m_actualInvaderAction;
	}

	void MotionPattern::SetNextAction()
	{
		//Nächste Aktion aus dem Step Vektor auslesen
		//Falls man am Ende angekommen ist schauen ob iterativ gesetzt ist ansonsten nichts mehr machen
		if(m_position < m_invaderSteps.size() - 1)
		{
			m_position++;
			InvaderStep invaderStep = m_invaderSteps.at(m_position);
			m_actualDuration = invaderStep.GetDuration();
			m_actualInvaderAction = invaderStep.GetInvaderAction();
		}
		else
		{
			if(m_iterative)
			{
				m_position = 0;
				InvaderStep invaderStep = m_invaderSteps.at(m_position);
				m_actualDuration = invaderStep.GetDuration();
				m_actualInvaderAction = invaderStep.GetInvaderAction();
			}
			else
			{
				m_actualDuration = -1;
				m_actualInvaderAction = InvaderAction_Nothing;
			}
		}
	}

	void MotionPattern::Clear()
	{
		m_invaderSteps.clear();
		m_position = 0;
	}
}