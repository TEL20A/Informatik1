#include <iostream>
#include <vector>
using namespace std;

// Deklaration der Funktion sort().
// Signatur / Prototyp / Kopf der Funktion
// Soll den als Referenz übergebenen Vektor aufsteigend sortieren.
void sort(vector<int> & v);

// Hilsfunktion zum Sortieren:
// Verschiebt das größte Element ans Ende der Liste.
// (Die restlichen Elemente können dabei auch umsortiert werden)
void largest_to_end(vector<int> & v);

// Hilfsfunktion:
// Vergleicht die beiden Elemente an Stelle i und i+1 und vertauscht sie,
// falls sie nicht in der richtigen Reihenfolge stehen
void compare_and_swap(vector<int> & v, int i);


int main() {
  vector<int> v1 = {5,3,2,17,25,42,38};

  for (int el : v1)
  {
    cout << el << " ";
  }
  cout << endl;

  sort(v1);

  for (int el : v1)
  {
    cout << el << " ";
  }
  cout << endl;

  return 0;
}

// Definition der Funktion sort().
void sort(vector<int> & v)
{
  
}