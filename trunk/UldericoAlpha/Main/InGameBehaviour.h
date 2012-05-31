#ifndef ULDERICO_ALPHA_IN_GAME_STATE_H_INCLUDED
#define ULDERICO_ALPHA_IN_GAME_STATE_H_INCLUDED

#include "Behaviour.h"

namespace UldericoAlpha
{
	/**
	 * Spielverhalten: Im Spiel.
	 */
	class InGameBehaviour : public Behaviour
	{
	public:
		/**
		 * Diese Methode wird vom Spiel in jedem Logik-Tick aufgerufen.
		 */
		virtual void Update();

		/**
		 * Bei einem Ereignis (Tastatur, Maus) wird diese Methode aufgerufen.
		 */
		virtual void OnEvent(sf::Event const& event);
	};
}

#endif // ULDERICO_ALPHA_IN_GAME_STATE_H_INCLUDED
