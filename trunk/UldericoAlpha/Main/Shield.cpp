#include "Shield.h"

namespace UldericoAlpha
{
    const float Shield::WIDTH = 100.0f;
    const float Shield::HEIGHT = 50.0f;
    const float Shield::BLOCK_WIDTH = 10.0f;
    const float Shield::BLOCK_HEIGHT = 10.0f;

	Shield::Shield(float posX, float posY)
		:Element(posX, posY, WIDTH, HEIGHT)
	{
        m_fragments.reserve(BLOCK_COUNT_WIDTH * BLOCK_COUNT_HEIGHT);

		for(int y = 0; y < BLOCK_COUNT_HEIGHT; y++)
		{
            float yOffset = y * BLOCK_WIDTH;

			for(int x = 0; x < BLOCK_COUNT_WIDTH; x++)
			{
                float xOffset = x * BLOCK_WIDTH;

				ShieldFragment fragment(posX + xOffset, posY + yOffset, BLOCK_WIDTH, BLOCK_HEIGHT);
				fragment.SetSpeed(0.0f);

                if (IsFilled(x, y))
                    m_fragments.push_back(fragment);
			}	
		}
	}

	bool Shield::Impact(Element const& element)
	{
		//int depth = (element.GetBoundingBox().GetHeight() / 2) * element.GetSpeed();
		//int index = 0;

		std::vector<ShieldFragment*>::iterator it;
		for (auto fragment = m_fragments.begin(); fragment != m_fragments.end(); ++fragment)
		{
			if (!fragment->IsDestroyed())
			{
				//Überprüfen ob das Fragment in dem Element liegt
				if (fragment->IsHit(element))
				{
					//Treffer ausgewähltes Element ist das Element ganz Links und unten
					//Zerstöre notwendige Elemente
					/*index -=  el.GetBoundingBox().GetWidth() / 4;
					int topWidth = el.GetBoundingBox().GetWidth() + el.GetBoundingBox().GetWidth() / 2;
					while(depth > 0)
					{
						for(int i = 0; i < topWidth; i++)
						{
							m_shieldFragments[index + i]->Destroy();
						}
						index -= 10;
						depth--;
					}*/
					fragment->Destroy();
					//return true;
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
