#ifndef ULDERICO_ALPHA_MENU_STATE_H_INCLUDED
#define ULDERICO_ALPHA_MENU_STATE_H_INCLUDED

#include "Game.h"
#include "Behaviour.h"
#include "ResourcesManager.h"

namespace UldericoAlpha
{
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
		virtual void Render(sf::RenderWindow& window);

		/**
		 * Gibt den Zustand des Programms zurück.
		 */
		virtual GameStates GetState() const
		{
			return GameState_Menu;
		}

	private:
		Game& m_game;
		ResourcesManager& m_resources;
	};
}

#endif // ULDERICO_ALPHA_MENU_STATE_H_INCLUDED
