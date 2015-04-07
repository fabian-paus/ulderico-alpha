# Einleitung #

Da an diesem Projekt mehrere Entwickler arbeiten, ist es wichtig die Grundlagen für den Programmierstil.

# Richtlinien #

## Sprache ##
Programmcode wird in Englisch geschrieben. Deutsche Bezeichner sind **nicht** erlaubt. Kommentare werden in Deutsch verfasst.

## Quellcode ##
Für jede Klasse wird ein Pärchen aus Quellcode- und Headerdatei angelegt. Der Dateiname entspricht dem Klassennamen. Für Headerdateien wird die Endung .h, für Quellcode die Endung .cpp verwendet.

Jede Headerdatei wird durch einen Include-Guard vor mehrfacher Einbindung geschützt. Ein Include-Guard hat diese Form:

```
#ifndef ULDERICO_ALPHA_CLASS_NAME_H_INCLUDED
#define ULDERICO_ALPHA_CLASS_NAME_H_INCLUDED

// Eigentlicher Inhalt der Headerdatei

#endif // ULDERICO_ALPHA_CLASS_NAME_H_INCLUDED

```

## Kommentare ##
Jede Klasse muss einen einleitenden Kommentar enthalten, der ihre Funktionalität beschreibt. Jede nicht öffentliche Funktion muss kommentiert werden. Private Funktionen dürfen/sollten ebenfalls kommentiert werden. Ein Funktionskommentar enthält die Aufgabe der Funktion und eine Beschreibung der Parameter und des Rückgabewerts.

Kommentare im Quellcode sollten beschreiben, was umgesetzt wurde und nicht wie (das steht schon im Code).

## Namensgebung ##
Durch Vorgaben in der Namensgebung schafft man vertraute Strukturen und lesbaren Code.

  * Typen (Klassen, Strukturen, etc.): PascalCase
  * Methoden: PascalCase
  * Namespaces: klein\_mit\_unterstrichen
  * Konstanten: GROSS\_MIT\_UNTERSTRICHEN
  * Lokale Variablen: camelCase
  * Member Variablen: m\_soWieVariablen (führendes m)

Klassennamen sind Subjektive. Methoden und Funktionen beginnen mit einem Verb. Abkürzungen sind grundsätzlich nicht erlaubt. Bezeichner müssen ausgeschrieben werden. Ausnahmen sind bekannte Abkürzungen wie XML, HTML, API, etc.

## Verwendete C++ Features ##
C++ ist eine Multiparadigmensprache. Es gibt verschiedene Features der Sprache, die sich für unterschiedliche Aufgaben eignen (Prozeudrale Programmierung wie in C, Objektorientierte Programmierung in C++, Metaprogrammierung mit Templates, Funktionale Programmierung mit Lambdas). Da wir in der Vorlesung nur einen kleinen Teil gesehen haben, beschränken wir uns in diesem Projekt auf das objektorientierte C++.

Das Projekt wird keine eigenen Templates enthalten. Die Verwendung von Templates aus der Standard-Bibliothek (vor allem Container-Klassen) ist zulässig und empfohlen. Eigene Container-Klassen sollten nicht implementiert werden.

Fehlerbehandlung erfolgt über Exceptions. Eigene Exceptions müssen von der Klasse std::exception abgeleitet werden. Fehlerbehandlung sollte in diesem Projekt lediglich beim Laden der Ressourcen notwendig sein.

## Verbote ##
Aus Gründen der Lesbarkeit und Nachvollziehbarkeit des Codes sind folgende Sprachfeatures verboten. Nach den Punkten sind ein paar Alternativen aufgelistet.
  * Makros: Funktionen
  * Globale Variablen: Lokale Variablen, Parameter, Rückgabewerte