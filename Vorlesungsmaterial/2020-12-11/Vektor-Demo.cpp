#include <iostream>
#include <vector>
using namespace std;

/* Nicht mehr notwendig, weil wir das Template ganz unten haben
/// Gibt einen int-Vektor aus
void print(vector<int> v)
{
  for (int i=0; i< v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

// Gibt einen double-Vektor aus
// (Überladung der anderen print-Funktion)
void print(vector<double> v)
{
  for (int i=0; i< v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
 */

// Gibt ein int-Array aus
// (Überladung der anderen print-Funktion)
void print(int v[])
{
  for (int i=0; i < 5; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

/// Gibt einen generischen Vektor aus
template <typename T>
void print(T v)
{
  for (auto element : v)
  {
    cout << element << " ";
  }
  cout << endl;
}

int main() {
  // Vektor aus int-Zahlen definieren.
  vector<int> v1 = {1,-3,5,7,38};
  print(v1);

  // Leeren Vektor erzeugen.
  vector<int> v2;
  //print(v2);

  // Vektor aus Kommazahlen definieren
  vector<double> v3 = {1.3,3,5,7.4,38.42};
  print(v3);

  // int-Array definieren (kein Vector).
  int v4 [] = {10,-3,5,7,38};
  print(v4);
}











