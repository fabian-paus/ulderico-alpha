#ifndef ULDERICO_ALPHA_GAME_OVER_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_GAME_OVER_BEHAVIOUR_H_INCLUDED

#include "Behaviour.h"

namespace UldericoAlpha
{
    class Game;
    class ResourcesManager;

	/**
	 * Game-Over Bildschirm.
	 */
	class GameOverBehaviour : public Behaviour
	{
	public:
		GameOverBehaviour(Game& game, ResourcesManager& resources);

		/**
		 * Diese Methode wird vom Spiel in jedem Logik-Tick aufgerufen.
		 */
		virtual void Update();

		/**
		 * Bei einem Ereignis (Tastatur, Maus) wird diese Methode aufgerufen.
		 */
		virtual void OnEvent(sf::Event const& event);

		/**
		 * Wenn der Zustand dargestellt werden soll, wird diese Methode aufgerufen.
		 */
		virtual void Render(sf::RenderTarget& window, float interpolation);

	private:
		Game& m_game;
		ResourcesManager& m_resources;
	};
}

#endif // ULDERICO_ALPHA_GAME_OVER_BEHAVIOUR_H_INCLUDED