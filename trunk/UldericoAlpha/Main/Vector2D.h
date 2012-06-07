#ifndef ULDERICO_ALPHA_VECTOR_2D_H_INCLUDED
#define ULDERICO_ALPHA_VECTOR_2D_H_INCLUDED

namespace UldericoAlpha
{
	/**
	 * Ein zweidimensionaler Vektor zur Darstellung von Punkten,
     * Geschwindigkeiten und Größen.
	 */
	class Vector2D
    {
    public:
        static const Vector2D ZERO;

        /**
         * Erstellt einen zweidimensionalen Vektor mit den
         * gegebenen Koordinaten.
         */
        explicit Vector2D(float x = 0.0f, float y = 0.0f);

        /**
         * Gibt die x-Koordinate des Vektors zurück.
         */
        float GetX() const { return m_x; }

        /**
         * Gibt die y-Koordinate des Vektors zurück.
         */
        float GetY() const { return m_y; }

        /**
         * Addiert einen anderen Vektor zu diesem hinzu.
         */
        Vector2D& operator += (Vector2D const& other);

        /**
         * Subtrahiert einen anderen Vektor von diesem.
         */
        Vector2D& operator -= (Vector2D const& other);

        /**
         * Multipliziert diesen Vektor mit einem Skalar.
         */
        Vector2D& operator *= (float factor);

		bool operator != (Vector2D const& other);

		bool operator == (Vector2D const& other);

    private:
        float m_x;
        float m_y;
    };

    /**
     * Addiert zwei Vektoren.
     */
    Vector2D operator + (Vector2D left, Vector2D const& right);

    /**
     * Subtrahiert zwei Vektoren.
     */
    Vector2D operator - (Vector2D left, Vector2D const& right);

    /**
     * Multipliziert einen Vektor mit einem Skalar.
     */
    Vector2D operator * (Vector2D left, float factor);

    /**
     * Multipliziert einen Vektor mit einem Skalar.
     */
    Vector2D operator * (float factor, Vector2D right);
}

#endif // ULDERICO_ALPHA_VECTOR_2D_H_INCLUDED