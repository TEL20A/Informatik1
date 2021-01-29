#include <iostream>
#include <vector>
using namespace std;

// Hilfsfunktion zur Ausgabe eines Vektors.
// Funktioniert mit allen Vektoren, deren
// Elemente man per cout ausgeben kann.
template <typename T>
void print(vector<T> const & v);

// Hilfsfunktionen für bubbleSort

// Soll im Vektor `v` die Elemente an den Stellen `i` und `j` miteinander vertauschen.
void swap(vector<int> & v, int i, int j); 

// Soll im Vektor `v` die Elemente an den Stellen `i` und `j` miteinander vergleichen und sie vertauschen, falls sie falsch herum sortiert sind. 
void compareAndSwap(vector<int> & v, int i, int j);  
  
// Soll im Vektor `v` einen Durchlauf wie oben beschrieben machen, so dass größere Elemente Richtung Ende wandern.
void bubbleUp(vector<int> & v);

//Soll den Vektor `v` mit dem Verfahren `BubbleSort` sortieren.
void bubbleSort(vector<int> & v);


int main()
{
  // Test-Vector:
  vector<int> v1 = {17,5,12,1,23,42,2,38};

  // Vektor ausgeben, Funktion anwenden und erneut ausgeben:
  print(v1);
  //bubbleSort(v1);
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