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
	BoundaryBox(int top = 0, int right = 0, int bottom = 0, int left = 0);
	~BoundaryBox();
	BoundaryPosition GetPositionInBox(Element el);
};

#endif