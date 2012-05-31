#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "ResourcesManager.h"
#include "Level.h"
#include "Player.h"
#include "Bullet.h"
#include "BoundaryBox.h"

#include "Behaviour.h"

namespace UldericoAlpha
{
	class Game
	{
	public:
		Game();

		void StartGameLoop();

		void ChangeState(GameStates newState);

	private:
		sf::RenderWindow m_window;
		ResourcesManager m_resources;
		Behaviour* m_behaviour;
	};
}
#endif