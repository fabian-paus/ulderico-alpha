#ifndef RESOURCESMANAGER_H_INCLUDED
#define RESOURCESMANAGER_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <list>

namespace UldericoAlpha
{
	class ResourcesManager
	{
	public:
		ResourcesManager();

		const sf::Sprite& GetSprite(std::string const& name);

		const sf::Sound& GetSound(std::string const& name);

		const sf::Font& GetFont(std::string const& name);

	private:
		void LoadSprites();

		void LoadSounds();

		void LoadFonts();

		void LoadSprite(std::string const& name, 
			sf::Texture const& texture,
			sf::IntRect const& textureRect,
            sf::Vector2f const& scale = sf::Vector2f(1.0f, 1.0f));

		void LoadFont(std::string const& name, std::string const& path);

		void LoadSound(std::string const& name, std::string const& path);

		void RegisterSprite(std::string const& name, sf::Sprite const& resource);

		void RegisterSound(std::string const& name, sf::Sound const& resource);

		void RegisterFont(std::string const& name, sf::Font const& resource);

		void LoadTexture(sf::Texture& texture, std::string const& path);

	private:
		typedef std::map <std::string, sf::Sprite> SpriteResourceMap;
		typedef std::map <std::string, sf::Sound> SoundResourceMap;
		typedef std::map <std::string, sf::Font> FontResourceMap;

		sf::Texture m_background;
		sf::Texture m_characters;
		sf::Texture m_logo;

		std::list<sf::SoundBuffer> m_soundBuffers;

		SpriteResourceMap m_spriteResources;
		SoundResourceMap m_soundResources;
		FontResourceMap m_fontResources;
	};
}
#endif