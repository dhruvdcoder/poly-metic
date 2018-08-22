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
/** \file gmpsupport.hpp
 * \brief The file contains explicit template declarations for gmp types as the template argument for polynomials.
 *
 * Include this file after including "Polynomial.hpp" to use quick compilation support for gmp types.
 */
#ifndef _GMPSUPPORT_HPP_
#define _GMPSUPPORT_HPP_
#include "../include/Polynomial.hpp"
#include "../include/PolynomialMultiplicationSimple.hpp"
#include <gmpxx.h>
/******************** Explicit template "declarations" ******************************/
extern template
class Polynomial <double>; 
extern template
Polynomial<double> operator*(const Polynomial<double>& p1, const Polynomial<double>& p2);


extern template
class Polynomial<mpz_class>;
extern template
class Polynomial<mpq_class>;
extern template
class Polynomial<mpf_class>;
extern template
Polynomial<mpz_class> operator*(const Polynomial<mpz_class>& p1, const Polynomial<mpz_class>& p2);
extern template
Polynomial<mpq_class> operator*(const Polynomial<mpq_class>& p1, const Polynomial<mpq_class>& p2);
extern template
Polynomial<mpf_class> operator*(const Polynomial<mpf_class>& p1, const Polynomial<mpf_class>& p2);

extern template
class PolynomialMultiplicationInterface<double>;
extern template
class PolynomialMultiplicationInterface<mpz_class>;
extern template
class PolynomialMultiplicationInterface<mpq_class>;
extern template
class PolynomialMultiplicationInterface<mpf_class>;

extern template
class PolynomialMultiplicationSimple<double>;
extern template
class PolynomialMultiplicationSimple<mpz_class>;
extern template
class PolynomialMultiplicationSimple<mpq_class>;
extern template
class PolynomialMultiplicationSimple<mpf_class>;
#endif //_GMPSUPPORT_HPP_

