#include <vector>
#include <ctime>
#include <string>
#include <iostream>
#include <unistd.h>

void print_mem(std::string str="") {
  std::cout << str << std::endl;
  system("ps -o pid,user,%mem,command ax | sort -b -k3 -r | grep './main' ");
}

void v_call2(std::vector<int> vec) {print_mem("v_call2");}
void v_call(std::vector<int> vec) {
  print_mem("v_call:");
    v_call2(vec);
}
void r_call2(std::vector<int> &vec) {print_mem("r_call2");}
void r_call(std::vector<int> &vec) {
  print_mem("r_call:");
    r_call2(vec);
}

int main()
{
   clock_t t = clock();
   // Großen Vector erzeugen
   std::vector<int> vec;
   for (int i = 0; i < 100000000; i++)
      vec.push_back(i);
   t = clock() - t;
   std::cout << "It took " << (float)t/CLOCKS_PER_SEC << " seconds to create the vector\n";

   // Beide Aufrufe haben den gleichen Effekt:
   t = clock();
   print_mem("Vor v_call");
   v_call(vec); // langsam (v wird kopiert)
   print_mem("Nach v_call");
   t = clock() - t;
   std::cout << "It took " << (float)t/CLOCKS_PER_SEC << " seconds to copy the vector\n";

   t = clock();
   print_mem("Vor r_call");
   r_call(vec); // schnell (keine Kopie)
   t = clock() - t;
   print_mem("Nach r_call");
   std::cout << "It took " << (float)t/CLOCKS_PER_SEC << " seconds to reference the vector\n";

   print_mem();
   //std::cout << "Sleep\n";
   //usleep(160000000);
   //std::cout << "Sleep done\n";

   return 0;
}