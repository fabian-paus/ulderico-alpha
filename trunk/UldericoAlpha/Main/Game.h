#ifndef ULDERICO_ALPHA_GAME_H_INCLUDED
#define ULDERICO_ALPHA_GAME_H_INCLUDED

#include "GameStates.h"
#include "ResourcesManager.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

namespace UldericoAlpha
{
    class ResourcesManager;
    class Behaviour;

    /**
     * Diese Klasse repräsentiert das Spiel "UldericoAlpha".
     */
	class Game
	{
	public:
        static const int WINDOW_WIDTH = 775;
        static const int WINDOW_HEIGHT = 572;
        static const std::string WINDOW_TITLE;

        /**
         * Erstellt ein neues Spiel.
         */
		Game();

        /**
         * Startet die Spielschleife.
         */
		void StartGameLoop();

        /**
         * Veranlasst das Spiel in den angegebenen Zustand zu wechseln.
         */
		void ChangeState(GameStates newState);

        /**
         * Beendet das Spiel.
         */
        void Quit();

	private:
        /**
         * Verarbeitet eingehende Ereignisse (z.B. Tastatureingaben).
         */
        void ProcessEvents();

        /**
         * Aktualisiert die Spiellogik in regelmäßigen Abständen.
         */
        void ProcessLogic();

        /**
         * Rendert den aktuellen (interpolierten) Zustand des Spiels.
         */
        void RenderGraphic();

        /**
         * Berechnet in regelmäßigen Abständen die FPS und gibt diese aus.
         */
        void CalculateFPS();

        /**
         * Verknüpft einen Spielzustand mit dem dazugehörigen Verhalten.
         */
        Behaviour* GetBehaviour(GameStates gameState);

    private:
        static const int LOGIC_TICK_MILLISECONDS = 50;
        
        ResourcesManager m_resources;
		sf::RenderWindow m_window;

        sf::Clock m_gameTime;
        sf::Clock m_frameTime;
        int m_frameCount;

		Behaviour* m_currentBehaviour;
	};
}
#endif // ULDERICO_ALPHA_GAME_H_INCLUDED
