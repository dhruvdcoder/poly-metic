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
#include <boost/numeric/ublas/matrix.hpp>
#include "../include/Polynomial.ipp"
#include <gmpxx.h>
#include <iostream>
int main()
{
   using namespace boost::numeric::ublas;
   using coefT = mpz_class;
   using entryT= Polynomial<coefT>;
   entryT p1 {1,2,3};
   entryT p2 {4,5,6};
   entryT p3 {1};
   entryT p4 {7,8,9,10};
   matrix<entryT> m (2,2);
   m(0,0)=p1;
   m(0,1)=p2;
   m(1,0)=p3;
   m(1,1)=p4;
   std::cout<<"m(0,0)= "<<m(0,0)<<std::endl;
   std::cout<<"m(0,1)= "<<m(0,1)<<std::endl;
   std::cout<<"m(1,0)= "<<m(1,0)<<std::endl;
   std::cout<<"m(1,1)= "<<m(1,1)<<std::endl;

   matrix<entryT> m2 (2,2);
   m2 = prod(m,m);
   std::cout<<"m2=m*m"<<std::endl;
   std::cout<<"m2(0,0)= "<<m2(0,0)<<std::endl;
   std::cout<<"m2(0,1)= "<<m2(0,1)<<std::endl;
   std::cout<<"m2(1,0)= "<<m2(1,0)<<std::endl;
   std::cout<<"m2(1,1)= "<<m2(1,1)<<std::endl;


   return 0;
}
