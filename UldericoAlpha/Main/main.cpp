#include "ResourcesManager.h"
#include "Game.h"

#include <iostream>

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(775, 572), "SFML window");
	
   //instantiate game class
	Game uldericoAlpha;

   //instantiate resource manager
	ResourcesManager rm;

   //getting main theme
	sf::Sound mainTheme = rm.GetSound("main-theme");

	// Play main theme in a loop. Space Invaders! ;)
	mainTheme.SetLoop(true);
	mainTheme.SetVolume(75.0f);
	mainTheme.Play();

   sf::Font ca = rm.GetFont("game-font");

   sf::Sprite logo = rm.GetSprite("logo");
   logo.SetPosition(250.0, 150.0);

	sf::Sound shoot = rm.GetSound("shoot");

   sf::Text StartGame("Spiel starten", ca);
   StartGame.SetPosition(250.0, 300.0);

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
					shoot.Play();
				if(event.Key.Control && event.Key.Code == 15)
					uldericoAlpha.Pause();

			}
         if(event.Type == sf::Event::MouseButtonPressed)
         {
            if(event.MouseButton.X >= 250 && event.MouseButton.X <= 450 && event.MouseButton.Y >= 300 && event.MouseButton.Y <= 350)
            {
               uldericoAlpha.Start();
            }
         }
		}

		// Clear screen
		window.Clear();

		sf::Sprite background = rm.GetSprite("background");
		// Draw background
		window.Draw(background);

      if(uldericoAlpha.GetState() == start)
      {
         window.Draw(logo);
         window.Draw(StartGame);
      }
		uldericoAlpha.Update();

		// Update the window
		window.Display();
	}

	return EXIT_SUCCESS;
}