#include "Cooldown.h"

namespace UldericoAlpha
{
	Cooldown::Cooldown(int timeInTicks)
		: m_timeInTicks(timeInTicks),
		m_currentTicks(0)
	{ }

	void Cooldown::Tick()
	{
		if (!IsElapsed())
			--m_currentTicks;
	}

	bool Cooldown::IsElapsed() const
	{
		return m_currentTicks == 0;
	}

	void Cooldown::Start()
	{
		m_currentTicks = m_timeInTicks;
	}
}