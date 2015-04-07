# Einleitung #

Das Projekt Ulderico Alpha hat das Ziel einen Space Invaders Clone zu implementieren.


# Anforderungen #

Titelbildschirm:
  * Auf dem Titelbildschirm stehen die Optionen "Spiel starten", "Highscore anzeigen" und "Spiel beenden" zur Auswahl.
  * Auf dem Titelbildschirm wird ein Hintergrundbild angezeigt.
  * Während der Titelbildschirm angezeigt wird, wird eine Hintergrundmusik abgespielt.

Highscore:
  * Der Highscore zeigt die Liste der 10 höchsten Punktzahlen an.
  * Jeder Eintrag in der Liste enthält die Platzierung (1 - 10), den am Spielende eingegebenen Namen und die Punktzahl.

Spiel:
  * Das Spiel kann pausiert werden.
  * Wie im echten Spiel mit STRG + P
  * Während einer Pause finden keine Aktionen (Spieler und Computer) im Spiel statt.
  * Es wird der Pause Bildschirm angezeigt
  * Das Spiel kann nach einer Pause wieder fortgesetzt werden.
  * Auch hier wie im echten Spiel mit der Taste P
  * Das Spiel kann abgebrochen werden. Das bedeutet Rückkehr zum Titelbildschirm ohne Speichern von Zwischenergebnissen .

Steuerung:
  * Ein Spieler kann sich horizontal bewegen.
  * Ein Spieler kann schießen.

Statusanzeige:
  * Wahrend des Spiels wird die erreichte Punktzahl angezeigt.
  * Während des Spiels wird die Anzahl der noch verbleibenden Leben des Spielers angezeigt.

Gegner:
  * Die Gegner starten in einem Schwarm oberhalb des Spielers.
  * Der Schwarm bewegt sich horizontal bis er an den Rand des Spielfeldes kommt. Danach bewegt er sich nach unten.
  * Die Gegner schießen zufällig auf den Spieler (nach unten).

Schutzschilde:
  * Der Spieler hat 4 Schutzschilde.
  * Die Schilde blockieren die Schüsse des Spielers und der Gegner.
  * Die Schilde verfügen über kein Schadensmodell (sind unzerstörbar).

Schüsse:
  * Alle Schüsse bewegen sich mit einer konstanten Geschwindigkeit.
  * Schüsse des Spielers bewegen sich nach oben
  * Schüsse der Gegner bewegen sich nach unten

Treffer:
  * Wird er Spieler getroffen, verliert dieser ein Leben.
  * Wird ein Gegner getroffen, stirbt dieser.

Punkte:
  * Die unterschiedlichen Gegnertypen geben bei Abschuss verschiedene Punkte.
  * Typ 1: 10 Punkte (Purple)
  * Typ 2: 20 Punkte (Blue)
  * Typ 3: 30 Punkte (Green)
  * Typ 4: 100 Punkte (Mothership)

Game Over:
  * Hat der Spieler keine Leben mehr, ist die Spielrunde beendet.
  * Der Schriftzug "Game Over" angezeigt.
  * Die erreichte Punktzahl des Spielers wird angezeigt.
  * Reicht die erreichte Punktzahl für einen Eintrag im Highscore, dann wird der Benutzer zur Eingabe seines Namen aufgefordert. Danach wird der Eintrag in den Highscore aufgenommen.

Musik:
  * Titelmusik auf dem Titelbildschirm
  * Hintergrundmusik während des Spiels
  * Pausieren hält auch die Hintergrundmusik an
  * Auf dem "Game Over" Bildschirm wird eine Hintergrundmusik abgespielt.

Soundeffekte:
  * Spieler gibt einen Schuss ab.
  * Ein Gegner wird abgeschossen.

Animationen:
  * Die Gegner bewegen sich, haben aber keine Animationen
  * Es gibt keine Sterbeanimation für den Spieler bzw. die Gegner.

Erweiterungsmöglichkeiten:
  * Bisher sind Mutterschiffe noch nicht vorgesehen. Diese könnten zufällig auftauchen und bei Abschuss durch den Spieler Bonuspunkte geben (100 - 300).
  * Die Steuerung kann nicht konfiguriert werden. Hier kann eine Option ins Hauptmenü hinzugefügt werden, die es erlaubt die Tastenbelegung zu definieren.