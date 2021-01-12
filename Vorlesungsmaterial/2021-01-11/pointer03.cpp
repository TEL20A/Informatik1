#include <iostream>

#define const_var 10

//Protoypen
void foo(int *const c_ptr);
void boo(int &ref_v);

int main()
{
   //Benutzung einer Referenz
   int x = 3;
   int &y = x;

   std::cout << x << y << std::endl;
   x = 4;
   std::cout << x << y << std::endl;
   y = 5;
   std::cout << x << y << std::endl;

   //Benutzung von Pointern
   int x2 = 3;
   int *ptr_y = &x2;

   std::cout << x2 << *ptr_y << std::endl;
   x2 = 4;
   std::cout << x2 << *ptr_y << std::endl;
   *ptr_y = 5;
   std::cout << x2 << *ptr_y << std::endl;

   //Benutzung von Konstanten
   const int c_var = 3;
   int c_x = 3;
   int c_y = 66;

   //konstanter pointer auf typ int
   //Äquivalent zu einer Referenz auf int, die Addresse kann nicht verändert werden
   int *const c_ptr_x = &c_x;

   //veränderbarer pointer
   int *v_ptr_x;
   v_ptr_x = &c_x;

   std::cout << c_var << std::endl;
   // c_var = 100; //--> Nicht erlaubt da const

   std::cout << *c_ptr_x << std::endl;
   *c_ptr_x = 4;
   std::cout << *c_ptr_x << std::endl;
   //c_ptr_x = &y; // Nicht erlaubt, der Speicherbereich auf den der Poiter zeigt kann nicht verändert werden

   std::cout << "* v_ptr_x: " << *v_ptr_x << std::endl;
   *v_ptr_x = 5;
   std::cout << "* v_ptr_x: " << *v_ptr_x << std::endl;
   v_ptr_x = &c_y;
   std::cout << "* v_ptr_x: " << *v_ptr_x << std::endl;

   //konstanter Pointer auf ein konstantes int, weder Addresse noch Inhalt können verändert werden
   const int *const cc_ptr_x = &c_x;

   //hier dürfen werden Addresse noch Inhalt verwendet werden
   // z.B. wenn man den Inhalt einer Variablen in einer Funktionen nur lesend zur Verfügung stellen möchte.
   //*cc_ptr_x = 5;
   //cc_ptr_x = &y;

   return 0;
}

// Foo verwendet einen konstanten Pointer
// die Addresse auf die dieser zeigt kann nicht verändert werden
void foo(int *const c_ptr)
{
   int foo_x = 5;
   std::cout << "foo(): *c_ptr: " << *c_ptr << std::endl;
   *c_ptr = 100;
   std::cout << "foo(): *c_ptr: " << *c_ptr << std::endl;
   //c_ptr = &foo_x; //Nicht erlaubt da const Pointer
}

// Verwenden einer Referenz hat das gleiche Resultat wie ein
// const Pointer, der Inhalt kann verändert werden aber nicht
// die Addresse der referenzierten Variable
void boo(int &ref_v)
{
   int foo_x = 5;
   std::cout << "boo(): ref_v: " << ref_v << std::endl;
   ref_v = foo_x; //lediglich der Inhalt (5) wird in der Referenz gespeichert
   std::cout << "boo(): ref_v: " << ref_v << std::endl;
}