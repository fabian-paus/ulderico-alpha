#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "ResourcesManager.h"
#include "Behaviour.h"
#include "Element.h"

namespace UldericoAlpha
{
	class Game
	{
	public:
        static const int WINDOW_WIDTH = 775;
        static const int WINDOW_HEIGHT = 572;
        static const std::string WINDOW_TITLE;

		Game();

		void StartGameLoop();

		void ChangeState(GameStates newState);

	private:
        Behaviour* GetBehaviour(GameStates gameState);

    private:
        static const int LOGIC_TICK_MILLISECONDS = 50;

		sf::RenderWindow m_window;
		ResourcesManager m_resources;

		Behaviour* m_currentBehaviour;
	};
}
#endif