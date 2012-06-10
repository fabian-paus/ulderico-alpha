#ifndef ULDERICO_ALPHA_BOUNDING_BOX_H_INCLUDED
#define ULDERICO_ALPHA_BOUNDING_BOX_H_INCLUDED

#include "Vector2D.h"

#include "Object.h"
#include "BoundingBoxAction.h"

namespace UldericoAlpha
{
	class BoundingBox
	{
	public:
		BoundingBox();

		BoundingBox(Vector2D size, Vector2D position);

		Vector2D GetSize() const { return m_size; };

		Vector2D GetPosition() const { return m_position; };

		BoundingBoxAction InBoundingBox(Object const& object);

	private:
		Vector2D m_size;
		Vector2D m_position;
	};
}

#endif //ULDERICO_ALPHA_BOUNDING_BOX_H_INCLUDED