#include "Bullet.h"

namespace UldericoAlpha
{
    const float Bullet::WIDTH = 13.0f * 0.4f;
    const float Bullet::HEIGHT = 45.0f * 0.4f;

    static const Vector2D BULLET_SIZE(Bullet::WIDTH, Bullet::HEIGHT);

	Bullet::Bullet(Vector2D const& position,
                   Vector2D const& speed)
		: Object(position, BULLET_SIZE, speed)
    { }
}
