#include "InGameBehaviour.h"

#include "Game.h"
#include "ResourcesManager.h"

#include "Shield.h"
#include "ShieldFragment.h"
#include "ElementTypes.h"
#include "Bullet.h"
#include "Element.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>

namespace UldericoAlpha
{
	InGameBehaviour::InGameBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		  m_resources(resources)
	{ 
        Reset();
    }

    void InGameBehaviour::Reset()
    {
        CreateShields();
        CreateBullets();
        m_player.SetPosition(Game::WINDOW_WIDTH / 2.0f, Game::WINDOW_HEIGHT - 30.0f);
    }

	void InGameBehaviour::Update()
	{
        m_player.Move();
        MoveBullets();
        CheckCollisions();
	}

	void InGameBehaviour::OnEvent(sf::Event const& event)
	{
        switch (event.Type)
        {
        case sf::Event::MouseButtonPressed:
            // TEST: Auf Mausdruck neue Kugeln erzeugen.
            CreateBullets();
            break;

        case sf::Event::KeyPressed:
            HandleKeyPressed(event.Key);
            break;

        case sf::Event::KeyReleased:
            HandleKeyReleased(event.Key);
            break;
        }
	}

	void InGameBehaviour::Render(sf::RenderWindow& window)
	{
		DrawShields(window);
        DrawBullets(window);
        DrawPlayer(window);
	}

    void InGameBehaviour::CreateShields()
    {
        m_shields.clear();

        // Speicher reservieren, um mehrfache Allokationen zu vermeiden
        m_shields.reserve(4);

        m_shields.push_back(Shield( 80, 420));
		m_shields.push_back(Shield(260, 420));
		m_shields.push_back(Shield(440, 420));
		m_shields.push_back(Shield(620, 420));
    }

    void InGameBehaviour::CreateBullets()
    {
        m_bullets.clear();

        const unsigned int BULLET_COUNT = 40;

        // Speicher reservieren, um mehrfache Allokationen zu vermeiden
        m_bullets.reserve(BULLET_COUNT);

		for(int i = 0; i < BULLET_COUNT; i++)
		{
			float speed = (rand() % 9 + 1) + 1.0f;
			if (rand() % 2 == 0)
                speed = -speed;

            float positionX = rand() % Game::WINDOW_WIDTH * 1.0f;
            float positionY = rand() % Game::WINDOW_HEIGHT * 1.0f;

            m_bullets.push_back(Bullet(positionX, positionY, speed));
		}
    }

    void InGameBehaviour::MoveBullets()
    {
        // Kugeln weiter bewegen
		for (auto bullet = m_bullets.begin(); bullet != m_bullets.end(); ++bullet)
        {
            bullet->SetPosition(bullet->GetX(), bullet->GetY() + bullet->GetSpeed());
        }
    }
    
    void InGameBehaviour::CheckCollisions()
    {
        // Wenn eine Kugel etwas trifft, dann entfernen
        auto erase_iter = std::remove_if(m_bullets.begin(), m_bullets.end(), [&] (Bullet const& bullet) -> bool
        {
            for (auto shield = m_shields.begin(); shield != m_shields.end(); ++shield)
            {
                if (shield->IsHit(bullet))
                    return true;
		    }

            return false;
        });

        m_bullets.erase(erase_iter, m_bullets.end());
    }

    void InGameBehaviour::DrawShields(sf::RenderWindow& window)
    {
        sf::RectangleShape shieldShape;		
        shieldShape.SetFillColor(sf::Color::Green);
        shieldShape.SetSize(sf::Vector2f(Shield::BLOCK_WIDTH, Shield::BLOCK_HEIGHT));

        for (auto shield = m_shields.begin(); shield != m_shields.end(); ++shield)
		{
            for (int fragment = 0; fragment < shield->GetCount(); ++fragment)
            {
                ShieldFragment const* shieldFragment = shield->GetShieldFragment(fragment);
                if (!shieldFragment->IsDestroyed())
                {
                    shieldShape.SetPosition(shieldFragment->GetX(), shieldFragment->GetY());

                    window.Draw(shieldShape);
                }
            }
        }
    }

    void InGameBehaviour::DrawBullets(sf::RenderWindow& window)
    {
        sf::Sprite bulletSprite = m_resources.GetSprite("red-attack");

        for (auto bullet = m_bullets.begin(); bullet != m_bullets.end(); ++bullet)
        {
            bulletSprite.SetPosition(bullet->GetX(), bullet->GetY());

            window.Draw(bulletSprite);
		}
    }

    void InGameBehaviour::DrawPlayer(sf::RenderWindow& window)
    {
        sf::Sprite playerSprite = m_resources.GetSprite("red-defender");
        
        playerSprite.SetPosition(m_player.GetX(), m_player.GetY());

        window.Draw(playerSprite);
    }

    void InGameBehaviour::HandleKeyPressed(sf::Event::KeyEvent const& event)
    {
        switch (event.Code)
        {
        // Auf Tastendruck Geschwindigkeit des Spielers setzen
        case sf::Keyboard::Left:
            m_player.SetSpeedX(-5.0f);
            break;

        case sf::Keyboard::Right:
            m_player.SetSpeedX(+5.0f);
            break;
        }
    }

    void InGameBehaviour::HandleKeyReleased(sf::Event::KeyEvent const& event)
    {
        switch (event.Code)
        {
        // Wird die Taste wieder losgelassen, dann Geschwindigkeit auf 0 setzen
        case sf::Keyboard::Left:
            m_player.SetSpeedX(0.0f);
            break;

        case sf::Keyboard::Right:
            m_player.SetSpeedX(0.0f);
            break;
        }
    }
}