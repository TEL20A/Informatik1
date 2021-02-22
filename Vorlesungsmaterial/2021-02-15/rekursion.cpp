#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Prototypes
void foo(int k);
int add(int x, int y);
int fac(int n);
int fibn(int n);

int main(int argc, char *argv[])
{
   foo(42);
   cout << add(3, 2) << endl;
   cout << "fac(5): " << fac(5) << endl;
   cout << "fibn(1): " << fibn(1) << endl; // --> 1
   cout << "fibn(5): " << fibn(5) << endl; // --> 5
   cout << "fibn(8): " << fibn(8) << endl; // --> 21

   return EXIT_SUCCESS;
}

void foo(int k)
{
   if (k == 0)
   {
      return;
   }
   cout << k << endl;
   foo(k - 1);
}

int add(int x, int y)
{
   if (y == 0)
      return x; // x + 0 = x
   else
      return add(x, y - 1) + 1;
   // x + (y + 1) = (x + y) + 1
}

int fac(int n) {
   // 1,2,3, 4, 5
   // 1,2,6,24,120
   // 1*2*3*4*5
   if(n == 0)
      return 1;
   else
      return n*fac(n-1);
}

int fibn(int n){
   int ret = (n <= 2) ? 1 : fibn(n-2) + fibn(n-1);
   return ret;
}
