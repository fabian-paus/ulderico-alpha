#include "Game.h"


Game::Game(void)
{
	activLevel = 1;
	bullets = 0;
	levels = 0;
	state = start;
}


Game::~Game(void)
{
}

void Game::Start()
{
}

void Game::Pause()
{
}

void Game::Update()
{
	draw();
}

void Game::draw()
{

}