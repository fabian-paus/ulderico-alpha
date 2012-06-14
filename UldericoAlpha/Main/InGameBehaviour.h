#ifndef ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED

#include <vector>

#include "Behaviour.h"

#include "World.h"

#include "PlayerAction.h"
#include "Cooldown.h"

#include <SFML\Audio\Sound.hpp>

namespace UldericoAlpha
{
    class Game;
    class ResourcesManager;

	/**
	 * Spielverhalten: Im Spiel.
	 */
	class InGameBehaviour : public Behaviour
	{
	public:
		InGameBehaviour(Game& game, ResourcesManager& resources);
    
        void Reset();

		/**
		 * Diese Methode wird vom Spiel in jedem Logik-Tick aufgerufen.
		 */
		virtual void Update();

		/**
		 * Bei einem Ereignis (Tastatur, Maus) wird diese Methode aufgerufen.
		 */
		virtual void OnEvent(sf::Event const& event);

		/**
		* Zeichnet das für das Spiel relevante Daten
		*/
		virtual void Render(sf::RenderTarget& target, float interpolation);
	
	private:
        /**
         * Behandelt Benutzereingaben über die Tastatur.
         */
        void HandleKeyPressed(sf::Event::KeyEvent const& event);

        /**
         * Behandelt Benutzereingaben über die Tastatur.
         */
        void HandleKeyReleased(sf::Event::KeyEvent const& event);

		/**
		 * Behandelt das Spielende. 
		 * Am Spielende muss das Spiel zurückgesetzt und der Übergang zum
		 * GameOver Verhalten eingeleitet werden.
		 */
		void HandleGameOver();

    private:
		Game& m_game;
		ResourcesManager& m_resources;

        PlayerAction m_action;
		Cooldown m_shootCooldown;
        World m_world;
		
		sf::Sound m_shootSound;
		sf::Sound m_killedSound;
		sf::Sound m_explosionSound;
	};
}

#endif // ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED
