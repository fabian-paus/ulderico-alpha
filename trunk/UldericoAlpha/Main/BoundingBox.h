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
		int m_width;

		int m_height;

	public:
		/**
		* Konstruktur, mit Standard Inititalisierung
		*/
		BoundingBox(int width = 0, int height = 0);

		/**
		* Getter für die Breite
		*/
		int GetWidth() { return m_width; };

		/**
		* Getter für die Höhe
		*/
		int GetHeight() { return m_height; };

		void SetBoundingBox(int height, int width) { m_width = width; m_height = height;};
	};
}

#endif // ULDERICO_ALPHA_BOUNDARYBOX_H_INCLUDED