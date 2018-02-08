/** \file Matrix.hpp
 * \brief Contains typedefs and convinience operators which are wrappers around boost::numeric::ublas::matrix class
 * \todo Provide better way of creating a matrix than zero initialization and then assignment to each entry.
 */
#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_
#include <boost/numeric/ublas/matrix.hpp>

template<typename EntryT>
using Matrix = boost::numeric::ublas::matrix<EntryT>;///< Typedef for the main matrix class
template <typename EntryT>
using Identity_Matrix = boost::numeric::ublas::identity_matrix<EntryT>;

//template <typename MatrixT>
//using productFunctionT = typename boost::numeric::ublas::matrix_matrix_binary_traits<typename MatrixT::value_type, MatrixT, typename MatrixT::value_type, MatrixT>::result_type(*)(const boost::numeric::ublas::matrix_expression<MatrixT>& e1, const boost::numeric::ublas::matrix_expression<MatrixT>& e2);
//
/** \todo Create an operator* as a wrapper so that the requirements from Matrix type can be stated cleanly in terms of operators rather than relying on exact function names
 */
using boost::numeric::ublas::prod; ///< exposing the prod() along with all its instantiations and overloads to global namespace
using boost::numeric::ublas::trans;
using boost::numeric::ublas::element_prod;
namespace boost { namespace numeric { namespace ublas {
   /*! \brief Finds trace of a square matrix
    *
    *  Detailed description of the function
    * \except{strong}{Throws std::invalid_argument if the supplied matrix is now square} 
    * \return trace Trace of a square matrix
    */
   template <typename EntryT>
   EntryT trace(const Matrix<EntryT>& M);

   /** \brief Convinience function to check if a matrix is square or not
    */
   template <typename MatrixT>
   bool isSquare(const MatrixT& M);


                                       }
               }

}

//template <typename FieldT>
//class Matrix 
//{
//   public:
//       /******* Constructors ********/
//      /*! \brief Takes in no arguments and creates a 0x0 matrix 
//       *
//       */
//       Matrix(); 
//       
//       /*! \brief Create a matrix with dimensions num_rows x num_cols with default
//        * initialized entries.
//        * \param num_rows 
//        * \param num_cols
//        */
//       Matrix(size_t num_rows,size_t num_cols); 
//
//       /*! \brief Use 2d initializer list to construct the matrix 
//        *
//        *
//        * \param entires 2d initializer list for example, for FieldT=int, {{23,56},{1,100}} 
//        */
//       Matrix(std::initializer_list<std::initializer_list<FieldT>> entries);
//         
//   private:
//      std::vector<FieldT> m_entries;
//};

#endif // _MATRIX_HPP_
