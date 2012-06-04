#ifndef ULDERICO_ALPHA_BULLET_H_INCLUDED
#define ULDERICO_ALPHA_BULLET_H_INCLUDED

#include "Element.h"
#include "ElementTypes.h"

namespace UldericoAlpha
{
	class Bullet : public Element
	{
	public:
		Bullet(float posX, float posY, float speed);

		virtual ElementTypes GetType() { return ElementType_Bullet; };
        
    private:
		static const float WIDTH;

		static const float HEIGHT;
	};
}

#endif //ULDERICO_ALPHA_BULLET_H_INCLUDED