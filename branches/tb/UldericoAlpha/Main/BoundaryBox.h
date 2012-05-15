#ifndef BOUNDARYBOX_H_INCLUDED
#define BOUNDARYBOX_H_INCLUDED

#include "Element.h"

enum BoundaryPosition
{
	CanMove,
	CollidedLeft,
	CollidedTop,
	CollidedRight,
	CollidedBottom
};

class BoundaryBox
{
private:
	int top;
	int right;
	int bottom;
	int left;
public:
	BoundaryBox(void);
	~BoundaryBox(void);
	BoundaryBox GetPositionInBox(Element el);
};

#endif