#include "InGameBehaviour.h"

#include "Game.h"
#include "ResourcesManager.h"

#include "Shield.h"
#include "Bullet.h"

namespace UldericoAlpha
{
    sf::Vector2f toSFML(Vector2D const& vector)
    {
        return sf::Vector2f(vector.GetX(), vector.GetY());
    }

    static const Vector2D WORLD_SIZE(
        static_cast<float>(Game::WINDOW_WIDTH),
        static_cast<float>(Game::WINDOW_HEIGHT));

	InGameBehaviour::InGameBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		  m_resources(resources),
          m_action(PlayerAction_Nothing),
          m_world(WORLD_SIZE)
	{ }

    void InGameBehaviour::Reset()
    {
        m_world = World(WORLD_SIZE);
    }

	void InGameBehaviour::Update()
	{
        m_world.Update();
        switch (m_action)
        {
        case PlayerAction_MoveLeft:
            m_world.MovePlayerLeft();
            break;

        case PlayerAction_MoveRight:
            m_world.MovePlayerRight();
            break;

        case PlayerAction_StopMovement:
            m_world.StopPlayerMovement();
            break;

        case PlayerAction_Shoot:
            m_world.ShootFromPlayer();
            break;
        }
	}

	void InGameBehaviour::OnEvent(sf::Event const& event)
	{
        switch (event.Type)
        {
        case sf::Event::KeyPressed:
            HandleKeyPressed(event.Key);
            break;

        case sf::Event::KeyReleased:
            HandleKeyReleased(event.Key);
            break;
        }
	}

	void InGameBehaviour::Render(sf::RenderTarget& window, float interpolation)
	{
		DrawShields(window);
        DrawBullets(window, interpolation);
        DrawPlayer(window, interpolation);
	}

    void InGameBehaviour::DrawShields(sf::RenderTarget& window)
    {
        sf::RectangleShape shieldShape;		
        shieldShape.SetFillColor(sf::Color::Green);
        shieldShape.SetSize(sf::Vector2f(Shield::BLOCK_WIDTH, Shield::BLOCK_HEIGHT));

        for (auto shield = m_world.ShieldsBegin(); shield != m_world.ShieldsEnd(); ++shield)
		{
            for(int y = 0; y < Shield::BLOCK_COUNT_HEIGHT; y++)
            {
                for(int x = 0; x < Shield::BLOCK_COUNT_WIDTH; x++)
                {
                    if (shield->FragmentExists(x, y))
                    {
                        Vector2D delta(x * Shield::BLOCK_WIDTH, y * Shield::BLOCK_HEIGHT);
                        Vector2D position = shield->GetPosition() + delta;

                        shieldShape.SetPosition(toSFML(position));
                        window.Draw(shieldShape);
                    }
                }
            }
        }
    }

    void InGameBehaviour::DrawBullets(sf::RenderTarget& window, float interpolation)
    {
        sf::Sprite bulletSprite = m_resources.GetSprite("red-attack");

        for (auto bullet = m_world.BulletsBegin(); bullet != m_world.BulletsEnd(); ++bullet)
        {
            bulletSprite.SetPosition(toSFML(bullet->PredictPosition(interpolation)));

            window.Draw(bulletSprite);
		}
    }

    void InGameBehaviour::DrawPlayer(sf::RenderTarget& window, float interpolation)
    {
        sf::Sprite playerSprite = m_resources.GetSprite("red-defender");
        
        Player const& player = m_world.GetPlayer();
        playerSprite.SetPosition(toSFML(player.PredictPosition(interpolation)));

        window.Draw(playerSprite);
    }

    void InGameBehaviour::HandleKeyPressed(sf::Event::KeyEvent const& event)
    {
        switch (event.Code)
        {
        // Auf Tastendruck Geschwindigkeit des Spielers setzen
        case sf::Keyboard::Left:
            m_action = PlayerAction_MoveLeft;
            break;

        case sf::Keyboard::Right:
            m_action = PlayerAction_MoveRight;
            break;

        case sf::Keyboard::Space:
            m_action = PlayerAction_Shoot;
            break;
        }
    }

    void InGameBehaviour::HandleKeyReleased(sf::Event::KeyEvent const& event)
    {
        switch (event.Code)
        {
        // Wird die Taste wieder losgelassen, dann Geschwindigkeit auf 0 setzen
        case sf::Keyboard::Left:
            if (m_world.GetPlayer().GetSpeed().GetX() < 0.0f)
                m_action = PlayerAction_StopMovement;
            break;

        case sf::Keyboard::Right:
            if (m_world.GetPlayer().GetSpeed().GetX() > 0.0f)
                m_action = PlayerAction_StopMovement;
            break;
            
        case sf::Keyboard::Space:
            if (m_action == PlayerAction_Shoot)
                m_action = PlayerAction_Nothing;
            break;
        }
    }
}