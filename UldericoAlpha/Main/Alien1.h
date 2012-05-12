#ifndef ALIEN1_H_INCLUDED
#define ALIEN1_H_INCLUDED

#include "Invader.h"

class Alien1 : public Invader
{
public:
	Alien1(void);
	~Alien1(void);
	virtual const char* GetType() { return "green-invader"; };
};

#endif