#include <gmpxx.h>
#include <iostream>

int main ()
{
   mpz_class a=10, b=23;
   //mpz_class b (23);
   mpz_class mul = a*b;
   mpz_class sum = a+b;
   mpz_class sub = a-b;
   mpz_class div =a/b;
   mpz_class mod = b%a;
   std::cout<< "(a,b) = ("<<a<<","<<b<<")"<<std::endl;
   std::cout<< "(a*b) = "<< mul<<std::endl;
   std::cout<< "(a+b) = "<< sum<<std::endl;
   std::cout<< "(a-b) = "<< sub<<std::endl;
   std::cout<< "(a/b) = "<< div<<std::endl;
   std::cout<< "(b\%a) = "<< mod<<std::endl;
   return 0;

}
