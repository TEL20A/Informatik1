#include <iostream>
using namespace std;

int main()
{
   int x = 42;
   {
      int x = 2;
      {
         int x = 4;
         {
            int x = 6;
            cout << x << endl;
         }
         cout << x << endl;
      }
      cout << x << endl;
   }
   cout << x << endl;
}