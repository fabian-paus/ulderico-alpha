#ifndef ULDERICO_ALPHA_ELEMENT_H_INCLUDED
#define ULDERICO_ALPHA_ELEMENT_H_INCLUDED

#include "BoundingBox.h"
#include "ElementTypes.h"

namespace UldericoAlpha
{
	/**
	* Abstrakte Klasse für alle Spielelemente
	*/
	class Element
	{
	private:
		float m_posX;

		float m_posY;

		float m_speed;

		BoundingBox m_boundingBox;

	public:
		/**
		* Standardkonstrukur
		*/
		Element();

		/**
		* Konstruktur bei dem eine Element
		* an Position 0,0 mit einer bestimmten
		* Höhe und Breite erzeugt wird
		*/
		Element(float width, float height);

		/**
		* Konstruktur, welcher Position und Ausmaße
		* initialisiert
		*/
		Element (float posX, float posY, float width, float height);

		/**
		* Setter um die Position eines 
		* Elements zu setzen
		*/
		void SetPosition(float const x, float const y);

		/**
		* Setter für den Speed-Member
		*/
		void SetSpeed(float const speed) { m_speed = speed; };

		/**
		* Getter für die X-Koordinate
		*/
		float GetX() const { return m_posX; };

		/**
		* Getter für die Y-Koordinate
		*/
		float GetY() const { return m_posY; };
		
		float GetSpeed() const { return m_speed; };

		/**
		* Getter für die Boundingbox
		*/
		BoundingBox GetBoundingBox() const { return m_boundingBox; };

		/**
		* Gibt zurück, ob das übergebene Element
		* in der Bounding Box des Elements liegt
		*/
		bool IsHit(Element const &el);

		/**
		* Wird aufgerufen wenn ein Element getroffen wurde
		*/
		virtual bool Impact(Element const& el) { return true; };

		/**
		* Funktion, welche den Typ des Elements
		* zurückgibt um das Element zu zeichnen
		*/
		virtual ElementTypes GetType() = 0;
	};
}
#endif //ULDERICO_ALPHA_ELEMENT_H_INCLUDED