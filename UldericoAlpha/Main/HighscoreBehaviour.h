#ifndef ULDERICO_ALPHA_HIGHSCORE_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_HIGHSCORE_BEHAVIOUR_H_INCLUDED

#include "Behaviour.h"

namespace UldericoAlpha
{
    class Game;
    class ResourcesManager;

	/**
	 * Highscore-Anzeige.
	 */
	class HighscoreBehaviour : public Behaviour
	{
	public:
		HighscoreBehaviour(Game& game, ResourcesManager& resources);

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
		virtual void Render(sf::RenderTarget& target, float interpolation);

	private:
		Game& m_game;
		ResourcesManager& m_resources;
	};
}

#endif // ULDERICO_ALPHA_HIGHSCORE_BEHAVIOUR_H_INCLUDED