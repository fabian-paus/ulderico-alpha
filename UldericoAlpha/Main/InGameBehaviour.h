#ifndef ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED

#include <vector>

#include "Behaviour.h"

#include "Shield.h"
#include "Bullet.h"
#include "World.h"

#include "PlayerAction.h"
#include "Cooldown.h"

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
		* Zeichnet das f�r das Spiel relevante Daten
		*/
		virtual void Render(sf::RenderTarget& target, float interpolation);
	
	private:
        /**
         * Zeichnet die Schutzschilde.
         */
        void DrawShields(sf::RenderTarget& target);

        /**
         * Zeichnet die aktiven Kugeln.
         */
        void DrawBullets(sf::RenderTarget& target, float interpolation);

        /**
         * Zeichnet den Spieler.
         */
        void DrawPlayer(sf::RenderTarget& target, float interpolation);

		/*
		* Zeichnet die Invaders
		*/
		void DrawInvaders(sf::RenderTarget& target, float interpolation);

        /**
         * Behandelt Benutzereingaben �ber die Tastatur.
         */
        void HandleKeyPressed(sf::Event::KeyEvent const& event);

        /**
         * Behandelt Benutzereingaben �ber die Tastatur.
         */
        void HandleKeyReleased(sf::Event::KeyEvent const& event);

		/**
		 * Behandelt das Spielende. 
		 * Am Spielende muss das Spiel zur�ckgesetzt und der �bergang zum
		 * GameOver Verhalten eingeleitet werden.
		 */
		void HandleGameOver();

    private:
		Game& m_game;
		ResourcesManager& m_resources;

        PlayerAction m_action;
		Cooldown m_shootCooldown;
        World m_world;
	};
}

#endif // ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED
