#include "Sprites.h"

#include <cassert>

namespace UldericoAlpha
{
	Textures GetTexture(Sprites sprite)
	{
		switch (sprite)
		{
			case Sprite_Background: 
				return Texture_Background;
			case Sprite_Logo: 
				return Texture_Characters;
			case Sprite_GreenShield:
				return Texture_Green;
			
			case Sprite_GreenInvader:
			case Sprite_BlueInvader:
			case Sprite_PurpleInvader:
			case Sprite_RedDefender:
			case Sprite_GreenAttack:
			case Sprite_BlueAttack:
			case Sprite_PurpleAttack:
			case Sprite_RedAttack:
				return Texture_Characters;

			default: 
				assert(false);
				return Textures_Begin;
		}
	}

	sf::IntRect GetPosition(Sprites sprite, sf::Texture const& texture)
	{
		switch (sprite)
		{
			case Sprite_Background: 
			case Sprite_Logo: 
			case Sprite_GreenShield:
				return sf::IntRect(0, 0,
					texture.GetWidth(), texture.GetHeight());
			
			case Sprite_GreenInvader:  return sf::IntRect(0, 0, 82, 86);
			case Sprite_BlueInvader:   return sf::IntRect(112, 0, 116, 86);
			case Sprite_PurpleInvader: return sf::IntRect(250, 0, 122, 86);
			case Sprite_RedDefender:   return sf::IntRect(31, 303, 117, 70);
			case Sprite_GreenAttack:   return sf::IntRect(22, 122, 30, 60);
			case Sprite_BlueAttack:    return sf::IntRect(152, 122, 28, 50);
			case Sprite_PurpleAttack:  return sf::IntRect(290, 122, 28, 50);
			case Sprite_RedAttack:    return sf::IntRect(84, 222, 13, 45);

			default: 
				assert(false);
				return sf::IntRect();
		}
	}

	float GetScale(Sprites sprite)
	{
		switch (sprite)
		{
			case Sprite_Background: 
			case Sprite_Logo: 
			case Sprite_GreenShield:
				return 1.0f;
			
			case Sprite_GreenInvader:
			case Sprite_BlueInvader:
			case Sprite_PurpleInvader:
			case Sprite_RedDefender:
			case Sprite_GreenAttack:
			case Sprite_BlueAttack:
			case Sprite_PurpleAttack:
			case Sprite_RedAttack:
				return 0.4f;

			default: 
				assert(false);
				return 1.0f;
		}
	}
}
