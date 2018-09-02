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
//
#include "../include/Polynomial.ipp" 
#include "../include/Matrix.ipp"
#include "../include/MatrixAlgorithms.ipp"
#include "../test/Polynomial_testutils.ipp"
#include "../external/cxxopts/include/cxxopts.hpp"


int main(int argc,char **argv){
    cxxopts::Options options("Determinant", "Finds determinant of a square matrix with univariate polynomial entries");
    options.add_options()
    ("i,input", "Input file name", cxxopts::value<std::string>())
    ("d,dim", "Dimension of the square matrix", cxxopts::value<unsigned int>());

    auto args = options.parse(argc, argv);
    std::string input_file;
    unsigned int dim = 0;
    try {
        input_file = args["input"].as<std::string>();
        dim = args["dim"].as<unsigned int>();
    }
    catch (const std::exception& e) {
        std::cout << "Could not parse command line argument --file " << e.what();
    }
    using numT = long double;
    using entryT = Polynomial<numT>;
    using MatrixT = Matrix<entryT>;
    MatrixT M (dim, dim);
    readMatrixWithPolynomialEntries<numT>(input_file, &M);
    std::cout << det(M) << std::endl;
    return 0;
}



