#ifndef ULDERICO_ALPHA_LEVEL_LIST_H_INCLUDED
#define ULDERICO_ALPHA_LEVEL_LIST_H_INCLUDED

#include "Level.h"

#include <vector>

namespace UldericoAlpha
{
	class LevelList
	{
	public:
		void Load();

		std::size_t GetMaxLevel() const;

		Level const& operator [] (std::size_t index) const;

	private:
		std::vector<Level> m_levels;
	};
}

#endif // ULDERICO_ALPHA_LEVEL_LIST_H_INCLUDED