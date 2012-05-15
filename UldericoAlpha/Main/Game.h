#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "ResourcesManager.h"

#include "Level.h"
#include "Player.h"
#include "Bullet.h"

enum GameState 
{
   loading,
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
   ResourcesManager rm;
	void draw();
public:
	Game();
	~Game(void);
   //sf::RenderWindow window(sf::VideoMode(775, 572), "SFML window");
	void Start();
	void Pause();
	void Update();
   GameState GetState() { return state; };
   void OnKeyDown(sf::Event event);
   void OnMouseButtonPressed(sf::Event event);
};

#endif