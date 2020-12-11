#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Sucht das angegebene Wort in der Liste und liefert
// dessen Position zurück.
int suche(string suchwort, vector<string> liste)
{
  for (int i=0; i<liste.size(); i++)
  {
    if (liste[i] == suchwort)
    {
      return i;
    }
  }
  return liste.size();
}

// Für mehrere Rückgabe-Alternativen (z.B. in oder string):
// - Union
// - boost::variant

int main() {
  // Datenstrukturen
  vector<string> liste_deutsch = {"Auto", "Haus", "Wald"};
  vector<string> liste_englisch = {"Car", "House", "Forest"};
  string deutsch;

  // Benutzer nach einem deutschen Wort fragen.
  cout << "Welches Wort soll uebersetzt werden? ";
  cin >> deutsch;


  // Das entsprechende englische Wort ausgeben.

  // TODO: Kommt das Wort überhaupt vor?
  //       Was soll passieren, wenn es nicht vorkommt?

  // Suche das geforderte Wort in der deutschen Liste:
  int pos = suche(deutsch, liste_deutsch);

  // Gib das entsprechende Wort aus der englischen Liste aus.
  string englisch = liste_englisch[pos];
  cout << "Das englische Wort ist " << englisch << endl;

}









