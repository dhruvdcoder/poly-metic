//   Copyright 2018 Dhruvesh Nikhilkumar Patel
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//
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
