#ifndef ULDERICO_ALPHA_FONTS_H_INCLUDED
#define ULDERICO_ALPHA_FONTS_H_INCLUDED

#include <string>

namespace UldericoAlpha
{
	/**
	 * Aufz�hlung der im Spiel verwendeten Schriftarten.
	 */
	enum Fonts
	{
		Fonts_Begin,

		Font_CosmicAlien = Fonts_Begin,

		Fonts_Count
	};

	/**
	 * Gibt den Speicherort der Schriftart an.
	 */
	std::string GetFontFile(Fonts font);
}

#endif // ULDERICO_ALPHA_FONTS_H_INCLUDED