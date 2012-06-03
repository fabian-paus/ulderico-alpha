#include "InGameBehaviour.h"

#include "Shield.h"
#include "ShieldFragment.h"
#include "ElementTypes.h"
#include "Bullet.h"
#include "Element.h"

namespace UldericoAlpha
{
	InGameBehaviour::InGameBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		m_resources(resources)
	{}

	void InGameBehaviour::Update()
	{
		std::vector<Element*>::iterator it;
		std::vector<Element*> elements = m_game.GetElements();
		std::vector<int> erase;
		std::vector<int>::iterator erase_it;
		erase_it = erase.begin();
		int elementIndex = 0;

		it = elements.begin();
		for(; it != elements.end(); ++it, elementIndex++)
		{
			switch((*it)->GetType())
			{
			case ElementType_Bullet:
				{
					Bullet *bullet = (Bullet*)*it;
					bullet->SetPosition(bullet->GetX(), bullet->GetY() + bullet->GetSpeed());
					std::vector<Element*>::iterator bullet_it;
					
					for(bullet_it = elements.begin(); bullet_it != elements.end(); ++bullet_it)
					{
						Element *hitTestEl = (Element*)*bullet_it;
						if(hitTestEl->GetType() != bullet->GetType())
						{
							if(hitTestEl->IsHit(*bullet))
							{
								bullet->SetSpeed(0);
								erase_it = erase.insert(erase_it, elementIndex); 
							}
						}
					}
					break;
				}
			}
		}
		for(int i = 0; i < erase.size(); i++) 
		{ 
			m_game.DeleteElement(erase[i]);
		}
	}

	void InGameBehaviour::OnEvent(sf::Event const& event)
	{

	}

	void InGameBehaviour::Render(sf::RenderWindow& window)
	{
		//Zeichne die Schilde
		std::vector<Element*>::iterator it;
		std::vector<Element*> elements = m_game.GetElements();
		it = elements.begin();
		for(; it != elements.end(); ++it)
		{
			switch((*it)->GetType())
			{
			case ElementType_Shield:
				{
					Shield *shield = (Shield*)*it;
					for(int i = 0; i < shield->Count(); i++)
					{
						ShieldFragment *shieldFragment = shield->GetShieldFragment(i);
						if(!shieldFragment->IsDestroyed())
						{
							sf::RectangleShape shieldShape;							
							shieldShape.SetFillColor(sf::Color::Green);
							shieldShape.SetPosition(shieldFragment->GetX(), shieldFragment->GetY());
							shieldShape.SetSize(sf::Vector2f(shieldFragment->GetBoundingBox().GetWidth(), shieldFragment->GetBoundingBox().GetHeight()));
							window.Draw(shieldShape);
						}
					}
					break;
				}
			case ElementType_Bullet:
				{
					Bullet *bullet = (Bullet*)*it;
					sf::RectangleShape bulletShape;
					bulletShape.SetFillColor(sf::Color::Red);
					bulletShape.SetPosition(bullet->GetX(), bullet->GetY());
					bulletShape.SetSize(sf::Vector2f(bullet->GetBoundingBox().GetWidth(), bullet->GetBoundingBox().GetHeight()));
					window.Draw(bulletShape);
					break;
				}
			}
		}
	}
}