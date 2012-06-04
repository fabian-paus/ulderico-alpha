#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Element.h"
#include "ElementTypes.h"

namespace UldericoAlpha
{
	class Player : public Element
	{
	private:
		int points;
		int lifes;
        float m_speedX;
	public:
		int GetPoints();
		void AddPoints(int points);
		int GetLifes() { return lifes; };
		void LoseLife(){ lifes--; };
		void Shot();

        void SetSpeedX(float speed)
        {
            m_speedX = speed;
        }

        void Move()
        {
            Element::SetPosition(Element::GetX() + m_speedX, Element::GetY());
        }

		virtual ElementTypes GetType() { return ElementType_Player; };
	};
}
#endif