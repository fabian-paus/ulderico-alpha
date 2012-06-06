#ifndef ULDERICO_ALPHA_BULLET_H_INCLUDED
#define ULDERICO_ALPHA_BULLET_H_INCLUDED

#include "Object.h"

namespace UldericoAlpha
{
	class Bullet : public Object
	{
	public:
        static const float WIDTH;
        static const float HEIGHT;

		Bullet(Vector2D const& position,
               Vector2D const& speed);
	};
}

#endif //ULDERICO_ALPHA_BULLET_H_INCLUDED