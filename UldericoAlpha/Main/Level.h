#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "Squadron.h"

class Level
{
private:
	Squadron squadron;
public:
	Level(void);
	~Level(void);
	void Start();
	void Update();
};

#endif