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
/** \file Polynomial.cpp
 *  \brief The file contains the explicit intantiations of the template class Polynomial.
 *
 * It defines/instantiates the Polynomial class for the following types
 *
 * -# double
 * -# mpz_class (GMP Integers)
 * -# mpq_class (GMP Rationals)
 * -# mpf_class (GMP Floats)
 * 
 *  One must link with the object code of this file to use the Polynomial class with the above types.
 *  If one wishes to instantiate the Polynomial class with any other template argument, then one should include "Polynomial.ipp" header file as it contains the implementations of the member functions of the template class Polynomial.
 */

#include "../include/Polynomial.ipp"
#include <gmpxx.h>


/******************** Explicit template "instantiations/definitions" ******************************/
template
class Polynomial <double>; 
template
Polynomial<double> operator*(const Polynomial<double>& p1, const Polynomial<double>& p2);



template
class Polynomial<mpz_class>;
template
class Polynomial<mpq_class>;
template
class Polynomial<mpf_class>;
template
Polynomial<mpz_class> operator*(const Polynomial<mpz_class>& p1, const Polynomial<mpz_class>& p2);
template
Polynomial<mpq_class> operator*(const Polynomial<mpq_class>& p1, const Polynomial<mpq_class>& p2);
template
Polynomial<mpf_class> operator*(const Polynomial<mpf_class>& p1, const Polynomial<mpf_class>& p2);

template
class PolynomialMultiplicationSimple<double>;
template
class PolynomialMultiplicationSimple<mpz_class>;
template
class PolynomialMultiplicationSimple<mpq_class>;
template
class PolynomialMultiplicationSimple<mpf_class>;
