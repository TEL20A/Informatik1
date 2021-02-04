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
std::string str(Farbe f);

// Hilfsfunktion: Gibt zu einem Wert einen String zurück.
std::string str(Wert w);

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

// Mainfunktion mit Beispiel- bzw. Testcode.
int main() {
  // Erzeugt ein Skatblatt und gibt nacheinander alle Karten aus.
  vector<Spielkarte> blatt = skatBlatt();
  for (auto karte : blatt)
  {
    std::cout << str(karte.farbe) << " " << str(karte.wert) << endl;
  }
}

std::string str(Farbe f)
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

std::string str(Wert w)
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

  for (Farbe f : {KREUZ, PIK, HERZ, KARO})
  {
    for (Wert w : {SIEBEN, ACHT, NEUN, ZEHN, BUBE, DAME, KOENIG, ASS })
    {
      Spielkarte k{f,w};
      stapel.push_back(k);
    }
  }
  return stapel;
}
