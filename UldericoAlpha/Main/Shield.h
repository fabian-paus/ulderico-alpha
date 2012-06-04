#ifndef ULDERICO_ALPHA_SHIELD_H_INCLUDED
#define ULDERICO_ALPHA_SHIELD_H_INCLUDED

#include <vector>

#include "Element.h"
#include "ElementTypes.h"
#include "ShieldFragment.h"

namespace UldericoAlpha
{
	/**
	* Klasse des Schutzschilds mit integriertem Schadensmodell
	*/
	class Shield : public Element
	{
	public:
        static const float BLOCK_WIDTH;

		static const float BLOCK_HEIGHT;

		/**
		* Konstruktur zur Erstellung mit allen Ausma�en und Position
		*/
		Shield(float posX, float posY);

		/**
		* Wird aufgerufen wenn ein Element mit der Boundingbox
		* kollidiert ist. Bekommt den Ort der Kollision
		* �bergeben. Wenn keine Kollision passiert wird false
		* zur�ckgegeben.
		*/
		virtual bool Impact(Element const& element);

		virtual ElementTypes GetType() { return ElementType_Shield; };

		/**
		* Gibt das Fragment an der �bergebenen
		* Indexstelle zur�ck
		*/
		ShieldFragment const* GetShieldFragment(int index) const { return &m_fragments[index]; };

		int GetCount() { return m_fragments.size(); };

    private:
        static bool IsFilled(int xPosition, int yPosition);
        
    private:
		static const float WIDTH;
		static const float HEIGHT;

        static const int BLOCK_COUNT_WIDTH = 10;
        static const int BLOCK_COUNT_HEIGHT = 5;

		std::vector<ShieldFragment> m_fragments;

		BoundingBox m_boundingBox;
	};
}

#endif //ULDERICO_ALPHA_SHIELD_H_INCLUDED