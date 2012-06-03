#include "Shield.h"

namespace UldericoAlpha
{
	Shield::Shield(int posX, int posY)
		:Element(posX, posY, m_width, m_height)
	{
		/**
		*  ca. 200 Elmente (20 breit x 10 hoch)
		*      [][][][][][][][][]      
		*  [][][][][][][][][][][][][]  
		*  [][][][][][][][][][][][][]  
		*  [][][][][][][][][][][][][]  
		*  [][][][][][][][][][][][][]  
		*  [][][]              [][][]  
		*  [][]                  [][]  
		*  [][]                  [][]  
		*/

		//Array mit Shield Fragmenten anlegen		
		int index = 0;
		float topSize = m_width * 4 / 5;
		float bottomSize = m_width / 10;

		std::vector<ShieldFragment*>::iterator it;
		it = m_shieldFragments.begin();

		for(int j = 0; j < m_height; j++)
		{
			for(int i = 0; i < m_width; i++)
			{
				ShieldFragment *shieldFrag = new ShieldFragment(posX + (i * m_block_width), posY + (j * m_block_height), m_block_height, m_block_width);
				shieldFrag->SetSpeed(0);

				if(topSize < m_width && (i < ((m_width - topSize) / 2) || i >= (topSize + ((m_width - topSize) / 2))))
				{
					shieldFrag->Destroy();
				}
				if(j >= (m_height - (m_height / 5)) && (i > bottomSize && i < m_width - bottomSize))
				{
					shieldFrag->Destroy();
				}
				it = m_shieldFragments.insert(it, shieldFrag);
				index++;
			}	
			if(topSize < m_width)
				topSize += 2;
		}
	}

	bool Shield::Impact(Element const& el)
	{
		int depth = (el.GetBoundingBox().GetHeight() / 2) * el.GetSpeed();
		int index = 0;

		std::vector<ShieldFragment*>::iterator it;
		for(it = m_shieldFragments.begin(); it != m_shieldFragments.end(); ++it, index++)
		{
			ShieldFragment *shieldFrag = (ShieldFragment*)*it;
			if(!shieldFrag->IsDestroyed())
			{
				//Überprüfen ob das Fragment in dem Element liegt
				if(shieldFrag->IsHit(el))
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
					shieldFrag->Destroy();
					//return true;
				}
			}
		}
		return false;
	}
}