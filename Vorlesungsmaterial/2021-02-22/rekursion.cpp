#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Ausgabe des Vektors ohne Schleifen.
void print1(vector<int> v, int i=0)
{
  // Abbruchbedingung: Bei ungueltigem i machen wir nichts.
  if (i == v.size()) { return; }

  // Rekursiver Aufruf für den Rest der Liste.
  print1(v, i+1);

  // Erstes Element ausgeben
  cout << v[i] << " ";
}

void print2(vector<int> v)
{
  if (v.empty()) { return; }

  // Erstes Element merken:
  int x = v[0];

  // Erstes Element löschen
  v.erase(v.begin());

  // Den Rest ausgeben
  print2(v);

  cout << x << " ";
}

void print3(vector<int> v)
{
  if (v.empty()) { return; }

  // Erstes Element merken:
  int x = v.back();
  cout << x << " ";

  // Erstes Element löschen
  v.pop_back();

  // Den Rest ausgeben
  print3(v);

}

int main() {
  vector<int> v1 = { 3,5,2,17,12,23,42 };

  print3(v1);

  cout << endl;
}