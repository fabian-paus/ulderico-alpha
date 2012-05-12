#ifndef ALIEN2_H_INCLUDED
#define ALIEN2_H_INCLUDED

#include "Invader.h"

class Alien2 : public Invader
{
public:
	Alien2(void);
	~Alien2(void);
	virtual const char* GetType() { return "blue-invader"; };
};

#endif