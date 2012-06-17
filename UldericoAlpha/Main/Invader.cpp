#include "Invader.h"

namespace UldericoAlpha
{	
    static const Vector2D INVADER_SIZE(123.0f * 0.4f, 87.0f * 0.4f);

	Invader::Invader(InvaderType type)
		: Object(Vector2D::ZERO, INVADER_SIZE),
		m_type(type),
		m_alive(true)
	{ }

	int Invader::GetScore() const
	{
		switch (m_type)
		{
			case InvaderType_Purple: return 10;
			case InvaderType_Blue: return 20;
			case InvaderType_Green: return 30;
			case InvaderType_MotherShip: return 100;
		}
		return 0;
	}
}