#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

class Element
{
private:
	int posX;
	int posY;
	int speed;
	int scale;
public:
	Element(void);
	~Element(void);
	void SetPosition(int x, int y);
	bool IsHit(Element el);
};

#endif