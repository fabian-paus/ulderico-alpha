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
   state = playing;
   //initialize player, shields, invaders & draw
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