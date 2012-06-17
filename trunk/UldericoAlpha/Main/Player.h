#ifndef ULDERICO_ALPHA_PLAYER_H_INCLUDED
#define ULDERICO_ALPHA_PLAYER_H_INCLUDED

#include "Object.h"

namespace UldericoAlpha
{
	class Player : public Object
	{
	public:
        /**
         * Erstellt einen Spieler.
         */
        Player(int lives);

		/**
		 * Gibt die Anzahl der Leben des Spielers zur�ck.
		 */
		int GetLives() const { return m_lives; }

		/**
		 * Gibt wahr zur�ck, wenn der Spieler mindestens ein Leben hat.
		 */
		bool IsAlive() const { return GetLives() > 0; }

		/**
		 * Der Spieler gewinnt ein Leben hinzu.
		 */
		void AddLife() { ++m_lives; }

		/**
		 * Der Spieler verliert ein Leben.
		 */
		void LoseLife() { --m_lives; }

		/**
		 * Gibt den aktuellen Score des Spielers zur�ck.
		 */
		int GetScore() const { return m_score; }

		/**
		 * F�gt den Wert 'value' zum Score hinzu.
		 * (Negativer Wert zum abziehen, falls das irgendwann unterst�tzt werden soll)
		 */
		void AddToScore(int value)	{ m_score += value; }

	private:
		int m_lives;
		int m_score;
	};
}

#endif // ULDERICO_ALPHA_PLAYER_H_INCLUDED
