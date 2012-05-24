#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Level.h"
#include "Player.h"
#include "Bullet.h"

enum GameState 
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
	GameState state;
	Bullet *bullets;
	Player player;
	void draw();
public:
	Game(void);
	~Game(void);
	void Start();
	void Pause();
	void Update();
   GameState GetState() { return state; };
};

#endif