#include "BoundaryBox.h"


BoundaryBox::BoundaryBox(int t, int r, int b, int l)
{
	top = t;
	right = r;
	bottom = b;
	left = l;
}


BoundaryBox::~BoundaryBox(void)
{
}

BoundaryPosition BoundaryBox::GetPositionInBox(Element el)
{
	return CanMove;
}