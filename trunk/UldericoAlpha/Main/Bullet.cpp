#include "Bullet.h"

namespace UldericoAlpha
{
    const float Bullet::WIDTH = 5.0f;
    const float Bullet::HEIGHT = 8.0f;

	Bullet::Bullet(float posX, float posY, float speed)
		:Element(posX, posY, WIDTH, HEIGHT)
	{	
		SetSpeed(speed);
	}
}