#include <iostream>
using namespace std;

/// Liefert die Summe der Zahlen von 1 bis n.
int summe_bis(int n);

/// Liefert die Summe der Zahlen von n1 bis n2.
int summe_von_bis(int n1, int n2);

/// Liefert das Ergebnis der ganzzahligen Division von n durch k.
int geteilt(int n, int k);

/// Liefert den Rest der ganzzahligen Division von n durch k.
int rest(int n, int k);

/// Liefert true, falls n durch k teilbar ist.
bool teilbar(int n, int k);

/// Liefert den größten gemeinsamen Teiler von a und b.
/// Hinweis: Es gilt immer ggT(a,b) = ggT(b, a-b)
int ggT(int a, int b);

/// Liefert die Anzahl der Teiler von n, die zwischen 1 und i liegen.
int anzahl_teiler(int n, int i);

/// Liefert true, wenn n eine Primzahl ist.
bool prim(int n);

int main() {

  cout << summe_bis(5) << endl; // Soll 1+2+3+4+5 == 15 ausgeben.
  cout << summe_von_bis(3, 5) << endl; // Soll 3+4+5 == 12 ausgeben.
  cout << geteilt(17, 4) << endl; // Soll 4 ausgeben.
  cout << rest(17, 4) << endl; // Soll 1 ausgeben.
  cout << teilbar(17, 4) << endl; // Soll 0 ausgeben.
  cout << ggT(60,24) << endl; // Soll 12 ausgeben.
  cout << anzahl_teiler(12,10) << endl; // Soll 5 ausgeben.
  cout << prim(4) << endl; // Soll 0 ausgeben.
}

