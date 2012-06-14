#include "BulletType.h"

#include <cassert>

namespace UldericoAlpha
{
	BulletType GetBulletFrom(InvaderType invader)
	{
		switch (invader)
		{
		case InvaderType_Green: return Bullet_Green;
		case InvaderType_Blue: return Bullet_Blue;
		case InvaderType_Purple: return Bullet_Purple;

		default:
			assert(false);
			return Bullet_Player;
		}
	}
}
