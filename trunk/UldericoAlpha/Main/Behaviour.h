#ifndef ULDERICO_ALPHA_BEHAVIOUR_H_INCLUDED
#define ULDERICO_ALPHA_BEHAVIOUR_H_INCLUDED

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameStates.h"

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
		virtual void Render(sf::RenderWindow& window) = 0;

		/**
		 * Gibt den Zustand des Programms zurück.
		 */
		virtual GameStates GetState() const = 0;
	};
}

#endif // ULDERICO_ALPHA_BEHAVIOUR_H_INCLUDED
