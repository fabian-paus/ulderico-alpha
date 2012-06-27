#ifndef ULDERICO_ALPHA_GAME_OVER_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_GAME_OVER_BEHAVIOUR_H_INCLUDED

#include "Behaviour.h"

#include <string>

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
		virtual void Render(sf::RenderTarget& target, float interpolation);

	private:
		static const int MAX_NAME_LENGTH = 10;

		void LeaveGameOver();

		void HandleKeyInput(sf::Keyboard::Key key);

		bool AwaitsNameInput() const;

		bool IsPartOfName(sf::Keyboard::Key key) const;

		void AppendToName(sf::Keyboard::Key key);

	private:
		Game& m_game;
		ResourcesManager& m_resources;

		int m_score;
		std::string m_name;
		bool m_isHighscore;
	};
}

#endif // ULDERICO_ALPHA_GAME_OVER_BEHAVIOUR_H_INCLUDED