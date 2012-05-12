#ifndef ALIEN3_H_INCLUDED
#define ALIEN3_H_INCLUDED

#include "Invader.h"

class Alien3 : public Invader
{
public:
	Alien3(void);
	~Alien3(void);
	virtual const char* GetType() { return "purble-invader"; };
};

#endif

