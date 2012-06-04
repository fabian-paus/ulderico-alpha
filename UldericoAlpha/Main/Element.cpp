#include "Element.h"

#include <cmath>

namespace UldericoAlpha
{

	Element::Element()
		: m_posX(0),
		  m_posY(0),
		  m_boundingBox(),
		  m_speed(0)
	{}

	Element::Element(float width, float height)
        : m_boundingBox(width, height),
		  m_speed(0.0f)
	{}

	Element::Element(float posX, float posY, float width, float height)
		:m_posX(posX),
		m_posY(posY),
		m_boundingBox(width, height),
		m_speed(0)
	{}

	void Element::SetPosition(float posX, float posY)
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
		float dx = std::fabs(this->GetX() - el.GetX());

		//Abstand zwischen den beiden Y-Koordinaten
		float dy = std::fabs(this->GetY() - el.GetY());

		//Höhe des weiter oben gelegenen Elements
		float height = this->GetY() > el.GetY() ? boundingBox.GetHeight() : this->GetBoundingBox().GetHeight();
		
		//Breite des weiter links gelegenen Elements
		float width = this->GetX() > el.GetX() ? boundingBox.GetWidth() : this->m_boundingBox.GetWidth();

		//Bestimmung, ob die Elemente überlappen
		if(dx < width && dy < height)
		{
			//Schauen, ob das Element auch wirklich getroffen wurde
			return Impact(el);
		}
		return false;
	}
}