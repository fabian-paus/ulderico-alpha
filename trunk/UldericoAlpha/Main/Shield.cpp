#include "Shield.h"

namespace UldericoAlpha
{
    const float Shield::BLOCK_WIDTH = 10.0f;
    const float Shield::BLOCK_HEIGHT = 10.0f;
    
    static const Vector2D SHIELD_SIZE(100.0f, 50.0f);

	Shield::Shield(float positionX, float positionY)
		: Object(Vector2D(positionX, positionY), SHIELD_SIZE)
	{
        for(int y = 0; y < BLOCK_COUNT_HEIGHT; y++)
		{
            for(int x = 0; x < BLOCK_COUNT_WIDTH; x++)
			{
                m_fragments[y][x] = IsFilled(x, y);
            } 
        }
	}

    bool Shield::FragmentExists(int positionX, int positionY) const
    {
        return m_fragments[positionY][positionX];
    }

    bool Shield::DetectCollision(Object const& other)
    {
        const Vector2D BLOCK_SIZE(BLOCK_WIDTH, BLOCK_HEIGHT);

		for(int y = 0; y < BLOCK_COUNT_HEIGHT; y++)
		{
            for(int x = 0; x < BLOCK_COUNT_WIDTH; x++)
			{
                if (FragmentExists(x, y))
                {
                    Vector2D delta(x * Shield::BLOCK_WIDTH, y * Shield::BLOCK_HEIGHT);
                    Vector2D position = GetPosition() + delta;

                    Object fragment(position, BLOCK_SIZE, Vector2D::ZERO);
                    
                    // Überprüfen ob das Fragment in dem anderen Objekt liegt
                    if (fragment.CollidesWith(other))
                    {
                        m_fragments[y][x] = false;
                        return true;
                    }
                }
			}
		}
		return false;
    }

    bool Shield::IsFilled(int xPosition, int yPosition)
    {
        /**
         * Hier wird der Aufbau der Shilde festgelegt.
         * Ein Shild ist in einem Raster (10 x 5) aufgebaut.
         *  - 1: Solides Feld
         *  - 0: Leeres Feld
         */
        static const bool FILLED[BLOCK_COUNT_HEIGHT][BLOCK_COUNT_WIDTH] =
        { 
            { 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
            { 1, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
        };

        return FILLED[yPosition][xPosition];
    }
}
