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
/*! @file Polynomial_testutils.ipp 
 * @brief Header for the utility functions like == operator for polynomials
 * */
#ifndef _POLYNOMIAL_TESTUTILS_IPP
#define _POLYNOMIAL_TESTUTILS_IPP

#include "../include/Polynomial.hpp" 
#include "../include/Matrix.ipp"
#include <limits>
#include <string>
#include <utility>
#include <regex>
#include <fstream>
#include <stdexcept>
template <typename FieldT>
 bool operator==(const Polynomial<FieldT>& lhs, const Polynomial<FieldT>& rhs)
{
   if (lhs.size() != rhs.size()) {
      return false;
   }
   for(size_t i = 0; i < lhs.size(); ++i){
      if (lhs[i] != rhs[i]) {
         return false;
      }
   }
   return true;
}



bool operator==(const Polynomial<double>& lhs, const Polynomial<double>& rhs)
{
   if (lhs.size() != rhs.size()) {
      return false;
   }
   auto areSame = [](double a, double b)->bool {
      //return std::fabs(a-b) < std::numeric_limits<double>::epsilon();
      return std::fabs(a-b) < double(1e-6);
   };
   for(size_t i = 0; i < lhs.size(); ++i){
      if (!areSame(lhs[i],rhs[i])) {
         return false;
      }
   }
   return true;

}

/** \brief Function to read the size of matrix and polynomial entries from filename of the input file
 */
std::pair<size_t,size_t> readInputSize(const std::string filename)
{
   /* Matrix dimension */
   std::regex matrixDimensionRegex ("MatDim(\\d+)");
   std::smatch matrixDimensionMatch;
   if(!std::regex_search(filename,matrixDimensionMatch,matrixDimensionRegex))
   {
      throw std::invalid_argument("readInputSize: The filename does not have pattern \"MatDim#\" ");
   }
   std::regex polyDegreeRegex("PolyDegree(\\d+)");
   std::smatch polyDegreeMatch;
   if(!std::regex_search(filename,polyDegreeMatch,polyDegreeRegex)) {
      throw std::invalid_argument("readInputSize: The filename doesn not have pattern \"PolyDegree#\" ");
   }
   return std::make_pair(std::stoul(matrixDimensionMatch[1]),std::stoul(polyDegreeMatch[1]));

}

/** \brief Function to convert string to various number types or coef types. Specialize for every supported type.
 */
template <typename FieldT>
FieldT stringToField(const std::string& s);
/** \brief Specialization for double as return type.
 */
template<>
double stringToField(const std::string& s)
{
   return std::stod(s);
}

template<>
long double stringToField(const std::string& s)
{
   return std::stold(s);
}
/** \brief Read the input and output files and create the matrix of polynomials
 */ 
template<typename FieldT>
 void createMatrixWithPolynomialEntries(const std::string& inputfile,Matrix<Polynomial<FieldT>>* pmat) {
   if(pmat==nullptr) throw std::invalid_argument("createMatrixWithPolynomialEnties: Pointer to matrix is null");
   std::pair<size_t,size_t> matrixDim_PolyDegree_pair = readInputSize(inputfile);
   size_t matrixDim=matrixDim_PolyDegree_pair.first;
   size_t PolyDegree=matrixDim_PolyDegree_pair.second;
   using EntryT = Polynomial<FieldT>;

   /* entries in the file are linearly indexed in row major order */
   std::ifstream file (inputfile);
   if(!file.is_open()) throw std::invalid_argument("createMatrixWithPolynomialEntries: Failed to open inputfile");
   size_t rowNumber=0;
   for(size_t entryNumber =0; entryNumber < matrixDim*matrixDim ; ) {
      for (size_t columnNumber=0;columnNumber<matrixDim;++columnNumber) {
         std::string line;
         getline(file,line); // read one line, ie coeffs of one polynomial 
         std::stringstream linestream(line);

         /* read all entries of a line */
         EntryT ijth_polynomial;
         for (size_t i_coef =0; i_coef < PolyDegree+1 ;++i_coef) {
            std::string coef;
            getline(linestream,coef,',');
            ijth_polynomial.appendTerm(stringToField<FieldT>(coef));
         }
         /* Place the polynomial in the matrix */
         (*pmat)(rowNumber,columnNumber)=ijth_polynomial;
         ++entryNumber;
      }
      rowNumber++;
      entryNumber++;
   }
}

/** \brief Read the input file and create the matrix of polynomials dynamically without depending on the file name
 *  to give information about the dimensions
 */
template<typename FieldT>
 void readMatrixWithPolynomialEntries(const std::string& inputfile,Matrix<Polynomial<FieldT>>* pmat) {
   if(pmat==nullptr) throw std::invalid_argument("createMatrixWithPolynomialEnties: Pointer to matrix is null");
   size_t matrixDim = pmat->size1();
   using EntryT = Polynomial<FieldT>;

   /* entries in the file are linearly indexed in row major order */
   std::ifstream file (inputfile);
   if(!file.is_open()) throw std::invalid_argument("createMatrixWithPolynomialEntries: Failed to open inputfile");
   size_t rowNumber=0;
   for(size_t entryNumber =0; entryNumber < matrixDim*matrixDim ; ) {
      for (size_t columnNumber=0;columnNumber < matrixDim;++columnNumber) {
         std::string line;
         getline(file,line); // read one line, ie coeffs of one polynomial 
         std::stringstream linestream(line);

         /* read all entries of a line */
         EntryT ijth_polynomial;
         for (std::string coef;getline(linestream,coef,',');) {
            ijth_polynomial.appendTerm(stringToField<FieldT>(coef));
         }
         /* Place the polynomial in the matrix */
         (*pmat)(rowNumber,columnNumber)=ijth_polynomial;
         ++entryNumber;
      }
      rowNumber++;
      entryNumber++;
   }
}




template <typename FieldT>
Polynomial<FieldT> readPolynomialFromFile(const std::string& resultfile)
{
   std::ifstream file (resultfile);
   if(!file.is_open()) throw std::invalid_argument("readPolynomialFromFile: Failed to open resultfile");
   std::string line;
   Polynomial<FieldT> p;
   while(getline(file,line)) {
      p.appendTerm(stringToField<FieldT>(line));
   }
   return std::move(p);
}
#endif // _POLYNOMIAL_TESTUTILS_H





