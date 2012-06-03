#ifndef ULDERICO_ALPHA_ELEMENT_H_INCLUDED
#define ULDERICO_ALPHA_ELEMENT_H_INCLUDED

#include "BoundingBox.h"
#include "ElementTypes.h"

namespace UldericoAlpha
{
	/**
	* Abstrakte Klasse f�r alle Spielelemente
	*/
	class Element
	{
	private:
		int m_posX;

		int m_posY;

		int m_speed;

		BoundingBox m_boundingBox;

	public:
		/**
		* Standardkonstrukur
		*/
		Element();

		/**
		* Konstruktur bei dem eine Element
		* an Position 0,0 mit einer bestimmten
		* H�he und Breite erzeugt wird
		*/
		Element(int width, int height);

		/**
		* Konstruktur, welcher Position und Ausma�e
		* initialisiert
		*/
		Element (int posX, int posY, int width, int height);

		/**
		* Setter um die Position eines 
		* Elements zu setzen
		*/
		void SetPosition(int const x, int const y);

		/**
		* Setter f�r den Speed-Member
		*/
		void SetSpeed(int const speed) { m_speed = speed; };

		/**
		* Getter f�r die X-Koordinate
		*/
		int GetX() const { return m_posX; };

		/**
		* Getter f�r die Y-Koordinate
		*/
		int GetY() const { return m_posY; };
		
		int GetSpeed() const { return m_speed; };

		/**
		* Getter f�r die Boundingbox
		*/
		BoundingBox GetBoundingBox() const { return m_boundingBox; };

		/**
		* Gibt zur�ck, ob das �bergebene Element
		* in der Bounding Box des Elements liegt
		*/
		bool IsHit(Element const &el);

		/**
		* Wird aufgerufen wenn ein Element getroffen wurde
		*/
		virtual bool Impact(Element const& el) { return true; };

		/**
		* Funktion, welche den Typ des Elements
		* zur�ckgibt um das Element zu zeichnen
		*/
		virtual ElementTypes GetType() = 0;
	};
}
#endif //ULDERICO_ALPHA_ELEMENT_H_INCLUDED