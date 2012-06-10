#ifndef ULDERICO_ALPHA_OBJECT_H_INCLUDED
#define ULDERICO_ALPHA_OBJECT_H_INCLUDED

#include "Vector2D.h"

namespace UldericoAlpha
{
    /**
    * Diese Klasse repr�sentiert ein Objekt in der Welt.
    * Ein Objekt hat eine Position, Gr��e und Geschwindigkeit.
    */
    class Object
    {
    public:
        /** 
        * Erstellt ein Objekt mit gegebener Position, Gr��e und
        * Geschwindigkeit.
        */
        Object(Vector2D const& position,
            Vector2D const& size,
            Vector2D const& speed = Vector2D::ZERO);

        /**
        * Gibt die Position des Objekts zur�ck.
        */
        Vector2D const& GetPosition() const { return m_position; }

        /**
         * Setzt die Position des Objekts auf den gegebenen Wert.
         */
        void SetPosition(Vector2D const& position) { m_position = position; }

        /**
        * Gibt die Gr��e des Objekts zur�ck.
        */
        Vector2D const& GetSize() const { return m_size; }

        /**
        * Gibt die Geschwindigkeit des Objekts zur�ck.
        */
        Vector2D const& GetSpeed() const { return m_speed; }

        /**
         * Setzt die Geschwindigkeit des Objekts auf den gegebenen Wert.
         */
        void SetSpeed(Vector2D const& speed) { m_speed = speed; }

        /**
         * Nutzt den Interpolationsfaktor, um die aktuelle Position des
         * Objekts vorherzusagen.
         */
        Vector2D PredictPosition(float interpolation) const;

        /**
         * �berpr�ft, ob diese Objekt mit einem anderen kollidiert.
         */
        bool CollidesWith(Object const& other);

        /**
         * Aktualisiert das Objekt. Dabei wird das Objekt mit der aktuellen
         * Geschwindigkeit weiterbewegt.
         */
        virtual void Update();

    protected:
        /**
         * Wurde �ber die Standard-Kollisionserkennung eine �berlappung von
         * Objekten entdeckt, dann wird diese Methode aufgerufen, um eine
         * Kollision zu erkennen.
         * Abgeleitete Klassen k�nnen diese Methode �berschreiben, um das
         * Standardverhalten zu �ndern.
         */
        virtual bool DetectCollision(Object const& other)
        {
            return true;
        }

    private:
        Vector2D m_position;
        Vector2D m_size;
        Vector2D m_speed;
    };


}

#endif // ULDERICO_ALPHA_GAME_STATES_H_INCLUDED
