#include <iostream>
#include <vector>
#include <string>
using namespace std;

using Spielfeld = vector<string>;

void print(Spielfeld const & feld)
{
  for (auto const & zeile : feld)
  {
    for (char c : zeile)
    {
      cout << "| " << c << " ";
    }
    cout << "|" << endl;
  }
  cout << endl;
}

/// Das Problem ist geloest, sobald das Feld quadratisch ist.
/// Idee: Diese Funktion wird immer direkt nach dem Platzieren
/// einer Dame aufgerufen. Wenn es gelungen ist, eine Dame in
/// einem quadratischen Feld zu platzieren, sind wir fertig.
bool done(Spielfeld const & feld)
{
  return !feld.empty() && (feld.size() == feld[0].size());
}

/// Prueft, ob es erlaubt ist, in der letzten Zeile in der
/// angegebenen Spalte eine Dame zu platzieren.
bool erlaubt(Spielfeld const & feld, int spalte)
{
  if (feld.empty()) { return false; }
  int zeile = feld.size()-1;

  // Spalte pruefen:
  for (int y=zeile-1; y>= 0; --y)
  {
    if (feld[y][spalte] != ' ') { return false; }
  }

  // Diagonale nach links oben pruefen:
  {
    int y = zeile-1;
    int x = spalte-1;
    while (x >= 0 && y >= 0)
    {
      if (feld[y][x] != ' ') { return false; }
      y--;
      x--;
    }
  }

  // Diagonale nach rechts oben pruefen:
  {
    int y = zeile-1;
    int x = spalte+1;
    while (x < feld[0].size() && y >= 0)
    {
      if (feld[y][x] != ' ') { return false; }
      y--;
      x++;
    }
  }
  return true;
}

bool solve(Spielfeld & feld)
{
  if (done(feld)) { return true; }

  feld.push_back(string(8, ' '));
  for (int i=0; i<feld.back().size(); i++)
  {
    if (erlaubt(feld, i))
    {
      feld.back()[i] = 'D';
      bool geloest = solve(feld);
      if (geloest) { return true; }
      feld.back()[i] = ' ';
    }
  }
  feld.pop_back();
  return false;
}

int main()
{
  Spielfeld feld;
  if(solve(feld))
  {
    print(feld);
  }
}