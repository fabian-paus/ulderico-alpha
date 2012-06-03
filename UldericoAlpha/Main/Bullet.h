#ifndef ULDERICO_ALPHA_BULLET_H_INCLUDED
#define ULDERICO_ALPHA_BULLET_H_INCLUDED

#include "Element.h"
#include "ElementTypes.h"

namespace UldericoAlpha
{
	class Bullet : public Element
	{
	private:
		static const int m_width = 5;

		static const int m_height = 8;
	public:
		Bullet(int posX, int posY, int speed);

		virtual ElementTypes GetType() { return ElementType_Bullet; };
	};
}

#endif //ULDERICO_ALPHA_BULLET_H_INCLUDED