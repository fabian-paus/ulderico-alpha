#ifndef ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED

#include "Behaviour.h"
#include "Game.h"
#include "ResourcesManager.h"

namespace UldericoAlpha
{
	/**
	 * Spielverhalten: Im Spiel.
	 */
	class InGameBehaviour : public Behaviour
	{
	public:
		InGameBehaviour(Game& game, ResourcesManager& resources);
		/**
		 * Diese Methode wird vom Spiel in jedem Logik-Tick aufgerufen.
		 */
		virtual void Update();

		/**
		 * Bei einem Ereignis (Tastatur, Maus) wird diese Methode aufgerufen.
		 */
		virtual void OnEvent(sf::Event const& event);

		/**
		* Zeichnet das für das Spiel relevante Daten
		*/
		virtual void Render(sf::RenderWindow& window);

		/**
		* Gibt den Status der Klasse zurück
		*/
		virtual GameStates GetState() const { return GameState_Game; };
	
	private:
		Game& m_game;
		ResourcesManager& m_resources;
	};
}

#endif // ULDERICO_ALPHA_IN_GAME_BEHAVIOUR_H_INCLUDED
