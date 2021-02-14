#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <tuple>
using namespace std;

// Enum für die Farben von Spielkarten.
enum Farbe
{
  KREUZ, PIK, HERZ, KARO
};

// Enum für die Werte von Spielkarten.
enum Wert
{
  SIEBEN, ACHT, NEUN, ZEHN, BUBE, DAME, KOENIG, ASS
};

// Hilfsfunktion: Gibt zu einer Farbe einen String zurück.
string str(Farbe f);

// Hilfsfunktion: Gibt zu einem Wert einen String zurück.
string str(Wert w);

// Klasse für Spielkarten. Jede Karte besteht aus einer Farbe und einem Wert.
struct Spielkarte
{
  Farbe farbe;
  Wert wert;
};

/***********************************************
 * Typdefinitionen für Kartenstapel, Hand etc. *
 ***********************************************/
 using Stapel = std::vector<Spielkarte>;

/**********************************************************
 * Hilfsfunktionen für den Umgang mit Karten.             *
 * Dies ist sozusagen die Basisfunktionalität des Spiels. *
 **********************************************************/

/// Erzeugt ein frisches Skatblatt und liefert es zurück.
Stapel skatBlatt();

/// Erwartet einen Kartenstapel und gibt die Karten darin auf der Konsole aus.
void printStapel(Stapel const & stapel);

/// Erwartet einen Kartenstapel und mischt ihn. D.h. bringt die Karten in eine zufällige Reihenfolge.
/// Hinweis: Informieren Sie sich, wie man die Funktion rand() in C++ verwendet.
void mischen(Stapel & stapel);

/// Erwartet zwei Kartenstapel: Den allgemeinen Kartenstapel und einen Satz Handkarten. Zieht eine Karte vom Stapel in das Handblatt.
void ziehen(Stapel & stapel, Stapel & hand);

/// Erwartet zwei Kartenstapel: Den allgemeinen Kartenstapel und einen Satz Handkarten. Zieht 6 Karten vom Stapel in das Handblatt.
void geben(Stapel & stapel, Stapel & hand);

/// Erwartet zwei Karten. Liefert true, falls sie nach den Mau-Mau-Regeln aufeinander gelegt werden dürfen, ansonsten false.
bool passt(Spielkarte const & k1, Spielkarte const & k2);

/// Zeigt dem Spieler seine Karten sowie die oberste Karte vom Ablagestapel
/// und fragt ihn, welche er legen oder ob er ziehen möchte.
/// Prüft die Entscheidung des Spielers und führt sie durch.
void legen(string name, Stapel & kartenstapel, Stapel & ablagestapel, Stapel & hand);


/****************************************************
 * Hilfsfunktionen für die Durchführung des Spiels. *
 ****************************************************/

/// Erzeugt einen fertig gemischten Karten- und Ablagestapel für den Spielstart.
tuple<Stapel, Stapel> initKarten();

/// Erzeugt Spielernamen und deren Handkarten.
/// Gibt jedem Spieler 6 Karten, damit das Spiel starten kann.
tuple<vector<string>, vector<Stapel>> initSpieler(Stapel &, int anzahlSpieler);

/*******************************************************
 * Hilfsfunktionen für die Umsetzung von Sonderregeln. *
 *******************************************************/
 
/// Sorgt dafuer, dass der nächste Spieler übersprungen wird.
void aussetzen(int & aktuellerSpieler, vector<string> const & namen);

/// Sorgt dafür, dass der nächste Spieler zwei Karten ziehen muss.
void zweiZiehen(
  Stapel & kartenstapel,
  int & aktuellerSpieler,
  vector<string> const & namen,
  vector<Stapel> & haende);

/// Prueft, ob Sonderregeln angewendet werden können und wendet sie an.
void sonderRegelnAnwenden(
  Stapel & kartenstapel,
  Stapel & ablagestapel,
  int & aktuellerSpieler,
  vector<string> const & namen,
  vector<Stapel> & haende);

// Mainfunktion mit Beispiel- bzw. Testcode.
int main() {
  // Zufallsgenerator initialisieren.
  srand(time(nullptr));

  // Spielvorbereitung
  auto [kartenstapel, ablagestapel] = initKarten();
  auto [spieler, haende] = initSpieler(kartenstapel, 3);
  int aktueller_spieler = 0;
  bool fertig = false;

  // Game Loop
  while (!fertig)
  {
    string const name = spieler[aktueller_spieler];
    legen(name, kartenstapel, ablagestapel, haende[aktueller_spieler]);
    fertig = (haende[aktueller_spieler].empty());
    if (!fertig)
    {
      sonderRegelnAnwenden(kartenstapel, ablagestapel, aktueller_spieler, spieler, haende);
      aktueller_spieler = (aktueller_spieler + 1) % spieler.size();
    }
  }
}

string str(Farbe f)
{
  switch (f)
  {
    case KREUZ: return "Kreuz";
    case PIK: return "Pik";
    case HERZ: return "Herz";
    case KARO: return "Karo";
    default: break;
  }
  return "";
}

string str(Wert w)
{
  switch (w)
  {
    case SIEBEN: return "Sieben";
    case ACHT: return "Acht";
    case NEUN: return "Neun";
    case ZEHN: return "Zehn";
    case BUBE: return "Bube";
    case DAME: return "Dame";
    case KOENIG: return "König";
    case ASS: return "Ass";
    default: break;
  }
  return "";
}

Stapel skatBlatt()
{
  Stapel stapel;

  for (Farbe f : { KREUZ, PIK, HERZ, KARO })
  {
    for (Wert w : { SIEBEN, ACHT, NEUN, ZEHN, BUBE, DAME, KOENIG, ASS })
    {
      Spielkarte k{f,w};
      stapel.push_back(k);
    }
  }
  return stapel;
}


/* Implementierung der Hilfsfunktionen. */
void printStapel(Stapel const & stapel)
{
  for (int i = 0; i<stapel.size(); i++)
  {
    auto const & karte = stapel[i];
    cout << i << ": " << str(karte.farbe) << " " << str(karte.wert) << endl;
  }
}

void mischen(Stapel & stapel)
{
  // Das folgende "oft genug" machen (ein Vielfaches der Länge des Stapels):
  for (int i=0; i<stapel.size()*30; i++)
  {
    // Zwei Positionen innerhalb des stapels raten:
    int p1 = rand() % stapel.size();
    int p2 = rand() % stapel.size();

    // Die beiden Elemente stapel[p1] und stapel[p2] vertauschen:
    swap(stapel[p1], stapel[p2]);
  }
}

void ziehen(Stapel & stapel, Stapel & hand)
{
  hand.push_back(stapel.back());
  stapel.pop_back();
}

void geben(Stapel & stapel, Stapel & hand)
{
  for (int i = 0; i<=6; i++)
  {
    ziehen(stapel, hand);
  }
}

bool passt(Spielkarte const & k1, Spielkarte const & k2)
{
  return k1.farbe == k2.farbe || k1.wert == k2.wert;
}

void legen(string name, Stapel & kartenstapel, Stapel & ablagestapel, Stapel & hand)
{
  cout << name << ", Du bist am Zug." << endl;
  cout << "Deine Karten sind: " << endl;
  printStapel(hand);
  cout << endl;
  cout << "Die oberste Karte des Ablagestapels ist: ";
  cout << str(ablagestapel.back().farbe) << " " 
       << str(ablagestapel.back().wert) << "." << endl;
  cout << endl;
  cout << "Gib die Nummer der Karte ein, die du spielen willst";
  cout << " (" << hand.size() << " zum Ziehen): ";
  
  int input;
  cin >> input;

  if (input >= 0 && input <= hand.size())
  {
    if (input == hand.size())
    {
      ziehen(kartenstapel, hand);
      return;
    }
    else if (passt(hand[input], ablagestapel.back()))
    {
      ablagestapel.push_back(hand[input]);
      hand.erase(hand.begin()+input);
      return;
    }
  }
  cout << "Die gewählte Karte darf nicht gelegt werden." << endl << endl;
  legen(name, kartenstapel, ablagestapel, hand);
}

tuple<Stapel, Stapel> initKarten()
{
  Stapel kartenstapel = skatBlatt();
  Stapel ablagestapel;
  mischen(kartenstapel);
  ziehen(kartenstapel, ablagestapel);

  return { kartenstapel, ablagestapel };
}

tuple<vector<string>, vector<Stapel>> initSpieler(Stapel & kartenstapel, int anzahl)
{
  vector<string> namen;
  vector<Stapel> haende;
  for (int i=0; i<anzahl; i++)
  {
    string name = "Spieler " + to_string(i+1);
    namen.push_back(name);
    Stapel hand;
    geben(kartenstapel, hand);
    haende.push_back(hand);
  }
  return { namen, haende };
}

void aussetzen(int & aktuellerSpieler, vector<string> const & namen)
{
  aktuellerSpieler = (aktuellerSpieler + 1) % namen.size();
  cout << namen[aktuellerSpieler] << " muss aussetzen." << endl;
}

void zweiZiehen(
  Stapel & kartenstapel,
  int & aktuellerSpieler,
  vector<string> const & namen,
  vector<Stapel> & haende)
{
  int const naechsterSpieler = (aktuellerSpieler + 1) % namen.size();
  cout << namen[naechsterSpieler] << " muss 2 Karten Ziehen." << endl;
  ziehen(kartenstapel, haende[naechsterSpieler]);
  ziehen(kartenstapel, haende[naechsterSpieler]);
}

void sonderRegelnAnwenden(
  Stapel & kartenstapel,
  Stapel & ablagestapel,
  int & aktuellerSpieler,
  vector<string> const & namen,
  vector<Stapel> & haende)
{
  Spielkarte karte = ablagestapel.back();
  switch (karte.wert)
  {
    case SIEBEN:
      zweiZiehen(kartenstapel, aktuellerSpieler, namen, haende); 
      break;
    case ACHT:
      aussetzen(aktuellerSpieler, namen);
      break;
    default:
      break;
  }
}