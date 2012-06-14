#ifndef ULDERICO_ALPHA_BULLET_TYPE_H_INCLUDED
#define ULDERICO_ALPHA_BULLET_TYPE_H_INCLUDED

#include "InvaderType.h"

namespace UldericoAlpha
{
	/**
	 * Es gibt unterschiedliche Arten von Kugeln.
	 */
	enum BulletType
	{
		Bullet_Player,
		Bullet_Green,
		Bullet_Blue,
		Bullet_Purple
	};

	BulletType GetBulletFrom(InvaderType invader);
}

#endif // ULDERICO_ALPHA_BULLET_TYPE_H_INCLUDED
