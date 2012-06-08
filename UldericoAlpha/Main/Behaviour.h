#ifndef ULDERICO_ALPHA_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_BEHAVIOUR_H_INCLUDED

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace UldericoAlpha
{
	/**
	 * Abstrakte Basisklasse für Spielverhalten.
	 */
	class Behaviour
	{
	public:
		/**
		 * Diese Methode wird vom Spiel in jedem Logik-Tick aufgerufen.
		 */
		virtual void Update() = 0;

		/**
		 * Bei einem Ereignis (Tastatur, Maus) wird diese Methode aufgerufen.
		 */
		virtual void OnEvent(sf::Event const& event) = 0;

		/**
		 * Wenn der Zustand dargestellt werden soll, wird diese Methode aufgerufen.
		 */
		virtual void Render(sf::RenderTarget& target, float interpolation) = 0;
	};
}

#endif // ULDERICO_ALPHA_BEHAVIOUR_H_INCLUDED
