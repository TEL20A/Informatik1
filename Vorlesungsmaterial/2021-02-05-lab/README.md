# Implementierung des Kartenspiels "Mau Mau"

Ziel ist es, das Spiel Mau Mau in einer einfachen Version zu implementieren.

## Spielregeln

### Gundregeln

- Gespielt wird mit einem Skatblatt (32 Karten)
- Es gibt einen Kartenstapel, von dem gezogen wird, einen Ablagestapel sowie Handkarten für jeden Spieler.
- Ziel der Spieler ist es, so schnell wie möglich ihre Karten abzulegen.
- Spielstart: Jeder Spieler bekommt 6 Karten vom Kartenstapel, eine Karte vom Kartenstapel wird offen auf den Ablagestapel gelegt.
- Die Spieler legen reihum Karten von ihrer Hand auf den Stapel.
  - Eine Karte darf gelegt werden, falls entweder ihre Farbe oder ihr Wert mit Farbe/Wert auf der obersten Karte des Ablagestapels übereinstimmen.
  - Wer keine passende Karte legen kann, muss stattdessen eine Karte bom Kartenstapel ziehen.
- Falls ein Spieler ziehen muss und keine Karte mehr auf dem Kartenstapel liegt, werden alle Karten bis auf die oberste des Ablagestapels auf den Kartenstapel gelegt und neu gemischt.

### Zusatzregeln
- Wird eine 7 gelegt, muss der nächste Spieler zwei Karten ziehen.
  - Weitere Zusatzregel: Kann der betroffene Spieler selbst eine 7 legen,
    muss der nächste 4 Karten ziehen usw.
- Wird eine 8 gelegt, muss der nächste Spieler aussetzen.
- Wird ein Bube gelegt, darf der legende Spieler sich eine Farbe wünschen.
  - Die als nächstes gelegte Karte muss dann nicht zum Ablagestapel passen,
    aber sie muss die gewünschte Farbe haben.


## Konzept für die Implementierung

Hier folgt die Beschreibung des generellen Konzepts für die Mau-Mau-Implementierung. Ein Teil der benötigten Datenstrukturen bzw. Funktionen ist bereits vorgegeben. Die Vorgabe findet sich in der Datei `maumau.cpp`.

### Datenstrukturen

Durch die Spielregeln sind die benötigten Datenstrukturen schon relativ klar:
Es werden zwei zentrale Kartenstapel sowie die Handkarten für jeden Spieler gebraucht.

Wir formalisieren sie hier einmal, um besser zu verstehen, was diese natürlichsprachlichen Anforderungen technisch bedeuten.

#### Spielkarten und Kartenstapel
In der Realität ist eine Karte ein Stück Pappe, das mit Symbolen bedruckt ist.
Für die Implementierung im Computer genügt es, die Karte durch ihre `Farbe` und ihren `Wert` zu charakterisieren. Wir definieren zwei `enum`-Datentypen für `Farbe` und `Wert`:

    enum Farbe
    {
      KREUZ, PIK, HERZ, KARO
    };

    enum Wert
    {
      SIEBEN, ACHT, NEUN, ZEHN, BUBE, DAME, KOENIG, ASS
    };

Mit diesen `enum`-Typen können wir einen Karten-Datentyp erstellen. Ein Struct mit dem Namen `Spielkarte`, das zwei Attribute hat, nämlich `farbe` und `wert`:

    struct Spielkarte
    {
      Farbe farbe;
      Wert wert;
    };

Ein Kartenstapel ist nun einfach eine Liste von Karten.
Hierfür definieren wir keinen eigenen Datentyp, aber immer da,
wo wir in der Implementierung einen Kartenstapel brauchen,
werden wir einen `vector` aus Karten benutzen:

    vector<Spielkarte>

Desweiteren sind zwei Hilfsfunktionen vorgegeben, die den Umgang mit Karten erleichtern.

    string str(Farbe f);
    string str(Wert w);
    
Die Implementierung dieser Funktionen ist in `maumau.cpp` gegeben.

#### Manipulation von Kartenstapeln

Beim Spielen werden immer wieder bestimmte Aktionen durchgeführt, wie z.B. das Ziehen von Karten, das Mischen von Stapeln etc.

Für jede dieser Aktionen sollte eine Funktion implementiert werden, die diese umsetzt. Eine Reihe von Funktionen sind in `maumau.cpp` bereits deklariert.

    vector<Spielkarte> skatBlatt();
    void printStapel(vector<Spielkarte> const & stapel);
    void mischen(vector<Spielkarte> & stapel);
    void ziehen(vector<Spielkarte> & stapel, vector<Spielkarte> & hand);
    void geben(vector<Spielkarte> & stapel, vector<Spielkarte> & hand);
    bool passt(Spielkarte const & k1, Spielkarte const & k2);
    void legen(string name, vector<Spielkarte> & kartenstapel, vector<Spielkarte> & ablagestapel, vector<Spielkarte> & hand);
    
Die Namen der Funktionen sollten weitgehend selbsterklärend sein,
in `maumau.cpp` findet sich als Kommentar über jeder Deklaration
eine kurze Erklärung.
    
Die Funktion `skatBlatt()` erzeugt einen frischen, nicht gemischten Kartenstapel.
Diese Funktion ist in `maumau.cpp` bereits implementiert. Die anderen Funktionen sind dort nur deklariert und müssen von Ihnen umgesetzt werden.

## Aufgaben

- Implementieren Sie die oben vorgegebenen Funktionen.
- Implementieren Sie mit Hilfe der Funktionen ein Zwei-Spieler-Mau-Mau.  
  - Zunächst sollten Sie nur die Grundlogik implementieren, bei der die Spieler abwechselnd Karten legen, wobei geprüft wird, ob der Zug erlaubt ist.
  - Definieren Sie bei Bedarf weitere Hilfsfunktionen, die Ihnen sinnvoll erscheinen.
- Erweitern Sie das Spiel um:
  - neu mischen, wenn beim Ziehen der Kartenstapel leer ist.
  - mehrere Spieler
  - Sonderregeln (zwei ziehen bei 7, Aussetzen bei 8, Farbwunsch bei Bube)
    - Hinweis: Aussetzen bei 8 ist am einfachsten.
- Setzen Sie weitere Ideen und/oder andere Spiele um. Z.B.:
  - KI für Mau-Mau? Mehrere Spiele mit Punktetabelle?
  - Uno (Mau-Mau mit mehr Regeln und Sonderfällen).
  - BlackJack (17 und 4).