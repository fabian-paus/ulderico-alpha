#include "Textures.h"

#include <cassert>

namespace UldericoAlpha
{
	std::string GetTextureFile(Textures texture)
	{
		switch (texture)
		{
			case Texture_Characters: return "res/img/characters.png";
			case Texture_Background: return "res/img/invaders.png";
			case Texture_Logo:       return "res/img/logo.png";
			case Texture_Green:      return "res/img/green.png"; 

			default: 
				assert(false);
				return "";
		}
	}
}
