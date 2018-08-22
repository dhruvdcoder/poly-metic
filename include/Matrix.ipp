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
/*! @file Matrix.ipp 
 * @brief Single file which is needed to be included to access all the functionallities associated with Matrix (which right now is boost::numeric::ublas::matrix). 
 */
#ifndef _MATRIX_IPP_
#define _MATRIX_IPP_

#include "../include/Matrix_impl.ipp"
using boost::numeric::ublas::isSquare; ///< exposing isSquare to global namespace
using boost::numeric::ublas::trace; ///< exposing isSquare to global namespace

#endif // _MATRIX_IPP_
