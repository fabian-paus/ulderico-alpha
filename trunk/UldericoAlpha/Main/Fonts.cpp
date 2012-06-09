#include "Fonts.h"

#include <cassert>

namespace UldericoAlpha
{
	std::string GetFontFile(Fonts font)
	{
		switch (font)
		{
		case Font_CosmicAlien: return "res/font/ca.ttf";

		default:
			assert(false);
			return "";
		}
	}
}
