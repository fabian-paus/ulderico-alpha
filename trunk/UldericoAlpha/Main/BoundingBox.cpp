#include "BoundingBox.h"

namespace UldericoAlpha
{
	BoundingBox::BoundingBox()
		:m_size(Vector2D::ZERO),
		m_position(Vector2D::ZERO)
	{}

	BoundingBox::BoundingBox(Vector2D size, Vector2D position)
		: m_size(size),
		  m_position(position)
	{}

	BoundingBoxAction BoundingBox::InBoundingBox(Object const& object)
	{
		Vector2D objectPosition = object.PredictPosition(2.0f);
		Vector2D objectSize = object.GetSize();

		//Links raus
		if(objectPosition.GetX() < m_position.GetX())
			return BoundingBoxAction_CollisionLeft;

		//Rechts raus
		if(objectPosition.GetX() + objectSize.GetX() > m_position.GetX() + m_size.GetX())
			return BoundingBoxAction_CollisionRight;

		//Oben raus
		if(objectPosition.GetY() < m_position.GetY())
			return BoundingBoxAction_CollisionTop;

		//Unten raus
		if(objectPosition.GetY() + objectSize.GetY() > m_position.GetY() + m_size.GetY())
			return BoundingBoxAction_CollisionBottom;

		return BoundingBoxAction_Move;
	}
}