#include "ResourcesManager.h"

static const char* const CHARACTERS_IMAGE = "res/img/characters.png";
static const char* const BACKGROUND_IMAGE = "res/img/invaders.png";

ResourcesManager::ResourcesManager()
{
	// Load all images into sprites and make them accessable by name
	if(!m_background.LoadFromFile(BACKGROUND_IMAGE) || !m_character.LoadFromFile(CHARACTERS_IMAGE))
		return;

	RegisterSprite("background", sf::Sprite(m_background));
}

void ResourcesManager::RegisterSprite(std::string const & name, sf::Sprite resource)
{
	m_spriteResources.insert(std::make_pair(name, resource));
}

//void ResourcesManager::RegisterSound(std::string const & name, sf::Sound resource)
//{
//	soundResources.insert(std::make_pair(name, resource));
//}

const sf::Sprite& ResourcesManager::GetSprite(std::string const & name)
{
	return m_spriteResources[name];
}

//const sf::Sound& ResourcesManager::GetSound(std::string const & name)
//{
//	return soundResources[name];
//}