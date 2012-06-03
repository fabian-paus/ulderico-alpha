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
	public:
		int GetPoints();
		void AddPoints(int points);
		void SetPosition(int x, int y);
		int GetLifes() { return lifes; };
		void LoseLife(){ lifes--; };
		void Shot();
		virtual ElementTypes GetType() { return ElementType_Player; };
	};
}
#endif