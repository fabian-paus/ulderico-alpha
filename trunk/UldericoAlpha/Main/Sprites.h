#ifndef ULDERICO_ALPHA_SPRITES_H_INCLUDED
#define ULDERICO_ALPHA_SPRITES_H_INCLUDED

#include "Textures.h"

#include <SFML/Graphics/Texture.hpp>

namespace UldericoAlpha
{
	/**
	 * Aufzählung der im Spiel verwendeten Sprites.
	 */
	enum Sprites
	{
		Sprites_Begin,

		Sprite_Background = Sprites_Begin,
		Sprite_Logo,
		Sprite_GreenInvader,
		Sprite_BlueInvader,
		Sprite_PurpleInvader,
		Sprite_RedDefender,
		Sprite_GreenAttack,
		Sprite_BlueAttack,
		Sprite_PurpleAttack,
		Sprite_RedAttack,
		Sprite_GreenShield,

		Sprites_Count
	};

	/**
	 * Gibt die Textur des Sprites an.
	 */
	Textures GetTexture(Sprites sprite);

	/**
	 * Gibt die Position des Sprites an.
	 */
	sf::IntRect GetPosition(Sprites sprite, sf::Texture const& texture);

	/**
	 * Gibt den Skalierungsfaktor des Sprites an.
	 */
	float GetScale(Sprites sprite);
}

#endif // ULDERICO_ALPHA_SPRITES_H_INCLUDED