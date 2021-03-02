#ifndef PRUEFUNG_H
#define PRUEFUNG_H

/** Diese Header-Datei enthaelt Hilfsfunktionen, Includes und
    Definitionen, die bei der Laborpruefung gebraucht werden.
**/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


/// Gibt einen Vektor auf der Konsole aus.
/// Variante fuer eindimensionalen Vektor.
template<typename T>
void print(vector<T> v)
{
    for (auto el : v)
    {
      cout << el << " ";
    }
    cout << endl;
}

/// Gibt einen Vektor auf der Konsole aus.
/// Variante fuer zweidimensionalen Vektor.
template<typename T>
void print(vector<vector<T>> v)
{
    for (auto el : v)
    {
      print(el);
    }
}

#endif
