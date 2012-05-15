#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <boost\signals2.hpp>

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

class Game : public sf::RenderWindow
{
private:
	Level *levels;
	int activLevel;
	GameState state;
	Bullet *bullets;
	Player player;
	ResourcesManager rm;
	sf::RenderWindow window;
	void gameLoop();
	void draw();
public:
	Game();
	~Game(void);
	void Start();
	void Pause();
	void Update();
	void OnKeyDown(sf::Event event);
	void OnMouseButtonPressed(sf::Event event);
};

#endif