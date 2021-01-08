#ifndef _POINTER02_
#define _POINTER02_

#include <iostream> //iostream wird in beiden Datein benötigt

/*
* Hier werden nur spezifische funktionen importiert
* und nicht der komplette namespace std
*/
using std::cout;
using std::endl;

//Prototypen
double findmin(double * dfeld, int laenge);
int findminindex(double * dfeld, int laenge);
void pointer02();

#endif /* _POINTER02_ */