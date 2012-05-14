#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Level.h"
#include "Player.h"
#include "Bullet.h"

enum GameStates 
{
	start,
   playing,
	paused,
	gameOver
};

class Game
{
private:
	Level *levels;
	int activLevel;
	GameStates state;
	Bullet *bullets;
	Player player;
	void draw();
public:
	Game(void);
	~Game(void);
	void Start();
	void Pause();
	void Update();
   GameStates GetState() { return state; };
};

#endif