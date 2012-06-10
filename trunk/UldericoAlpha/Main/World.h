#ifndef ULDERICO_ALPHA_WORLD_H_INCLUDED
#define ULDERICO_ALPHA_WORLD_H_INCLUDED

#include "Player.h"
#include "Shield.h"
#include "Bullet.h"
#include "Squadron.h"

namespace UldericoAlpha
{
    /**
    * Diese Klasse repr�sentiert die Welt.
    * Die Welt enth�lt alle f�r die Spiellogik relevanten Objekte.
    */
    class World
    {
    public:
        /** 
        * Erstellt eine neue Welt mit gegebener Gr��e.
        */
        World(Vector2D const& size);

        /**
         * Gibt die Breite der zweidimensionalen Welt an.
         */
        float GetWidth() const { return m_size.GetX(); }

        /**
         * Gibt die H�he der zweidimensionalen Welt an.
         */
        float GetHeight() const { return m_size.GetY(); }

        Player const& GetPlayer() const { return m_player; }

        std::vector<Shield>::const_iterator ShieldsBegin() const
        { return m_shields.begin(); }

        std::vector<Shield>::const_iterator ShieldsEnd() const
        { return m_shields.end(); }

        std::vector<Bullet>::const_iterator BulletsBegin() const
        { return m_bullets.begin(); }

        std::vector<Bullet>::const_iterator BulletsEnd() const
        { return m_bullets.end(); }

		std::vector<Invader>::const_iterator InvadersBegin() const
		{ return m_squadron.InvadersBegin(); }

        std::vector<Invader>::const_iterator InvadersEnd() const
		{ return m_squadron.InvadersEnd(); }

		bool HasInvaders() const { return m_squadron.HasInvaders(); }

        void MovePlayerLeft();

        void MovePlayerRight();

        void StopPlayerMovement();

        void ShootFromPlayer();

		bool IsPlayerAlive() const { return m_player.IsAlive(); }

        /**
         * Aktualisiert alle Objekte in der Welt.
         */
        void Update();

    private:
        void InitializePlayer();

        void InitializeShields();

		void InitializeSquadron();

        void UpdatePlayer();

        bool CanPlayerMove() const;

        void CheckCollisions();

    private:
        Vector2D m_size;

        Player m_player;
        std::vector<Shield> m_shields;
        std::vector<Bullet> m_bullets;
		Squadron m_squadron;
    };


}

#endif // ULDERICO_ALPHA_WORLD_H_INCLUDED
