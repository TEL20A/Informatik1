#include <iostream>
using namespace std;

int main()
{
   int x = 3;
   int *y = &x;

   cout << x << *y << endl;

   x = 4;
   cout << x << *y << endl;

   *y = 5;
   cout << x << *y << endl;

   std::cout << sizeof(int*) << std::endl;

   return 0;
}