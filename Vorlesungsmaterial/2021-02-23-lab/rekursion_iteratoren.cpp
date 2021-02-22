#include <iostream>
#include <vector>
using namespace std;

/// Liefert die Summe der Elemente im Bereich [begin, end[.
template<typename T>
int sum(T begin, T end);

/// Liefert das Produkt der Elemente im Bereich [begin, end[.
template<typename T>
int product(T begin, T end);

/// Liefert true, wenn der Bereich [begin, end[ ein Element x enthält.
template<typename T>
bool contains(T begin, T end, int x);

/// Liefert die Anzahl der Vorkommen von x im Bereich [begin, end[.
template<typename T>
int count(T begin, T end, int x);

/// Gibt den Bereich [begin, end[ auf der Konsole aus.
template<typename T>
void print(T begin, T end);

/// Liefert eine Kopie des Bereichs [begin, end[ als Vektor.
template<typename T>
vector<int> copy(T begin, T end);

/// Liefert den Bereich [begin, end[ rückwärts als Vektor.
template<typename T>
vector<int> reverse(T begin, T end);

/// Liefert die Elemente im Bereich [begin, end[ als Vektor,
/// die kleiner als p sind.
template<typename T>
vector<int> filterk(T begin, T end, int p);

int main() {
  vector<int> v1 = {1,2,3,4,5,2,3};

  cout << sum(v1.begin(), v1.end()) << endl; // Soll 20 ausgeben.
  cout << product(v1.begin(), v1.end()) << endl; // Soll 720 ausgeben.
  cout << contains(v1.begin(), v1.end(), 10) << endl; // Soll 0 ausgeben.
  cout << count(v1.begin(), v1.end(),3) << endl; // Soll 2 ausgeben.
  auto v2 = copy(v1.begin(), v1.end());
  print(v2.begin(), v2.end()); // Soll 1 2 3 4 5 2 3 ausgeben.
  auto v3 = reverse(v1.begin(), v1.end());
  print(v3.begin(), v3.end()); // Soll 3 2 5 4 3 2 1 ausgeben.
  auto v4 = filterk(v1.begin(), v1.end(),3);
  print(v4.begin(), v4.end()); // Soll 1 2 2 ausgeben.
}

template<typename T>
int sum(T begin, T end)
{
  if (begin == end) { return 0; }
  return *begin + sum(begin+1, end);
}

