#ifndef ULDERICO_ALPHA_HIGHSCORE_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_HIGHSCORE_BEHAVIOUR_H_INCLUDED

#include "Behaviour.h"
#include "ResourcesManager.h"

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
		/**
		* Margin beschreibt den Abstand zwischen den Highscore-Elementen
		*/
		static const int MARGIN = 30;

		/**
		* Namen für die Highscore-Elemente
		*/
		static const sf::String STR_PLACEMENT_NAME_FIRST;
		static const int STR_SCORE_NAME_FIRST;
		static const sf::String STR_PLACEMENT_NAME_SECOND;
		static const int STR_SCORE_NAME_SECOND;
		static const sf::String STR_PLACEMENT_NAME_THIRD;
		static const int STR_SCORE_NAME_THIRD;
		static const sf::String STR_PLACEMENT_NAME_FOURTH;
		static const int STR_SCORE_NAME_FOURTH;
		static const sf::String STR_PLACEMENT_NAME_FIFTH;
		static const int STR_SCORE_NAME_FIFTH;
		static const sf::String STR_PLACEMENT_NAME_SIXTH;
		static const int STR_SCORE_NAME_SIXTH;
		static const sf::String STR_PLACEMENT_NAME_SEVENTH;
		static const int STR_SCORE_NAME_SEVENTH;
		static const sf::String STR_PLACEMENT_NAME_EIGHT;
		static const int STR_SCORE_NAME_EIGHT;
		static const sf::String STR_PLACEMENT_NAME_NINTH;
		static const int STR_SCORE_NAME_NINTH;
		static const sf::String STR_PLACEMENT_NAME_TENTH;
		static const int STR_SCORE_NAME_TENTH;
		static const sf::String STR_BACK;

		Game& m_game;
		ResourcesManager& m_resources;		

		std::vector<sf::Text> highscoreItems;
		
		void InitializeHighscoreItems();
		void SetHighscoreItemsPosition();
		void HandleMouseClick(sf::Event::MouseButtonEvent const& event);
	};
}

#endif // ULDERICO_ALPHA_HIGHSCORE_BEHAVIOUR_H_INCLUDED