#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Element.h"

class Player : public Element
{
private:
	int points;
	int lifes;
public:
	Player(void);
	~Player(void);
	int GetPoints();
	void AddPoints(int points);
	void SetPosition(int x, int y);
	int GetLifes() { return lifes; };
	void LoseLife(){ lifes--; };
	void Shot();
	const char* GetType() { return "red-defender"; };
};

#endif