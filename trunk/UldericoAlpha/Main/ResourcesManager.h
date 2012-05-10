#ifndef RESOURCESMANAGER_H_INCLUDED
#define RESOURCESMANAGER_H_INCLUDED

#include "ResourcesManagerTemplate.h"

static const char *characters = "\\res\\img\\characters.png";
static const char *background = "\\res\\img\\invaders.png";

class ResourcesManager : public ResourcesManagerTemplate <sf::Sprite>
{
public:
	ResourcesManager(void);
	~ResourcesManager(void);
    void Free(std::string const & name);
};

#endif