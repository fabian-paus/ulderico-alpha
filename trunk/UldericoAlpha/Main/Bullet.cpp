#include "Bullet.h"

namespace UldericoAlpha
{

	Bullet::Bullet(int posX, int posY, int speed)
		:Element(posX, posY, m_width, m_height)
	{	
		SetSpeed(speed);
	}

}