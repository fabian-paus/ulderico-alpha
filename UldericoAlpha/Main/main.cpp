#include "ResourcesManager.h"

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	
	ResourcesManager rm;

	sf::Sound mainTheme = rm.GetSound("main-theme");

	// Play main theme in a loop. Space Invaders! ;)
	mainTheme.SetLoop(true);
	mainTheme.SetVolume(75.0f);
	mainTheme.Play();

	sf::Sound shoot = rm.GetSound("shoot");

	// Start the game loop
	while (window.IsOpen())
	{
		// Process events
		sf::Event event;
		while (window.PollEvent(event))
		{
			switch (event.Type)
			{
			case sf::Event::Closed:
				window.Close();
				break;

			case sf::Event::KeyPressed:
				if (event.Key.Code == sf::Keyboard::Space)
				{
					shoot.Play();
				}
				break;
			}
		}

		// Clear screen
		window.Clear();

		sf::Sprite background = rm.GetSprite("background");
		// Draw background
		window.Draw(background);

		// Update the window
		window.Display();
	}

	return EXIT_SUCCESS;
}