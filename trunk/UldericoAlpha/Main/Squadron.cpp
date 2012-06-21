#include "Squadron.h"

namespace UldericoAlpha
{	
    static const Vector2D SQUADRON_SIZE(123.0f * 0.4f, 87.0f * 0.4f);
	static const Vector2D SQUADRON_POSITION(0.0f, 50.0f);

	Squadron::Squadron()
		: Object(SQUADRON_POSITION, SQUADRON_SIZE),
		  m_motionPattern(true),
		  m_absoluteSpeed(0.0f)
	{
		m_invaders.reserve(30);
	}

	void Squadron::SetAbsoluteSpeed(float speed)
	{
		m_absoluteSpeed = speed;
	}

	void Squadron::SetBoundingBox(Vector2D size, Vector2D position)
	{
		m_boundingBox = BoundingBox(size, position);
	}

	void Squadron::Initialize()
	{
		m_invaders.clear();
				
		Vector2D speed(m_absoluteSpeed, 0.0f);

		for(int j = 2; j >= 0 ; j--)
		{
			for(int i = 0; i < 10; i++)
			{
				Invader invader((InvaderType)j);
				float posX = ((invader.GetSize().GetX() + MARGIN) * i) + this->GetPosition().GetX();
				float posY = ((invader.GetSize().GetY() + MARGIN) * j) + this->GetPosition().GetY();
				invader.SetPosition(Vector2D(posX, posY));
				invader.SetSpeed(speed);
				m_invaders.push_back(invader);
			}
		}

		m_motionPattern.Clear();

		//Bewegungsablauf festlegen
		m_motionPattern.AddStep(InvaderAction_MoveRight, -1);
		m_motionPattern.AddStep(InvaderAction_MoveDown, 5);
		m_motionPattern.AddStep(InvaderAction_MoveLeft, -1);
		m_motionPattern.AddStep(InvaderAction_MoveDown, 5);
	}

	void Squadron::EraseInvaders()
	{
		// Alle getöteten Invader entfernen
		auto eraseInvaders = std::remove_if(m_invaders.begin(), m_invaders.end(),
			[] (Invader const& invader) { return !invader.IsAlive(); });

		m_invaders.erase(eraseInvaders, m_invaders.end());
	}

	bool Squadron::Collision(Object const bullet, bool kill)
	{		
		// Hat die Kugel einen Invader aus dem Schwadron getroffen?
		for (auto invader = m_invaders.begin(); invader != m_invaders.end(); ++invader)
		{
			if (invader->CollidesWith(bullet))
			{
				if (kill)
					invader->Kill();
				return true;
			}
		}
		return false;
	}

	void Squadron::Update()
	{
		if (m_invaders.empty())
			return;

		while(!CanMove())
		{
			m_motionPattern.SetNextAction();
			SetSpeed(GetSpeed());
		}	
		SetSpeed(GetSpeed());	
		UpdateInvaders();
	}

	bool Squadron::CanMove()
	{
		for(auto invader = m_invaders.begin(); invader != m_invaders.end(); ++invader)
		{
			//Überprüfen ob die Invader sich noch in der Boundingbox befinden
			BoundingBoxAction boundingBoxAction = m_boundingBox.InBoundingBox(*invader);
			if(boundingBoxAction != BoundingBoxAction_Move)
			{
				return false;
			}
		}
		return true;
	}

	Vector2D Squadron::GetSpeed()
	{
		Vector2D speed;
		switch(m_motionPattern.GetAction())
		{
		case InvaderAction_MoveDown:
			speed = Vector2D(0.0f, m_absoluteSpeed);
			break;
		case InvaderAction_MoveLeft:
			speed = Vector2D(-m_absoluteSpeed, 0.0f);
			break;
		case InvaderAction_MoveRight:
			speed = Vector2D(m_absoluteSpeed, 0.0f);
			break;
		default:
			speed = Vector2D::ZERO;
		}
		return speed;
	}

	void Squadron::SetSpeed(Vector2D speed)
	{
		for (auto invader = m_invaders.begin(); invader != m_invaders.end(); ++invader)
		{
			if(speed != Vector2D::ZERO)
				invader->SetSpeed(speed);
		}
	}

	void Squadron::UpdateInvaders()
	{
		for (auto invader = m_invaders.begin(); invader != m_invaders.end(); ++invader)
		{
			invader->Update();
		}
	}
}