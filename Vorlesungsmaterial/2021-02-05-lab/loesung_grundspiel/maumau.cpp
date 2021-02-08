#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
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

// Hilfsfunktion: Erzeugt ein frisches Skatblatt und liefert es zurück.
vector<Spielkarte> skatBlatt();

/* Aufgaben
 * 
 * - Implementieren Sie die folgenden Funktionen.
 * - Implementieren Sie mit Hilfe der Funktionen ein Zwei-Spieler-Mau-Mau.
 *   Zunächst sollten Sie nur die Grundlogik implementieren, bei der
 *   die Spieler abwechselnd Karten legen, wobei geprüft wird, ob der Zug *   erlaubt ist.
 * - Erweitern Sie das Spiel um:
 *   - neu mischen, wenn beim Ziehen der Kartenstapel leer ist.
 *   - mehrere Spieler
 *   - Sonderregeln (zwei ziehen bei 7, Aussetzen bei 8, Farbwunsch bei Bube)
 *     - Hinweis: Aussetzen bei 8 ist am einfachsten.
 * - Setzen Sie weitere Ideen und/oder andere Spiele um. Z.B.:
 *   - KI für Mau-Mau? Mehrere Spiele mit Punktetabelle?
 *   - Uno (Mau-Mau mit mehr Regeln und Sonderfällen).
 *   - BlackJack (17 und 4).
 */

// Erwartet einen Kartenstapel und gibt die Karten darin auf der Konsole aus.
void printStapel(vector<Spielkarte> const & stapel);

// Erwartet einen Kartenstapel und mischt ihn. D.h. bringt die Karten in eine zufällige Reihenfolge.
// Hinweis: Informieren Sie sich, wie man die Funktion rand() in C++ verwendet.
void mischen(vector<Spielkarte> & stapel);

// Erwartet zwei Kartenstapel: Den allgemeinen Kartenstapel und einen Satz Handkarten. Zieht eine Karte vom Stapel in das Handblatt.
void ziehen(vector<Spielkarte> & stapel, vector<Spielkarte> & hand);

// Erwartet zwei Kartenstapel: Den allgemeinen Kartenstapel und einen Satz Handkarten. Zieht 6 Karten vom Stapel in das Handblatt.
void geben(vector<Spielkarte> & stapel, vector<Spielkarte> & hand);

// Erwartet zwei Karten. Liefert true, falls sie nach den Mau-Mau-Regeln aufeinander gelegt werden dürfen, ansonsten false.
bool passt(Spielkarte const & k1, Spielkarte const & k2);

// Zeigt dem Spieler seine Karten sowie die oberste Karte vom Ablagestapel
// und fragt ihn, welche er legen oder ob er ziehen möchte.
// Prüft die Entscheidung des Spielers und führt sie durch.
void legen(string name, vector<Spielkarte> & kartenstapel, vector<Spielkarte> & ablagestapel, vector<Spielkarte> & hand);

// Mainfunktion mit Beispiel- bzw. Testcode.
int main() {
  // Zufallsgenerator initialisieren, damit der Aufruf von rand()
  // in mischen() funktioniert und wirklich zufällig ist.
  srand(time(nullptr));

  // Erzeugt ein Skatblatt und gibt nacheinander alle Karten aus.
  vector<Spielkarte> blatt = skatBlatt();

  printStapel(blatt);
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

vector<Spielkarte> skatBlatt()
{
  vector<Spielkarte> stapel;

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


/* Lösungen für die Funktionen aus den Aufgaben. 
 * Warnung: diese Funktionen sind bisher noch ungetestet, können also noch Fehler enthalten.
 */

void printStapel(vector<Spielkarte> const & stapel)
{
  for (auto karte : stapel)
  {
    cout << str(karte.farbe) << " " << str(karte.wert) << endl;
  }
}

// Erwartet einen Kartenstapel und mischt ihn. D.h. bringt die Karten in eine zufällige Reihenfolge.
// Hinweis: Informieren Sie sich, wie man die Funktion rand() in C++ verwendet.
void mischen(vector<Spielkarte> & stapel)
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

  // Anmerkung: Wir verwenden einfach die Funktion std::swap().
  // Alternativ hätte man die Elemente auch mittels einer Hilfsvariable
  // "von Hand" vertauschen können. Es ist aber generell besser, Funktionen
  // aus der Standardbibliothek zu verwenden, wenn sie verfügbar sind.
  // Noch besser wäre einfach std::shuffle() gewesen. Aufgrund meines Hinweises
  // auf rand() sowie dessen allgemeinem Nuten zeige ich hier aber nun auch rand().
}

// Erwartet zwei Kartenstapel: Den allgemeinen Kartenstapel und einen Satz Handkarten. Zieht eine Karte vom Stapel in das Handblatt.
void ziehen(vector<Spielkarte> & stapel, vector<Spielkarte> & hand)
{
  hand.push_back(stapel.back());
  stapel.pop_back();
}

// Erwartet zwei Kartenstapel: Den allgemeinen Kartenstapel und einen Satz Handkarten. Zieht 6 Karten vom Stapel in das Handblatt.
void geben(vector<Spielkarte> & stapel, vector<Spielkarte> & hand)
{
  for (int i = 0; i<=6; i++)
  {
    ziehen(stapel, hand);
  }
}

// Erwartet zwei Karten. Liefert true, falls sie nach den Mau-Mau-Regeln aufeinander gelegt werden dürfen, ansonsten false.
bool passt(Spielkarte const & k1, Spielkarte const & k2)
{
  return k1.farbe == k2.farbe || k1.wert == k2.wert;
}

// Zeigt dem Spieler seine Karten sowie die oberste Karte vom Ablagestapel
// und fragt ihn, welche er legen oder ob er ziehen möchte.
// Prüft die Entscheidung des Spielers und führt sie durch.
void legen(string name, vector<Spielkarte> & kartenstapel, vector<Spielkarte> & ablagestapel, vector<Spielkarte> & hand)
{
  cout << name << ", Du bist am Zug." << endl;
  cout << "Deine Karten sind: " << endl;
  printStapel(hand);
  cout << endl;
  cout << "Die oberste Karte des Ablagestapels ist: ";
  cout << str(ablagestapel.back().farbe) << " " 
       << str(ablagestapel.back().wert) << "." << endl;
  cout << endl;
  cout << "Gibt die Nummer der Karte ein, die du spielen willst";
  cout << " (" << hand.size() << "zum Ziehen.): ";
  
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