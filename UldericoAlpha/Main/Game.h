#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>

#include "ResourcesManager.h"
#include "Behaviour.h"
#include "Element.h"

namespace UldericoAlpha
{
	class Game
	{
	public:
		Game();

		void StartGameLoop();

		void ChangeState(GameStates newState);

		std::vector<Element*> GetElements() { return m_elements; }; 

		void DeleteElement(int index) { m_elements.erase(m_elements.begin() + index); }; 

	private:
		sf::RenderWindow m_window;

		ResourcesManager m_resources;

		GameStates m_gameState;

		std::vector<Behaviour*> m_behaviours;

		std::vector<Element*> m_elements;
	};
}
#endif