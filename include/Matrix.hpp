/** \file Matrix.hpp
 * \brief Contains typedefs and convinience operators which are wrappers around boost::numeric::ublas::matrix class
 */
#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_
#include <boost/numeric/ublas/matrix.hpp>

template<typename EntryT>
using Matrix = boost::numeric::ublas::matrix<EntryT>;///< Typedef for the main matrix class

namespace boost { namespace numeric { namespace ublas {
   /*! \brief Finds trace of a square matrix
    *
    *  Detailed description of the function
    * \except{strong}{Throws std::invalid_argument if the supplied matrix is now square} 
    * \return trace Trace of a square matrix
    */
   template <typename EntryT>
   EntryT trace(const Matrix<EntryT>& M);
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
