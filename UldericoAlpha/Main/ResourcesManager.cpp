#include "ResourcesManager.h"

#include <iostream>

static const char* const CHARACTERS_IMAGE = "res/img/characters.png";
static const char* const BACKGROUND_IMAGE = "res/img/invaders.png";

static const char* const MAIN_THEME_SOUND    = "res/sound/spaceinvaders1.wav";
static const char* const SHOOT_SOUND         = "res/sound/shoot.wav";
static const char* const KILLED_SOUND        = "res/sound/invaderkilled.wav";
static const char* const EXPLOSION_SOUND     = "res/sound/explosion.wav";
static const char* const UFO_LOWPITCH_SOUND  = "res/sound/ufo_lowpitch.wav";
static const char* const UFO_HIGHPITCH_SOUND = "res/sound/ufo_highpitch.wav";

ResourcesManager::ResourcesManager()
{
	LoadTexture(m_background, BACKGROUND_IMAGE);
	LoadTexture(m_characters, CHARACTERS_IMAGE);

	LoadSprites();
	LoadSounds();
}

const sf::Sprite& ResourcesManager::GetSprite(std::string const & name)
{
	return m_spriteResources[name];
}

const sf::Sound& ResourcesManager::GetSound(std::string const & name)
{
	return m_soundResources[name];
}

void ResourcesManager::LoadSprites()
{
	RegisterSprite("background", sf::Sprite(m_background));

	LoadSprite("green-invader", m_characters, sf::IntRect(0, 0, 82, 86));
	LoadSprite("blue-invader", m_characters, sf::IntRect(112, 0, 116, 86));
	LoadSprite("purple-invader", m_characters, sf::IntRect(250, 0, 122, 86));
	LoadSprite("red-defender", m_characters, sf::IntRect(31, 303, 117, 70));

	LoadSprite("green-attack", m_characters, sf::IntRect(22, 122, 30, 60));
	LoadSprite("blue-attack", m_characters, sf::IntRect(152, 122, 28, 50));
	LoadSprite("purple-attack", m_characters, sf::IntRect(290, 122, 28, 50));
	LoadSprite("red-attack", m_characters, sf::IntRect(84, 222, 13, 45));
}

void ResourcesManager::LoadSounds()
{
	LoadSound("main-theme", MAIN_THEME_SOUND);
	LoadSound("shoot", SHOOT_SOUND);
	LoadSound("killed", KILLED_SOUND);
	LoadSound("explosion", EXPLOSION_SOUND);
	LoadSound("ufo-lowpitch", UFO_LOWPITCH_SOUND);
	LoadSound("ufo-highpitch", UFO_HIGHPITCH_SOUND);
}

void ResourcesManager::LoadSprite(std::string const& name, 
		sf::Texture const& texture,
		sf::IntRect const& textureRect)
{
	sf::Sprite sprite(texture);
	sprite.SetTextureRect(textureRect);

	RegisterSprite(name, sprite);
}

void ResourcesManager::LoadSound(std::string const& name, 
								 std::string const& path)
{
	// Add new sound buffer
	m_soundBuffers.push_back(sf::SoundBuffer());
	sf::SoundBuffer& buffer = m_soundBuffers.back();

	if (!buffer.LoadFromFile(path))
	{
		std::cerr << "Could not load sound resource '" << name 
			<< "' from file '" << path << "'" << std::endl;
		return;
	}

	RegisterSound(name, sf::Sound(buffer));
}

void ResourcesManager::RegisterSprite(std::string const & name, sf::Sprite const& resource)
{
	m_spriteResources.insert(std::make_pair(name, resource));
}

void ResourcesManager::RegisterSound(std::string const & name, sf::Sound const& resource)
{
	m_soundResources.insert(std::make_pair(name, resource));
}

void ResourcesManager::LoadTexture(sf::Texture& texture, std::string const& path)
{
	if (!texture.LoadFromFile(path))
	{
		std::cerr << "Could not load texture from file '"	
			<< path << "'" << std::endl;
	}
}