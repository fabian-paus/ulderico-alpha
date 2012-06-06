#ifndef ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED

#include <vector>

#include "Behaviour.h"

#include "Shield.h"
#include "Bullet.h"
#include "World.h"

#include "PlayerAction.h"

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
		virtual void Render(sf::RenderTarget& window, float interpolation);
	
	private:
        /**
         * Zeichnet die Schutzschilde.
         */
        void DrawShields(sf::RenderTarget& window);

        /**
         * Zeichnet die aktiven Kugeln.
         */
        void DrawBullets(sf::RenderTarget& window, float interpolation);

        /**
         * Zeichnet den Spieler.
         */
        void DrawPlayer(sf::RenderTarget& window, float interpolation);

        /**
         * Behandelt Benutzereingaben über die Tastatur.
         */
        void HandleKeyPressed(sf::Event::KeyEvent const& event);

        /**
         * Behandelt Benutzereingaben über die Tastatur.
         */
        void HandleKeyReleased(sf::Event::KeyEvent const& event);

    private:
		Game& m_game;
		ResourcesManager& m_resources;

        PlayerAction m_action;
        World m_world;
	};
}

#endif // ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED
