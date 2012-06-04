#ifndef ULDERICO_ALPHA_BOUNDARYBOX_H_INCLUDED
#define ULDERICO_ALPHA_BOUNDARYBOX_H_INCLUDED

namespace UldericoAlpha
{
	/**
	* Klasse, welche die Grenzen eines Elements definiert
	*/
	class BoundingBox
	{
	private:
		float m_width;

		float m_height;

	public:
		/**
		* Konstruktur, mit Standard Inititalisierung
		*/
		BoundingBox(float width = 0, float height = 0);

		/**
		* Getter für die Breite
		*/
		float GetWidth() { return m_width; };

		/**
		* Getter für die Höhe
		*/
		float GetHeight() { return m_height; };

		void SetBoundingBox(float height, float width) { m_width = width; m_height = height;};
	};
}

#endif // ULDERICO_ALPHA_BOUNDARYBOX_H_INCLUDED