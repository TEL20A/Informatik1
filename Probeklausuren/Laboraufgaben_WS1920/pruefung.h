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
/// Variante fuer zweidimensionalen Vektor.
template<typename T>
void print_vector(vector<vector<T>> v)
{
    for (int i=0; i<v.size(); i++)
    {
        for (int j=0; j<v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

#endif
