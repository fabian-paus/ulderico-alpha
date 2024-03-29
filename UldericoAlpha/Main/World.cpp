#include "World.h"

#include <algorithm>

namespace UldericoAlpha
{
    /** 
     * Die Absolutgeschwindigkeit des Spielers, wenn dieser bewegt wird,
     * kann hier angepasst werden.
     */
    static const float PLAYER_ABS_SPEED = 10.0f;

	static const float BULLET_ABS_SPEED = 10.0f;

	static const int INITIAL_PLAYER_LIVES = 3;

    World::World(Vector2D const& size)
        : m_size(size),
		  m_player(INITIAL_PLAYER_LIVES),
		  m_shootChance(0.0f)
    {
		// Speicher f�r Sch�sse reservieren, um mehrfache Allokationen zu vermeiden
		m_bullets.reserve(32);
		m_shields.reserve(4);
    }

	void World::Reset()
	{
		m_player = Player(INITIAL_PLAYER_LIVES);
		m_bullets.clear();
		InitializePlayer();
		InitializeShields();
		m_squadron.Initialize();
	}

	void World::Load(Level const& level)
	{
		InitializeSquadron(level.GetAbsoluteSpeed());
		m_shootChance = level.GetShootChance();
	}
    
    void World::MovePlayerLeft()
    {
        m_player.SetSpeed(Vector2D(-PLAYER_ABS_SPEED, 0.0f));
        if (!CanPlayerMove())
            StopPlayerMovement();
    }
    
    void World::MovePlayerRight()
    {
        m_player.SetSpeed(Vector2D(+PLAYER_ABS_SPEED, 0.0f));
        if (!CanPlayerMove())
            StopPlayerMovement();
    }

    void World::StopPlayerMovement()
    {
        m_player.SetSpeed(Vector2D::ZERO);
    }

    void World::ShootFromPlayer()
    {
        Vector2D position(
            m_player.GetPosition().GetX() + m_player.GetSize().GetX() / 2.0f - Bullet::WIDTH / 2.0f,
            m_player.GetPosition().GetY() - Bullet::HEIGHT);

        Vector2D speed(0.0f, -BULLET_ABS_SPEED);

        m_bullets.push_back(Bullet(position, speed, Bullet_Player));
    }

    void World::Update()
    {
        UpdatePlayer();

		UpdateEnemies();
		m_squadron.Update();

        for (auto shield = m_shields.begin(); shield != m_shields.end(); ++shield)
            shield->Update();

        for (auto bullet = m_bullets.begin(); bullet != m_bullets.end(); ++bullet)
            bullet->Update();

        CheckCollisions();
    }

    void World::InitializePlayer()
    {
        Vector2D startPosition(
            GetWidth() / 2.0f - m_player.GetSize().GetX() / 2.0f, 
            GetHeight() - m_player.GetSize().GetY() - 30.0f);

        m_player.SetPosition(startPosition);
    }

    void World::InitializeShields()
    {
		m_shields.clear();

        m_shields.push_back(Shield( 60, 420));
		m_shields.push_back(Shield(240, 420));
		m_shields.push_back(Shield(420, 420));
		m_shields.push_back(Shield(600, 420));
    }

	void World::InitializeSquadron(float speed)
	{
		m_squadron.SetAbsoluteSpeed(speed);
		Vector2D boundingSize(m_size.GetX(), m_size.GetY() - 220.0f);
		m_squadron.SetBoundingBox(boundingSize, Vector2D(0.0f, 50.0f));
		m_squadron.Initialize();
	}

    void World::UpdatePlayer()
    {
        m_player.Update();
        if (!CanPlayerMove())
            StopPlayerMovement();
    }

	void World::UpdateEnemies()
	{
		m_squadron.Update();

		// Die Invader schiessen zuf�llig auf den Spieler
		for (auto invader = m_squadron.InvadersBegin(); invader != m_squadron.InvadersEnd(); ++invader)
		{
			if (rand() < m_shootChance * RAND_MAX)
				ShootFromInvader(*invader);
		}
	}

	void World::ShootFromInvader(Invader const& invader)
	{
		Vector2D position(
            invader.GetPosition().GetX() + invader.GetSize().GetX() / 2.0f - Bullet::WIDTH / 2.0f,
            invader.GetPosition().GetY() + invader.GetSize().GetY() + 0.5f);

        Vector2D speed(0.0f, BULLET_ABS_SPEED);

		Bullet bullet(position, speed, invader.GetBulletType());

		// Vermeiden, dass sich die Invader selbst t�ten
		if (!m_squadron.Collision(bullet, false))
			m_bullets.push_back(bullet);
	}
    
    bool World::CanPlayerMove() const
    {
        Vector2D nextPosition = m_player.PredictPosition(1.0f);

        // Linker Rand
        if (nextPosition.GetX() < 0.0f)
            return false;

        // Rechter Rand (Gr��e des Spielers mit einbeziehen)
        if (nextPosition.GetX() > GetWidth() - m_player.GetSize().GetX())
            return false;

        return true;
    }

    void World::CheckCollisions()
    {
		bool playerWasHit = false;

        // Wenn eine Kugel ein Schild trifft, dann entfernen
        auto eraseBullets = std::remove_if(m_bullets.begin(), m_bullets.end(), 
			[&] (Bullet const& bullet) -> bool
		{
            // Oben aus dem Bildschirm geflogen
            if (bullet.GetPosition().GetY() < -Bullet::HEIGHT)
                return true;

            // Unten aus dem Bildschirm geflogen
            if (bullet.GetPosition().GetY() > GetHeight())
                return true;

			// Hat die Kugel ein Schild getroffen?
            for (auto shield = m_shields.begin(); shield != m_shields.end(); ++shield)
            {
                if (shield->CollidesWith(bullet))
                    return true;
		    }

			//Hat die Kugel einen Invader aus dem Schwadron getroffen?
			if(m_squadron.Collision(bullet))
			{
				m_onInvaderHit();
				return true;
			}
			
			// Hat die Kugel den Spieler getroffen?
			if (m_player.CollidesWith(bullet))
			{
				playerWasHit = true;
				return true;
			}

            return false;
        });


		// Abgeschossene invaders geben Punkte..., zum Score des Spielers addieren
		for (auto invader = m_squadron.InvadersBegin(); invader != m_squadron.InvadersEnd(); ++invader)
		{
			if (!invader->IsAlive())
				m_player.AddToScore(invader->GetScore());
		}

		m_bullets.erase(eraseBullets, m_bullets.end());
		m_squadron.EraseInvaders();
		

		// Wenn der Spieler mindestens einmal getroffen wurde, verliert er ein Leben
		if (playerWasHit)
		{
			m_onPlayerHit();
			m_player.LoseLife();
		}
    }
}
