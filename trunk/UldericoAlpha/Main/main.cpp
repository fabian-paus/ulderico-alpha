#include "ResourcesManager.h"
#include "Game.h"

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

	sf::Sound shoot = rm.GetSound("shoot");

	uldericoAlpha.Start();

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
		}

		// Clear screen
		window.Clear();

		sf::Sprite background = rm.GetSprite("background");
		// Draw background
		window.Draw(background);

		uldericoAlpha.Update();

		// Update the window
		window.Display();
	}

	return EXIT_SUCCESS;
}