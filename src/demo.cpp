/** \brief This file demonstrates the top-level funtionalities of the Polynomial class
 */
#include "../include/Polynomial.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

void print_help() {
   std::cout<< "Enter number of coefficients followed by the values for two polynomials. For example:" <<std::endl;
   std::cout<< "if p1 = 2x^3 + x and p2 = x^2 - 10x + 1,\nthen enter 4 0 1 0 2 3 1 -10 1" <<std::endl;
}

int main(int argc, char* argv[]) 
{  

   /* use field as double for now */
   using FieldType = double;
   /* process the inputs */
   Polynomial<FieldType> p1;
   Polynomial<FieldType> p2;
   if ( argc > 2) {
      try {
         size_t number_of_coeffs_p1 = std::stoul(argv[1]);
         size_t idx = 1;
         if ((size_t)argc < idx + number_of_coeffs_p1 +1) throw std::invalid_argument("Invalid number of inputs supplied");
         for (size_t i= 0; i < number_of_coeffs_p1; ++i) {
            p1.appendTerm(std::stod(argv[++idx]));
         }

         size_t number_of_coeffs_p2 = std::stoul(argv[++idx]); 
         if ((size_t)argc < idx + number_of_coeffs_p2 + 1) throw std::invalid_argument("Invalid number of inputs supplied");
         for (size_t i= 0; i < number_of_coeffs_p2; ++i) {
            p2.appendTerm(std::stod(argv[++idx]));
         }
      }
      catch (std::invalid_argument& e) {
         std::cout << e.what() <<std::endl;
         print_help();
         return 1;
      } 
   }
   else {
     print_help(); 
   }

   /* add the polynomial */
   Polynomial<FieldType> padd = p1+p2; 
   std::cout<<"Addition:p1+p2\n"<<padd<<std::endl;
   /* subtract the polynomial */
   Polynomial<FieldType> psub = p1-p2; 
   std::cout<<"Subtraction:p1-p2\n"<<psub<<std::endl;

   return 0;
}
