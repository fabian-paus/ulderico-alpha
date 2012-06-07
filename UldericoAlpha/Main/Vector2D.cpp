#include "Vector2D.h"

namespace UldericoAlpha
{
    const Vector2D Vector2D::ZERO(0.0f, 0.0f);

    Vector2D::Vector2D(float x, float y)
        : m_x(x), m_y(y)
    { }

    Vector2D& Vector2D::operator += (Vector2D const& other)
    {
        m_x += other.GetX();
        m_y += other.GetY();

        return *this;
    }

    Vector2D& Vector2D::operator -= (Vector2D const& other)
    {
        m_x -= other.GetX();
        m_y -= other.GetY();

        return *this;
    }

    Vector2D& Vector2D::operator *= (float factor)
    {
        m_x *= factor;
        m_y *= factor;

        return *this;
    }

	bool Vector2D::operator != (Vector2D const& other)
	{
		return !this->operator==(other);
	}

	bool Vector2D::operator == (Vector2D const& other)
	{
		return (m_x == other.GetX() && m_y == other.GetY());
	}

    Vector2D operator + (Vector2D left, Vector2D const& right)
    {
        return left += right;
    }

    Vector2D operator - (Vector2D left, Vector2D const& right)
    {
        return left -= right;
    }

    Vector2D operator * (Vector2D left, float factor)
    {
        return left *= factor;
    }

    Vector2D operator * (float factor, Vector2D right)
    {
        return right * factor;
    }
}
