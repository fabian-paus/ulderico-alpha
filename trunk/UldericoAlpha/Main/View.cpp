#include "View.h"

#include <cassert>

namespace UldericoAlpha
{
	View::View(sf::RenderTarget& target, 
			   ResourcesManager const& resources,
			   float interpolation)
		: m_target(target),
		  m_resources(resources),
		  m_interpolation(interpolation)
	{ }

	void View::Draw(World const& world)
	{
		Draw(world.GetPlayer());

		for (auto shield = world.ShieldsBegin(); shield != world.ShieldsEnd(); ++shield)
			Draw(*shield);

		for (auto bullet = world.BulletsBegin(); bullet != world.BulletsEnd(); ++bullet)
			Draw(*bullet);

		for (auto invader = world.InvadersBegin(); invader != world.InvadersEnd(); ++invader)
			Draw(*invader);
	}

	void View::Draw(Shield const& shield)
	{
		sf::Sprite shieldSprite = m_resources.Get(Sprite_GreenShield);	
		Vector2D shieldPosition = GetPosition(shield);

        for(int y = 0; y < Shield::BLOCK_COUNT_HEIGHT; y++)
        {
            for(int x = 0; x < Shield::BLOCK_COUNT_WIDTH; x++)
            {
                if (shield.FragmentExists(x, y))
                {
                    Vector2D delta(x * Shield::BLOCK_WIDTH, y * Shield::BLOCK_HEIGHT);
                    Vector2D position = shieldPosition + delta;

                    Draw(shieldSprite, position);
                }
            }
        }
	}

	void View::Draw(Bullet const& bullet)
	{
		Sprites sprite = GetSprite(bullet);
		sf::Sprite bulletSprite = m_resources.Get(sprite);	

        Draw(bulletSprite, GetPosition(bullet));
	}

	void View::Draw(Player const& player)
	{
		sf::Sprite playerSprite = m_resources.Get(Sprite_RedDefender);
        
        Draw(playerSprite, GetPosition(player));
	}

	void View::Draw(Invader const& invader)
	{
		Sprites sprite = GetSprite(invader);
		sf::Sprite invaderSprite = m_resources.Get(sprite);

		Draw(invaderSprite, GetPosition(invader));
	}

	void View::Draw(sf::Sprite& sprite, Vector2D const& position)
	{
		sprite.SetPosition(position.GetX(), position.GetY());

		m_target.Draw(sprite);
	}

	Sprites View::GetSprite(Bullet const& bullet) const
	{
		switch (bullet.GetType())
		{
		case Bullet_Player: return Sprite_RedAttack;
		case Bullet_Green:  return Sprite_GreenAttack;
		case Bullet_Blue:   return Sprite_BlueAttack;
		case Bullet_Purple: return Sprite_PurpleAttack;
		
		default:
			assert(false);
			return Sprites_Begin;
		}
	}

	Sprites View::GetSprite(Invader const& invader) const
	{
		switch(invader.GetType())
		{
		case InvaderType_Green:  return Sprite_GreenInvader;
		case InvaderType_Blue:   return Sprite_BlueInvader;
		case InvaderType_Purple: return Sprite_PurpleInvader;
			
		default:
			assert(false);
			return Sprites_Begin;
		}
	}

	Vector2D View::GetPosition(Object const& object) const
	{
		return object.PredictPosition(m_interpolation);
	}
}
