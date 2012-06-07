#include "Invader.h"

namespace UldericoAlpha
{	
    static const Vector2D INVADER_SIZE(123.0f * 0.4f, 87.0f * 0.4f);

	Invader::Invader(InvaderType type)
		: Object(Vector2D::ZERO, INVADER_SIZE),
	  m_type(type)
	{ }
}