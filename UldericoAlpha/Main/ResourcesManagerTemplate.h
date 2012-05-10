#ifndef RESOURCESMANAGERTEMPLATE_H_INCLUDED
#define RESOURCESMANAGERTEMPLATE_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

template <class T>
class ResourcesManagerTemplate
{
	typedef std::map <std::string,T*> ResourceMap;

private:
	ResourceMap resources;

protected:
	void Register( std::string const & name, T * resource )
	{
		resources.insert( std::make_pair( name, resource ) );
	}

	void UnRegister( std::string const & name )
	{
		typename ResourceMap::iterator it = resources.find(name);
		if (it != resources.end())
			resources.erase(it);
	}

public:
	T * Get( std::string const & name )
	{
		typename ResourceMap::iterator it = resources.find( name );
		if ( it != resources.end( ) )
			return (*it).second;
		return NULL;
	}

	~ResourcesManagerTemplate( )
	{
		typename ResourceMap::iterator it;
		for ( it = resources.begin( ); it != resources.end( ); ++it )
			delete (*it).second;
	}

};

#endif