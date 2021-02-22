#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hilfsfunktion für Tests:
// Erwartet zwei beliebige Vektoren und vergleicht diese.
// Liefert true, wenn die Vektoren gleich sind, sonst false.
template <typename T>
bool compare(vector<T> const & v1, vector<T> const & v2);

// Filtert den gegebenen Vektor aus Wörtern und liefert einen
// neuen Vektor, der nur die Wörter enthält, die mit 'A' anfangen.
vector<string> filterA(vector<string> const &);

// Filtert den gegebenen Vektor aus Wörtern und liefert einen
// neuen Vektor, der nur die Wörter enthält, deren Länge 3 ist.
vector<string> filter3(vector<string> const &);

// Filtert den gegebenen Vektor aus Zahlen und liefert einen
// neuen Vektor, der nur die Werte enthält, größer als 0 sind.
vector<int> filterGroesser0(vector<int> const &);

int main() {
  vector<string> v1 = {
    "Auto",
    "Fahrrad",
    "Acker",
    "Baum",
    "Zange",
    "Rad"
  };

  vector<string> v2 = filterA(v1);
  if (!compare(v2, {"Auto", "Acker"}))
  {
    cout << "Fehler: Das Ergebnis von filter() entspricht nicht dem erwarteten Wert." << endl;
  }

  vector<string> v3 = filter3(v1);
  if (!compare(v3, {"Rad"}))
  {
    cout << "Fehler: Das Ergebnis von filter() entspricht nicht dem erwarteten Wert." << endl;
  }

  vector<int> v4 = {3, 2, -1, 5, 0, -15, -42, 38};
  vector<int> v5 = filterGroesser0(v4);
  if (!compare(v5, {3, 2, 5, 38}))
  {
    cout << "Fehler: Das Ergebnis von filter() entspricht nicht dem erwarteten Wert." << endl;
  }

}

template <typename T>
bool compare(vector<T> const & v1, vector<T> const & v2)
{
  // Sonderfall: Zwei unterschiedlich lange Vektoren sind auf keinen Fall gleich.
  if (v1.size() != v2.size()) { return false; }

  // Die beiden Vektoren elementweise vergleichen:
  for (int i = 0; i < v1.size(); i++)
  {
    // Early out, falls zwei unterschiedliche Elemente gefunden wurden.
    if (v1[i] != v2[i]) { return false; }
  }
  return true;
}



vector<string> filterA(vector<string> const & v)
{
  vector<string> result;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i][0] == 'A')
    {
      result.push_back(v[i]);
    }
  }
  return result;
}

vector<string> filter3(vector<string> const & v)
{
  vector<string> result;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i].size() == 3)
    {
      result.push_back(v[i]);
    }
  }
  return result;
}

vector<int> filterGroesser0(vector<int> const & v)
{
  vector<int> result;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] > 0)
    {
      result.push_back(v[i]);
    }
  }
  return result;
}















