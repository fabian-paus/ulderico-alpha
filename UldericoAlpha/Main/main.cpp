#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	
	//Load background image
	sf::Texture texture;
	if(!texture.LoadFromFile(""))
		return EXIT_FAILURE;

	//Load background music
	sf::Music bgMusic;
	if(!bgMusic.OpenFromFile(""))
		return EXIT_FAILURE;
	//Play background music
	bgMusic.Play();

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
		}

		// Clear screen
		window.Clear();

		// Update the window
		window.Display();
	}

	return EXIT_SUCCESS;
}