#include <gmpxx.h>
#include <iostream>
#include <vector>

int main()
{
   std::vector<std::vector<mpz_class>> Integers {{1,2},{34,45}};
//   Integers.push_back(1);
//   Integers.push_back(2);
//   Integers.push_back(34);
//   Integers.push_back(45);
   std::cout<<"Integers = (";
   size_t i =0;
   for (;i<2;i++) {
      std::cout<< "(";
      for(size_t j=0;j<2;j++) {
         std::cout<<Integers[i][j]<<",";
      }
      std::cout<<")";
   }
   std::cout<<")"<<std::endl;
   return 0;
}
