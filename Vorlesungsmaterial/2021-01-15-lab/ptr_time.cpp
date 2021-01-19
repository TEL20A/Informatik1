#include <vector>
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>


void print_mem(std::string str="") {
  std::cout << str << std::endl;
  system("ps -o pid,user,%mem,command | sort -b -k3 | grep ./time.out");
}

void v_call(std::vector<int> vec) {
   print_mem("V_call:");
}
void r_call(std::vector<int> &vec) {
   print_mem("r_call:");
}

int main(int argc, char *argv[])
{
   clock_t t;  // Init der var t vom Tp clock_t
   t = clock();
   // Großen Vector erzeugen
   std::vector<int> vec;
   for (int i = 0; i < 100000000; i++)
      vec.push_back(i);
   t = clock() - t;
   std::cout << "It took " << (int)t/CLOCKS_PER_SEC << " seconds to create the vector\n";
   std::cout << "t = " << t << std::endl;
   print_mem("Vector created:");
   // Beide Aufrufe haben den gleichen Effekt:
   t = clock();
   v_call(vec); // langsam (v wird kopiert)
   t = clock() - t;
   std::cout << "It took " << (float)t/CLOCKS_PER_SEC << " seconds to copy the vector\n";

   t = clock();
   r_call(vec); // schnell (keine Kopie)
   t = clock() - t;
   std::cout << "It took " << (float)t/CLOCKS_PER_SEC << " seconds to reference the vector\n";

   return 0;
}