#include "LevelList.h"

#include <cassert>

namespace UldericoAlpha
{
	void LevelList::Load()
	{
		static const Level LEVELS[] =
		{
			Level(2.0f, 0.010f),
			Level(3.0f, 0.015f),
			Level(4.0f, 0.020f),
			Level(5.0f, 0.025f)
		};

		static const int LEVELS_COUNT = sizeof (LEVELS) / sizeof (LEVELS[0]);

		m_levels.assign(LEVELS, LEVELS + LEVELS_COUNT);
	}

	std::size_t LevelList::GetMaxLevel() const
	{
		return m_levels.size() - 1;
	}

	Level const& LevelList::operator [] (std::size_t index) const
	{
		assert(index <= GetMaxLevel());

		return m_levels[index];
	}
}
