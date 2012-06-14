#ifndef ULDERICO_ALPHA_LEVEL_H_INCLUDED
#define ULDERICO_ALPHA_LEVEL_H_INCLUDED

namespace UldericoAlpha
{
	/**
	 * Die Level in Ulderico Alpha unterscheiden sich in der Geschwindigkeit
	 * der Gegner und der Häufigkeit, mit der auf den Spieler geschossen wird.
	 */
	class Level
	{
	public:
		/**
		 * Erstellt ein Level mit gegebener Geschwindigkeit und 
		 * Schusswahrscheinlichkeit.
		 */
		Level(float absoluteSpeed, float shootChance);

		/**
		 * Gibt die Geschwindigkeit der Gegner zurück.
		 */
		float GetAbsoluteSpeed() const { return m_absoluteSpeed; }

		/**
		 * Gibt die Schusswahrscheinlichkeit der Gegner zurück.
		 */
		float GetShootChance() const { return m_shootChance; }

	private:
		float m_absoluteSpeed;
		float m_shootChance;
	};
}

#endif // ULDERICO_ALPHA_LEVEL_H_INCLUDED
