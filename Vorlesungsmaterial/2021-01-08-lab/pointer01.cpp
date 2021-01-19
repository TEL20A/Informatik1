#include "pointer02.h"


// Präprozessordirektiven
#define scope
#define ptr_teil1 0
#define ptr_teil2 1
#define my_macro localVar

//global Variables
#ifdef scope
double globVar;

namespace Scope {
  double s = 1;
}
#endif /* scope */


/**
 * Hauptprogramm
 */
int main(int argc, char*argv[])
{
#ifdef scope
  double locVar = 0;
  cout << endl;
  cout << "globVar: " << globVar << endl;
  cout << "locVar: " << locVar << endl;
  cout << "Scope::s " << Scope::s << endl;
  cout << endl;
  if (true) {
    double locVar{3.14}; // locVar = 3.14
    cout << "locVar if: " << locVar << endl;
  }
  cout << "locVar: " << locVar << endl;
  cout << endl;
#endif /* scope */

#if ptr_teil1

	int a = 0x25; // dezimal 37 (0x --> hexadezimal)
	int* i1_ptr, i2_ptr; // !!! i2_ptr ist KEIN Zeiger!!!
	double *d1_ptr, * d2_ptr; // **Beide** sind Zeiger!

	cout <<"Erste Schritte mit Zeigern\n";
  cout << "a= " << a << endl;
  cout << "a= 0x" << std::hex << a << endl;
	// i1_ptr  als nullpointer
	i1_ptr = nullptr;
  cout << "i1_ptr = "<< i1_ptr << endl;

  // Den Zeiger auf eine int-Variable setzen (=zeigen lassen)
	i1_ptr = &a; // a wird ***referenziert***
  cout << "Adresse von a: " << &a << endl;
  cout << "i1_ptr = "  << i1_ptr << endl;

	// Wo ist denn i1_ptr gespeichert?
	cout << "&i1_ptr = " << &i1_ptr << "\n";

	// Inhalt der Variablen, auf die der Zeiger
	//  zeigt, ausgeben	(i1_ptr wird ***dereferenziert***)
	printf("Dereferenzieren: *i1_ptr = %d\n", *i1_ptr);
  cout << "\na= " << a << endl;
  *i1_ptr = 0x15;
  cout << "a = " << a << "\n*i1_ptr = " << *i1_ptr << endl;
	cout << "\nGroesse eines Zeigers: sizeof(i1_ptr) = " << sizeof(i1_ptr) << endl;
	cout << "Groesse eines Zeigerinhalts(int): sizeof(*i1_ptr) = " << sizeof(*i1_ptr) << endl;

	// a mittels des Zeigers aendern
	*i1_ptr = 2;
	// So ***NICHT***:
	// &i1_ptr = 2; // ***NEIN***

	// a hat sich geaendert:
	cout << "a = " << a << endl;
	// ... oder natuerlich so zugreifen:
	cout << "Dereferenzieren: *i1_ptr = " << *i1_ptr << endl;


  //falscher typecast
  double d1 = 1.25;
  //d1_ptr = i1_ptr; // ***NEIN** funktioniert nicht

  d2_ptr = &d1;
  cout << "*d2_ptr = " << *d2_ptr << endl;
  cout << "&d2_ptr = " << &d2_ptr << endl;
  cout << "sizeof(d2_ptr) = " << sizeof(d2_ptr) << endl;
  cout << "sizeof(*d2_ptr) = " << sizeof(*d2_ptr) << endl;
  cout << "sizeof(double) = " << sizeof(double) << endl;
  cout << "sizeof(int) = " << sizeof(int) << endl;
  cout << "sizeof(char) = " << sizeof(char) << endl;
  cout << "sizeof(char*) = " << sizeof(char*) << endl;
  cout << "sizeof(int*) = " << sizeof(int*) << endl;

  // i1_ptr = d1_ptr; // VORSICHT: man darf keine anderen pointer typen zuweisen

  //void pointer
  void* v_ptr;
  v_ptr = (double *) (d2_ptr);
  // v_ptr = static_cast<double *>(d2_ptr);
  cout << "*(double *) v_ptr = " << *(double *)v_ptr << endl;

  //Vorsicht beim Umgang mit Pointern
  int * b = &a;
  cout << "\n*b = " << *b << endl;
  b++;
  cout << "*b = " << *b << endl; // Krawumm!!


  // return types
  cout << "EXIT_SUCCESS: " << EXIT_SUCCESS << endl;
  cout << "EXIT_FAILURE: " << EXIT_FAILURE << endl;

  // Umgang mit cArrays, Beispiele
  double dfeld[10] = {
		2.0, 3.5, -1.9, 4.6, 5.5,
		-6.7, 7.0, 8.2, -9.9, 10.0
	};
  //*(dfeld+0) = dfeld[0];
  cout << (dfeld) << endl;
  cout << &dfeld[0] << endl;
  cout << (dfeld+1) << endl;
  cout << &dfeld[1] << endl;
  cout << (dfeld+2) << endl;
  cout << &dfeld[2] << endl;
  cout << (dfeld+3) << endl;
  cout << &dfeld[3] << endl;
  cout << *(dfeld+3) << endl;
  cout << dfeld[3] << endl;

#elif ptr_teil2
  pointer02();
#endif /* ptr_teil1*/
	return EXIT_SUCCESS;
} // main
