#ifndef ULDERICO_ALPHA_SHIELDFRAGMENT_H_INCLUDED
#define ULDERICO_ALPHA_SHIELDFRAGMENT_H_INCLUDED

#include "Element.h"
#include "ElementTypes.h"

namespace UldericoAlpha
{
	/**
	* Klasse zur Definition eines Elements des Schilds
	*/
	class ShieldFragment : public Element
	{
	private:
		bool m_destroyed;
	public:
		ShieldFragment() : m_destroyed(false) {};

		ShieldFragment(int posX, int posY, int width, int height) 
			: m_destroyed(false), Element(posX, posY, width, height) {};

		/**
		* Überschreibt die rein virtuelle Funktion
		* der Klasse Element
		*/
		virtual ElementTypes GetType() { return ElementType_ShieldFragment; };

		/**
		* Getter für die destroyed Variable
		*/
		int IsDestroyed() const { return m_destroyed; }; 

		/**
		* Zerstört ein Schild Fragment
		*/
		void Destroy() { m_destroyed = true; };
	};
}

#endif //ULDERICO_ALPHA_SHIELDFRAGMENT_H_INCLUDED
