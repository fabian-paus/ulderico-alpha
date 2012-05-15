#include "Game.h"

Game::Game() : window(sf::VideoMode(775, 572), "SFML window")
{
	state = loading;
	activLevel = 1;
	bullets = 0;
	levels = 0;
	window.SetFramerateLimit(60);

	//getting main theme
	sf::Sound mainTheme = rm.GetSound("main-theme");

	//Play main theme in a loop. Space Invaders! ;)
	mainTheme.SetLoop(true);
	mainTheme.SetVolume(75.0f);
	mainTheme.Play();

	//paint loading
	sf::Text loading("Laden", rm.GetFont("game-font"));
	loading.SetPosition(250.0, 300.0);
	window.Draw(loading);
}


Game::~Game()
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
	if(state == loading)
		state = start;
	draw();
}

void Game::draw()
{
	sf::Sprite background = rm.GetSprite("background");
	// Draw background
	//window.Draw(background);

	if(state == start)
	{
		//window.Draw(rm.GetSprite("logo"));
		//window.Draw(StartGame);
	}
}

void Game::OnKeyDown(sf::Event event)
{
}

void Game::OnMouseButtonPressed(sf::Event event)
{

}