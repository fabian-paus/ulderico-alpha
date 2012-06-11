#ifndef ULDERICO_ALPHA_TEXTURES_H_INCLUDED
#define ULDERICO_ALPHA_TEXTURES_H_INCLUDED

#include <string>

namespace UldericoAlpha
{
	/**
	 * Aufzählung der im Spiel verwendeten Texturen.
	 */
	enum Textures
	{
		Textures_Begin,

		Texture_Characters = Textures_Begin,
		Texture_Background,
		Texture_Logo,
		Texture_Green,

		Textures_Count
	};

	/**
	 * Gibt den Speicherort der angegebenen Textur zurück.
	 */
	std::string GetTextureFile(Textures texture);
}

#endif // ULDERICO_ALPHA_TEXTURES_H_INCLUDED