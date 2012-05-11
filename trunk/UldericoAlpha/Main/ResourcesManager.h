#ifndef RESOURCESMANAGER_H_INCLUDED
#define RESOURCESMANAGER_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <list>


class ResourcesManager
{
public:
	ResourcesManager();

	const sf::Sprite& GetSprite(std::string const & name);

	const sf::Sound& GetSound(std::string const & name);

private:
	void RegisterSprite(std::string const & name, sf::Sprite resource);

	void RegisterSound(std::string const & name, sf::Sound resource);

	void LoadImages();

	void LoadSounds();

	void LoadSound(std::string const& name, std::string const& path);

private:
	typedef std::map <std::string, sf::Sprite> SpriteResourceMap;
	typedef std::map <std::string, sf::Sound> SoundResourceMap;

	sf::Texture m_background;
	sf::Texture m_character;

	std::list<sf::SoundBuffer> m_soundBuffers;

	SpriteResourceMap m_spriteResources;
	SoundResourceMap m_soundResources;
};

#endif