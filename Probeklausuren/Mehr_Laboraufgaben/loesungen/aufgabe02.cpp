#include "pruefung.h"

/*** AUFGABE: Permutationen eines Arrays ***/

/*** AUFGABENSTELLUNG:
    Schreiben Sie eine Funktion permutationen, die eine Liste von Zahlen erwartet.
    
    Die Funktion soll alle Permutationen der Liste liefern.
    D.h. eine Liste mit Vektoren, bei dem jeder einzelne Vektor eine Permutation (also eine Vertauschung) der Elemente ist.
***/
vector<vector<int>> permutationen(vector<int> liste);


/*** TESTCODE/MAIN ***/
int main() {
    
    vector<int> v1 = {1,2,3};
    print(permutationen(v1)); // Soll alle Varianten 1 2 3, 1 3 2, 2 3 1, ... ausgeben.
    
    return 0;
}

/*** LOESUNG ***/
vector<vector<int>> permutationen(vector<int> liste)
{
  vector<vector<int>> result;
  if (liste.empty())
  {
    return {};
  }
  if (liste.size() == 1)
  {
    return {liste};
  }
  
  int s = liste.size();
  for (int i = 0; i<s; i++)
  {
    // Erstes Element merken und löschen.
    int front = liste.front();
    liste.erase(liste.begin());

    // Permutationen der restlichen Liste holen
    auto perms = permutationen(liste);

    // Gemerktes erstes Element an jede der Rest-Permutationen anhängen
    // und diese dann ans Ergebnis anhängen.
    for (auto p : perms)
    {
      p.push_back(front);
      result.push_back(p);
    }

    // Erstes Element hinten wieder an die Liste anhängen.
    liste.push_back(front);
  }

  return result;
}
