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
	private:
		static const int m_width = 100;

		static const int m_height = 50;

		static const int m_block_width = 1;

		static const int m_block_height = 1;

		std::vector<ShieldFragment*> m_shieldFragments;

		BoundingBox m_boundingBox;
	public:
		/**
		* Konstruktur zur Erstellung mit allen Ausmaßen und Position
		*/
		Shield(int posX, int posY);

		/**
		* Wird aufgerufen wenn ein Element mit der Boundingbox
		* kollidiert ist. Bekommt den Ort der Kollision
		* übergeben. Wenn keine Kollision passiert wird false
		* zurückgegeben.
		*/
		virtual bool Impact(Element const& el);

		virtual ElementTypes GetType() { return ElementType_Shield; };

		/**
		* Gibt das Fragment an der übergebenen
		* Indexstelle zurück
		*/
		ShieldFragment* GetShieldFragment(int index) const { return m_shieldFragments.at(index); };

		int Count() { return m_shieldFragments.size(); };
	};
}

#endif //ULDERICO_ALPHA_SHIELD_H_INCLUDED