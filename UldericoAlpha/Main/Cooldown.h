#ifndef ULDERICO_ALPHA_COOLDOWN_H_INCLUDED
#define ULDERICO_ALPHA_COOLDOWN_H_INCLUDED

namespace UldericoAlpha
{
	/**
	 * Diese Klasse stellt die Abklingzeit von Benutzeraktionen dar.
	 *
	 * Ein Spieler kann z.B. nur in gewissen Zeitabständen Schüsse abgeben.
	 * Die Wartezeit bis zum nächsten Schussmöglichkeit wird mit dieser
	 * Klasse verwaltet.
	 *
	 * Als Zeiteinheit werden Logik-Ticks verwendet.
	 */
	class Cooldown
	{
	public:
		/**
		 * Erstellt einen Cooldown mit der gegebenen Anzahl an Logik-Ticks.
		 */
		Cooldown(int timeInTicks);

		/**
		 * Der Cooldown tickt eine Logik-Einheit weiter.
		 */
		void Tick();

		/**
		 * Gibt an, ob der Cooldown bereits abgelaufen ist.
		 */
		bool IsElapsed() const;

		/**
		 * Startet den Cooldown.
		 */
		void Start();

	private:
		int m_timeInTicks;
		int m_currentTicks;
	};
}

#endif // ULDERICO_ALPHA_COOLDOWN_H_INCLUDED
