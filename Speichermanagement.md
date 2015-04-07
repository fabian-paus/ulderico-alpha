# Einleitung #

Das Speichermanagement in C++ unterscheidet sich erheblich von dem aus anderen bekannten Sprachen. Deshalb erstelle ich hier eine kleine Einleitung um Speicherlecks und weitere Probleme in unserem Projekt zu vermeiden.

# Speichermanagement #

## Erstellung von Objekten ##
In anderen Sprachen (mit einem Garbage-Collector) ist folgende Art der Erstellung von Objekten bekannt:
```
Object o = new Object(args);
```
Diese Schreibweise verleitet dazu, Folgendes in C++ zu schreiben:
```
Object* o = new Object(args);
```
Das ist allerdings die falsche "Übersetzung". Die korrekte Umsetzung wäre:
```
Object o(args);
```

## Richtige Benutzung von `new` ##
Die einfache Antwort darauf ist: Don't do it!

In unserem Projekt wird es keine Stelle geben an der die Benutzung von `new` notwendig ist. Falls ihr auf ein Problem stoßt, bei dem ihr `new` verwenden wollt, wendet euch am besten an mich. Ich zeige euch dann eine `new`-freie Lösung.

Der Vorteil bei der Nichtverwendung von `new` ist, dass wir Speicherlecks zu 100% in unserem Projekt ausschließen können.

Für dynamische Listen gibt es bereits fertige Container aus der Standardbibliothek, sodass die Verwendung von `new[]` auch vermieden werden sollte. Siehe http://www.cplusplus.com/reference/stl/.

## Fazit ##
  * Objekte immer "normal" anlegen
  * Für Listen Standardcontainer verwenden