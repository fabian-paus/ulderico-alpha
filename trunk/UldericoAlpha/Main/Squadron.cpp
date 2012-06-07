#include "Squadron.h"

namespace UldericoAlpha
{	
    static const Vector2D SQUADRON_SIZE(123.0f * 0.4f, 87.0f * 0.4f);

	Squadron::Squadron()
    : Object(Vector2D::ZERO, SQUADRON_SIZE)
	{ 
		m_invaders.reserve(30);

		for(int j = 0; j < 3; j++)
		{
			for(int i = 0; i < 10; i++)
			{
				Invader invader((InvaderType)j);
				invader.SetPosition(Vector2D(invader.GetSize().GetX() * j, invader.GetSize().GetY() * i));
				m_invaders.push_back(invader);
			}
		}
	}

	void Squadron::Update()
	{
	}
}