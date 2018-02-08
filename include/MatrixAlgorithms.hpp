/*! @file MatrixAlgorithms.hpp
 * @brief Declarations for algorithms that work on Matrices 
 * */
#ifndef _MATRIXALGORITHMS_HPP_
#define _MATRIXALGORITHMS_HPP_

/** @brief Finds the M^n for a square matrix M
 * \todo Implement Matrix_Traits class to capture the requirements/properties of Matrix types at compile time to 
 * provide better error messages.
 * \todo exp() uses exponentiation by squaring. Give user the ability to specify algorithm using a template parameter.
 * \tparam MatrixT A Matrix type which supports indexing using (m,n), the *, + and the transpose opeators.
 */
template<typename MatrixT>
MatrixT exp(const MatrixT& M, size_t n);

/** @brief Finds the determinant of a square matrix
 * \todo Implement Matrix_Traits class to capture the requirements/properties of Matrix types at compile time to 
 * provide better error messages.
 * \todo exp() uses exponentiation by squaring. Give user the ability to specify algorithm using a template parameter.
 * \tparam MatrixT A Matrix type which supports indexing using (m,n), the *, + ,the transpose and the trace operators.
 */
template<typename MatrixT>
typename MatrixT::value_type det(const MatrixT& M);
#endif // _MATRIXALGORITHMS_H





