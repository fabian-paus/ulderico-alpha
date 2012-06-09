#include "ResourcesManager.h"

#include <iostream>
#include <cassert>

namespace UldericoAlpha
{

	ResourcesManager::ResourcesManager()
	{
		LoadTextures();
		LoadSprites();
		LoadSounds();
		LoadFonts();
	}

	sf::Sprite ResourcesManager::Get(Sprites sprite) const
	{
		assert(Sprites_Begin <= sprite && sprite < Sprites_Count);

		return m_sprites[sprite];
	}

	sf::Sound ResourcesManager::Get(Sounds sound) const
	{
		assert(Sounds_Begin <= sound && sound < Sounds_Count);

		return sf::Sound(m_soundBuffers[sound]);
	}

	sf::Text ResourcesManager::GetText(std::string const& text, Fonts font) const
	{
		return sf::Text(text, Get(font));
	}

	sf::Texture const& ResourcesManager::Get(Textures texture) const
	{
		assert(Textures_Begin <= texture && texture < Textures_Count);

		return m_textures[texture];
	}

	const sf::Font& ResourcesManager::Get(Fonts font) const
	{
		assert(Fonts_Begin <= font && font < Fonts_Count);

		return m_fonts[font];
	}

	void ResourcesManager::LoadTextures()
	{
		for (int i = Textures_Begin; i != Textures_Count; ++i)
		{
			Textures texture = Textures(i);

			std::string file = GetTextureFile(texture);

			if (!m_textures[i].LoadFromFile(file))
			{
				std::cerr << "Could not load texture from file '"	
					<< file << "'\n";
			}
		}
	}

	void ResourcesManager::LoadFonts()
	{
		for (int i = Fonts_Begin; i != Fonts_Count; ++i)
		{
			Fonts fontIndex = Fonts(i);

			std::string file = GetFontFile(fontIndex);
			sf::Font& font = m_fonts[i];

			if(!font.LoadFromFile(file))
			{
				std::cerr << "Could not load font resource from file '" 
					<< file << "'\n";
			}
		}
	}

	void ResourcesManager::LoadSprites()
	{
		for (int i = Sprites_Begin; i != Sprites_Count; ++i)
		{
			Sprites sprite = Sprites(i);

			// Daten auslesen
			Textures textureIndex = GetTexture(sprite);
			auto& texture = Get(textureIndex);
			sf::IntRect position = GetPosition(sprite, texture);
			float scale = GetScale(sprite);

			// Daten setzen
			auto& target = m_sprites[i];
			target.SetTexture(texture);
			target.SetTextureRect(position);
			target.SetScale(sf::Vector2f(scale, scale));
		}
	}

	void ResourcesManager::LoadSounds()
	{
		for (int i = Sounds_Begin; i != Sounds_Count; ++i)
		{
			Sounds sound = Sounds(i);
			std::string file = GetSoundFile(sound);

			auto& buffer = m_soundBuffers[i];

			if (!buffer.LoadFromFile(file))
			{
				std::cerr << "Could not load sound resource from file '" 
					<< file << "'\n";
			}
		}
	}

}
