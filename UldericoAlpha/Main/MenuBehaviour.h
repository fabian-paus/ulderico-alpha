#ifndef ULDERICO_ALPHA_MENU_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_MENU_BEHAVIOUR_H_INCLUDED

#include "Behaviour.h"
#include "ResourcesManager.h"

namespace UldericoAlpha
{
    class Game;

	/**
	 * Titelbildschirm.
	 */
	class MenuBehaviour : public Behaviour
	{
	public:
		MenuBehaviour(Game& game, ResourcesManager& resources);

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
		* Margin beschreibt den Abstand zwischen den Menü-Elementen
		*/
		static const int MARGIN = 50;

		/**
		* Namen für die Menü-Elemente
		*/
		static const sf::String STR_GAME_START;
		static const sf::String STR_HIGHSCORE;
		static const sf::String STR_QUIT;
		
		Game& m_game;
		ResourcesManager& m_resources;

		sf::Font m_gameFont;
		std::vector<sf::Text> m_menuItems;
		
		void InitializeMenuItems();
		void SetMenuItemsPosition();
		void HandleMouseClick(sf::Event::MouseButtonEvent const& event);
	};
}

#endif // ULDERICO_ALPHA_MENU_BEHAVIOUR_H_INCLUDED
