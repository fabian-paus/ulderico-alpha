#include "Element.h"

namespace UldericoAlpha
{

	Element::Element()
		:m_posX(0),
		m_posY(0),
		m_boundingBox(),
		m_speed(0)
	{}

	Element::Element(int width, int height)
		:m_boundingBox(width, height),
		m_speed(0)
	{}

	Element::Element(int posX, int posY, int width, int height)
		:m_posX(posX),
		m_posY(posY),
		m_boundingBox(width, height),
		m_speed(0)
	{}

	void Element::SetPosition(int const posX, int const posY)
	{
		if(posX >= 0)
			m_posX = posX;
		if(posY >= 0)
			m_posY = posY;
	}

	bool Element::IsHit(Element const &el)
	{
		//Überprüfen ob irgendein Punkt des Elements innerhalt des Objekts befindet
		//Boungingbox des übergebenen Elements
		BoundingBox boundingBox = el.GetBoundingBox();

		//Abstand zwischen den beiden X-Koordinaten
		int dx = this->GetX() - el.GetX();
		dx = dx > 0 ? dx : -dx;

		//Abstand zwischen den beiden Y-Koordinaten
		int dy = this->GetY() - el.GetY();
		dy = dy > 0 ? dy : -dy;

		//Höhe des weiter oben gelegenen Elements
		int height = this->GetY() > el.GetY() ? boundingBox.GetHeight() : this->GetBoundingBox().GetHeight();
		
		//Breite des weiter links gelegenen Elements
		int width = this->GetX() > el.GetX() ? boundingBox.GetWidth() : this->m_boundingBox.GetWidth();

		//Bestimmung, ob die Elemente überlappen
		if(dx < width && dy < height)
		{
			//Schauen, ob das Element auch wirklich getroffen wurde
			return Impact(el);
		}
		return false;
	}
}