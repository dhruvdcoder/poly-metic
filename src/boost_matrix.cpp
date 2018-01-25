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
