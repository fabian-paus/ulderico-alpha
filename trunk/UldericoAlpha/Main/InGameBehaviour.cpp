#include "InGameBehaviour.h"

#include "Game.h"
#include "ResourcesManager.h"

#include "View.h"

#include <SFML\Graphics\RectangleShape.hpp>

namespace UldericoAlpha
{
    sf::Vector2f toSFML(Vector2D const& vector)
    {
        return sf::Vector2f(vector.GetX(), vector.GetY());
    }

    static const Vector2D WORLD_SIZE(
        static_cast<float>(Game::WINDOW_WIDTH),
        static_cast<float>(Game::WINDOW_HEIGHT));

	static const int SHOOT_COOLDOWN_IN_TICKS = 5;

	InGameBehaviour::InGameBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		  m_resources(resources),
          m_action(PlayerAction_Nothing),
		  m_shootCooldown(SHOOT_COOLDOWN_IN_TICKS),
          m_world(WORLD_SIZE, Level(2.0f, 0.02f))
	{ }

    void InGameBehaviour::Reset()
    {
        m_world = World(WORLD_SIZE, Level(2.0f, 0.02f));
    }

	void InGameBehaviour::Update()
	{
        m_world.Update();

		m_shootCooldown.Tick();
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
			if (m_shootCooldown.IsElapsed())
			{
				m_world.ShootFromPlayer();
				m_shootCooldown.Start();
			}
            break;
        }

		// Wenn der Spieler stirbt, ist das Spiel beendet
		if (!m_world.IsPlayerAlive())
			HandleGameOver();

		// TODO: Wenn alle Invader getötet wurden, dann neues Level beginnen
		// Im Moment: Spiel beenden
		if (!m_world.HasInvaders())
			HandleGameOver();
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

	void InGameBehaviour::Render(sf::RenderTarget& target, float interpolation)
	{
		View view(target, m_resources, interpolation);
		view.Draw(m_world);
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

	void InGameBehaviour::HandleGameOver()
	{
		// Die Welt zurücksetzen
		Reset();

		// Übergang zum "Game Over"-Bildschirm
		m_game.ChangeState(GameState_GameOver);
	}
}