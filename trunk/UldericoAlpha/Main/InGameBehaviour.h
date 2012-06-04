#ifndef ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED

#include <vector>

#include "Behaviour.h"

#include "Shield.h"
#include "Bullet.h"
#include "Player.h"

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
		virtual void Render(sf::RenderWindow& window);

		/**
		* Gibt den Status der Klasse zurück
		*/
		virtual GameStates GetState() const { return GameState_InGame; };
	
	private:
        /**
         * Erstellt die Schutzschilde.
         */
        void CreateShields();

        /**
         * Erstellt Testkugeln.
         */
        void CreateBullets();

        /** 
         * Bewegt aktive Kugeln weiter.
         */
        void MoveBullets();

        /** 
         * Überprüft Kollisionen der Kugeln mit anderen Elementen.
         */
        void CheckCollisions();

        /**
         * Zeichnet die Schutzschilde.
         */
        void DrawShields(sf::RenderWindow& window);

        /**
         * Zeichnet die aktiven Kugeln.
         */
        void DrawBullets(sf::RenderWindow& window);

        /**
         * Zeichnet den Spieler.
         */
        void DrawPlayer(sf::RenderWindow& window);

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

        std::vector<Shield> m_shields;
        std::vector<Bullet> m_bullets;
        Player m_player;
	};
}

#endif // ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED
