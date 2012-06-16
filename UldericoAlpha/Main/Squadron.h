#ifndef ULDERICO_ALPHA_SQUADRON_H_INCLUDED
#define ULDERICO_ALPHA_SQUADRON_H_INCLUDED

#include "Object.h"
#include "Invader.h"
#include "InvaderType.h"
#include "BoundingBox.h"
#include "MotionPattern.h"

#include <vector>
#include <algorithm>

namespace UldericoAlpha
{
	class Squadron : public Object
	{
	public:
		Squadron();

		void SetAbsoluteSpeed(float speed);
				
		void SetBoundingBox(Vector2D size, Vector2D position);

		void Initialize();

        std::vector<Invader>::const_iterator InvadersBegin() const
        { return m_invaders.begin(); }

        std::vector<Invader>::const_iterator InvadersEnd() const
        { return m_invaders.end(); }

		bool HasInvaders() const { return m_invaders.size() > 0; };

		void EraseInvaders();

		bool Collision(Object const bullet, bool kill = true);

		virtual void Update();

	private:
		std::vector<Invader> m_invaders;
		Vector2D GetSpeed();
		void SetSpeed(Vector2D speed);
		BoundingBox m_boundingBox;
		bool CanMove();
		void UpdateInvaders();
		MotionPattern m_motionPattern;
		float m_absoluteSpeed;
		static const int MARGIN = 6;		
	};
}

#endif //ULDERICO_ALPHA_SQUADRON_H_INCLUDED