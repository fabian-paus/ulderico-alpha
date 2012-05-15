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
	int GetX();
	int GetY();
	bool IsHit(Element el);
   void Shot();
	virtual const char* GetType() { return "Element"; };
};

#endif