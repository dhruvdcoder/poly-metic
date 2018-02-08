/*! @file Matrix.ipp 
 * @brief Single file which is needed to be included to access all the functionallities associated with Matrix (which right now is boost::numeric::ublas::matrix). 
 */
#ifndef _MATRIX_IPP_
#define _MATRIX_IPP_

#include "../include/Matrix_impl.ipp"
using boost::numeric::ublas::isSquare; ///< exposing isSquare to global namespace
using boost::numeric::ublas::trace; ///< exposing isSquare to global namespace

#endif // _MATRIX_IPP_
