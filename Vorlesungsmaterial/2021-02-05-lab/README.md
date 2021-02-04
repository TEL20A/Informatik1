# Implementierung des Kartenspiels "Mau Mau"

Ziel ist es, das Spiel Mau Mau in einer einfachen Version zu implementieren.

## Spielregeln

## Konzept für die Implementierung

## Vorgegebener Code

Enum für die Farben von Spielkarten.

    enum Farbe
    {
      KREUZ, PIK, HERZ, KARO
    };


Enum für die Werte von Spielkarten.

    enum Wert
    {
      SIEBEN, ACHT, NEUN, ZEHN, BUBE, DAME, KOENIG, ASS
    };

Hilfsfunktion: Gibt zu einer Farbe einen String zurück.

    std::string str(Farbe f);

Hilfsfunktion: Gibt zu einem Wert einen String zurück.

    std::string str(Wert w);

Klasse für Spielkarten. Jede Karte besteht aus einer Farbe und einem Wert.

    struct Spielkarte
    {
      Farbe farbe;
      Wert wert;
    };

Hilfsfunktion: Erzeugt ein frisches Skatblatt und liefert es zurück.

    vector<Spielkarte> skatBlatt();

## Aufgaben

- Implementieren Sie die unten vorgegebenen Funktionen.
- Implementieren Sie mit Hilfe der Funktionen ein Zwei-Spieler-Mau-Mau.  
  Zunächst sollten Sie nur die Grundlogik implementieren, bei der die Spieler abwechselnd Karten legen, wobei geprüft wird, ob der Zug *   erlaubt ist.
- Erweitern Sie das Spiel um:
  - neu mischen, wenn beim Ziehen der Kartenstapel leer ist.
  - mehrere Spieler
  - Sonderregeln (zwei ziehen bei 7, Aussetzen bei 8, Farbwunsch bei Bube)
    - Hinweis: Aussetzen bei 8 ist am einfachsten.
- Setzen Sie weitere Ideen und/oder andere Spiele um. Z.B.:
  - KI für Mau-Mau? Mehrere Spiele mit Punktetabelle?
  - Uno (Mau-Mau mit mehr Regeln und Sonderfällen).
  - BlackJack (17 und 4).