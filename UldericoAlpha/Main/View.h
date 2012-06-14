#ifndef ULDERICO_ALPHA_VIEW_H_INCLUDED
#define ULDERICO_ALPHA_VIEW_H_INCLUDED

#include "World.h"
#include "ResourcesManager.h"

#include <SFML/Graphics/RenderTarget.hpp>

namespace UldericoAlpha
{
	class View
	{
	public:
		View(sf::RenderTarget& target, 
			 ResourcesManager const& resources,
			 float interpolation);

		void Draw(World const& world);

	private:
		void Draw(Shield const& shield);

		void Draw(Bullet const& bullet);

		void Draw(Player const& player);

		void Draw(Invader const& invader);

		void Draw(sf::Sprite& sprite, Vector2D const& position);

		Sprites GetSprite(Bullet const& bullet) const;

		Sprites GetSprite(Invader const& invader) const;

		Vector2D GetPosition(Object const& object) const;

	private:
		sf::RenderTarget& m_target;
		ResourcesManager const& m_resources;
		float m_interpolation;
	};
}

#endif // ULDERICO_ALPHA_VIEW_H_INCLUDED
