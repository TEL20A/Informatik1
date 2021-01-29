#include <iostream>
#include <vector>
using namespace std;

// Hilfsfunktion zur Ausgabe eines Vektors.
// Funktioniert mit allen Vektoren, deren
// Elemente man per cout ausgeben kann.
template <typename T>
void print(vector<T> const & v);

// Hilfsfunktionen für selectionSort

// Soll im Vektor `v` die Elemente an den Stellen `i` und `j` miteinander vertauschen.
void swap(vector<int> & v, int i, int j); 

// Soll im Vektor `v` ab Stelle `i` das kleinste Element suchen und dessen Position zurückgeben. 
int select(vector<int> & v, int i);

//Soll den Vektor `v` mit dem Verfahren `SelectionSort` sortieren.
void selectionSort(vector<int> & v);


int main()
{
  // Test-Vector:
  vector<int> v1 = {17,5,12,1,23,42,2,38};

  // Vektor ausgeben, Funktion anwenden und erneut ausgeben:
  print(v1);
  //selectionSort(v1);
  print(v1);
  
  /* Anmerkung:
  Der Aufruf von bubbleSort() ist noch auskommentiert, da die Funktion noch nicht implementiert ist. Sobald Sie sie implementiert haben, können Sie den Aufruf einkommentieren, um die Funktion zu testen. Sie können (und sollten) zwischendurch auch geeignete Aufrufe der Hilfsfunktionen einbauen, um diese zu testen.
  */
  
  return 0;
}


// Hilfsfunktion zu Ausgabe eines Vektors.
// Funktioniert mit allen Vektoren, deren
// Elemente man per cout ausgeben kann.
template <typename T>
void print(vector<T> const & v)
{
  for (T el : v)
  {
    cout << el << " ";
  }
  cout << endl;
}