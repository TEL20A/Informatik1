#include "pointer02.h"

void pointer02() {
  double dfeld[10] = {
    2.0, 3.5, -1.9, 4.6, 5.5,
    -6.7, 7.0, 8.2, -9.9, 10.0
  };

  //int laenge = sizeof(dfeld)/sizeof(double);
  int laenge = sizeof(dfeld)/sizeof(dfeld[0]);
  cout << "laenge: " << laenge << endl;
  cout << "Kleinster Wert von dfeld = " << findmin(dfeld ,laenge) << endl;
  cout << "Index vom kleinsten Wert von dfeld = " << findminindex(dfeld, laenge) << endl;
}

//double findmin(double * dfeld, int laenge) {
double findmin(double dfeld[], int laenge) {
  //Finde den kleinsten Wert in dfeld und gebe
  //diesen zurueck
  double min = dfeld[0];
  for(int i = 1; i < laenge; i++) {
    if (dfeld[i] < min) min = dfeld[i];
  }
  return min;
}

int findminindex(double * dfeld, int laenge) {
  //Finde den Index des kleinsten Wertes in dfeld und gebe
  //diesen zurueck
  int min_index = 0;
  for(int i = 1; i < laenge; i++) {
    if (dfeld[i] < dfeld[min_index]) min_index = i;
  }
  /*
  double min = dfeld[0];
  for(int i = 1; i < laenge; i++) {
    if (dfeld[i] < min) {
      min = dfeld[i];
      index = i;
    }
  }*/
  return min_index;
}
