#include "Object.h"

#include <cmath>

namespace UldericoAlpha
{
    Object::Object(
        Vector2D const& position,
        Vector2D const& size,
        Vector2D const& speed)
        : m_position(position),
          m_size(size),
          m_speed(speed)
    { }

    Vector2D Object::PredictPosition(float interpolation) const
    {
        Vector2D predictedPosition = GetPosition();

        predictedPosition += GetSpeed() * interpolation;

        return predictedPosition;
    }

    void Object::Update()
    {
        m_position += GetSpeed();
    }

    bool Object::CollidesWith(Object const& other)
    {
        // Abstand zwischen den beiden Positionen
        Vector2D positionDelta = GetPosition() - other.GetPosition();

        float deltaX = std::fabs(positionDelta.GetX());
        float deltaY = std::fabs(positionDelta.GetY());

		// Höhe des weiter oben gelegenen Elements
        float height = GetSize().GetY();
        if (GetPosition().GetY() > other.GetPosition().GetY())
            height = other.GetSize().GetY();

		// Breite des weiter links gelegenen Elements
        float width = GetSize().GetX();
        if (GetPosition().GetX() > other.GetPosition().GetX())
            width = other.GetSize().GetX();

		// Bestimmung, ob die Elemente überlappen
		if (deltaX < width && deltaY < height)
            return DetectCollision(other);

        return false;
    }
}
