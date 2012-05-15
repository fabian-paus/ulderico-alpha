#include "Game.h"

using namespace UldericoAlpha::Core;

Game::Game() : window(sf::VideoMode(775, 572), "SFML window")
{
	state = loading;
	activLevel = 1;
	bullets = 0;
	levels = 0;
}


Game::~Game()
{
}

void Game::Load()
{
	window.SetFramerateLimit(60);

	//getting main theme
	sf::Sound mainTheme = rm.GetSound("main-theme");

	//Play main theme in a loop. Space Invaders! ;)
	mainTheme.SetLoop(true);
	mainTheme.SetVolume(75.0f);
	mainTheme.Play();

	draw();
}

void Game::StartGameLoop()
{
	// Start the game loop
	while (window.IsOpen())
	{
		// Process events
		sf::Event event;
		while (window.PollEvent(event))
		{
			// Close window : exit
			if (event.Type == sf::Event::Closed)
				window.Close();

			if(event.Type == sf::Event::KeyPressed)
			{
				if (event.Key.Code == sf::Keyboard::Space)
					player.Shot(); //shoot.Play();
				if(event.Key.Control && event.Key.Code == 15)
					pause();

			}
			if(event.Type == sf::Event::MouseButtonPressed)
			{
				if(event.MouseButton.X >= 250 && event.MouseButton.X <= 450 && event.MouseButton.Y >= 300 && event.MouseButton.Y <= 350)
				{
					if(state == started)
						start();
					if(state == paused)
						state = playing;
				}
			}
		}

		// Clear screen
		window.Clear();

		//Update the game
		update();

		// Update the window
		window.Display();
	}
}

void Game::start()
{
	state = playing;
	//initialize player, shields, invaders & draw
}

void Game::pause()
{
	state = paused;
	//draw pause screen
}

void Game::update()
{
	if(state == loading)
		state = started;
	//call update für invaders, player etc.
	draw();
}

void Game::draw()
{
	sf::Sprite background = rm.GetSprite("background");
	// Draw background
	window.Draw(background);

	switch(state)
	{
	case loading:
		{
			//paint loading
			sf::Text loading("Laden", rm.GetFont("game-font"));
			loading.SetPosition(250.0, 300.0);
			window.Draw(loading);
			break;
		}
	case started:
		{
			sf::Sprite logo = rm.GetSprite("logo");
			logo.SetPosition(250.0, 150.0);

			sf::Text StartGame("Spiel starten", rm.GetFont("game-font"));
			StartGame.SetPosition(250.0, 300.0);
			window.Draw(logo);
			window.Draw(StartGame);
			break;
		}
	case playing:
		break;
	case paused:
		{
			sf::Text loading("Spiel fortsetzen", rm.GetFont("game-font"));
			loading.SetPosition(250.0, 300.0);
			window.Draw(loading);
			break;
		}
	case gameOver:
		{
			sf::Text loading("Game Over", rm.GetFont("game-font"));
			loading.SetPosition(250.0, 300.0);
			window.Draw(loading);
			break;
		}
	default:
		break;
	}
}