/*! @file Test_MatrixAlgorithms_Polynomial_double.cpp 
 * @brief Contains the tests for the external/user defined functions like exp(), det(), etc,. on Matrix with Polynomials (on the field of doubles) entries. 
 */
#include "../include/Matrix.ipp"
#include "../include/MatrixAlgorithms.ipp"
#include "../include/Polynomial.ipp"
#include "Polynomial_testutils.ipp"
#include "gtest/gtest.h"
namespace{
   class MatrixTest : public ::testing::Test{
      public:
      using FieldT = double;
      using entryT = Polynomial<double>;
      using MatrixT = Matrix<entryT>;
     MatrixTest(){
   
    }
    virtual ~MatrixTest(){
       
    }

      protected:
         //virtual void SetUp() {

         //}

         //virtual void TearDown() {
            
         //}


   };
   
   
   

   TEST_F(MatrixTest,trace_with_power){

      Matrix<entryT> mi (3,3);
      mi(0,0)=1;
      mi(0,1)=0;
      mi(0,2)=0;
      mi(1,0)=0;
      mi(1,1)=1;
      mi(1,2)=0;
      mi(2,0)=0;
      mi(2,1)=0;
      mi(2,2)=1;

      entryT tri = trace(mi,5);
      ASSERT_EQ(tri.size(),1);
      ASSERT_DOUBLE_EQ(tri[0],3);

      Matrix<entryT> m2 (3,3);
      m2(0,0)=1;
      m2(0,1)=2;
      m2(0,2)=3;
      m2(1,0)=4;
      m2(1,1)=5;
      m2(1,2)=6;
      m2(2,0)=7;
      m2(2,1)=8;
      m2(2,2)=9;

      entryT tr2 = trace(m2,3);
      ASSERT_EQ(tr2,entryT(4185));

      Matrix<entryT> m (3,3);
      entryT p11  {2,0,10};//10x^2+2
      entryT p12 {5.2};
      entryT p13 {0,0,2,0,0,0.1};
      entryT p21 {0};
      entryT p22 {1,2.5};
      entryT p23 {0,100,0,23};
      entryT p31 {45};
      entryT p32 {0,0,44};
      entryT p33 {0};
      m(0,0)=p11;
      m(0,1)=p12;
      m(0,2)=p13;
      m(1,0)=p21;
      m(1,1)=p22;
      m(1,2)=p23;
      m(2,0)=p31;
      m(2,1)=p32;
      m(2,2)=p33;
       
            
      entryT tr = trace(m,3);
      ASSERT_EQ(tr,entryT ({9.0,70207.5000000000024,678.7500,29361.62500000000055,36300.0,3063.000000000000001,8590.0,135.0000000000000075}));



   }
   TEST_F(MatrixTest,determinant){

      Matrix<entryT> mi (3,3);
      mi(0,0)=1;
      mi(0,1)=0;
      mi(0,2)=0;
      mi(1,0)=0;
      mi(1,1)=1;
      mi(1,2)=0;
      mi(2,0)=0;
      mi(2,1)=0;
      mi(2,2)=1;

      entryT di = det(mi);
      ASSERT_EQ(di,entryT(1));

      Matrix<entryT> m2 (3,3);
      m2(0,0)=1;
      m2(0,1)=2;
      m2(0,2)=3;
      m2(1,0)=4;
      m2(1,1)=5;
      m2(1,2)=6;
      m2(2,0)=7;
      m2(2,1)=8;
      m2(2,2)=9;

      entryT d2 = det(m2);
      ASSERT_EQ(d2,entryT(0));

      Matrix<entryT> m (3,3);
      entryT p11  {2,0,10};//10x^2+2
      entryT p12 {5.2};
      entryT p13 {0,0,2,0,0,0.1};
      entryT p21 {0};
      entryT p22 {1,2.5};
      entryT p23 {0,100,0,23};
      entryT p31 {45};
      entryT p32 {0,0,44};
      entryT p33 {0};
      m(0,0)=p11;
      m(0,1)=p12;
      m(0,2)=p13;
      m(1,0)=p21;
      m(1,1)=p22;
      m(1,2)=p23;
      m(2,0)=p31;
      m(2,1)=p32;
      m(2,2)=p33;
            
      entryT d = det(m);
      ASSERT_EQ(d,entryT({0,23400.0,-90.0,-3642.99999999999982,0,-46028.5,-11.250,-10120.00}));

   }
   TEST_F(MatrixTest,determinant_large_5_5){
      /* read in the files created by mathematica */
      std::string input_file {"test/inputs_MatDim5_PolyDegree5.csv"};
      std::string result_file {"test/result_MatDim5_PolyDegree5.csv"};

      /* Create the input matrix*/
      Matrix<entryT> M (5,5);
      createMatrixWithPolynomialEntries<FieldT>(input_file,&M);

      /* read the expected result from file */
      entryT expectedResultp= readPolynomialFromFile<FieldT>(result_file);

      /* calculate the det */
      entryT resultp= det(M);
      ASSERT_EQ(resultp,expectedResultp);

   }
   TEST_F(MatrixTest,determinant_large_5_10){
      /* read in the files created by mathematica */
      std::string input_file {"test/inputs_MatDim5_PolyDegree10.csv"};
      std::string result_file {"test/result_MatDim5_PolyDegree10.csv"};

      /* Create the input matrix*/
      Matrix<entryT> M (5,5);
      createMatrixWithPolynomialEntries<FieldT>(input_file,&M);

      /* read the expected result from file */
      entryT expectedResultp= readPolynomialFromFile<FieldT>(result_file);

      /* calculate the det */
      entryT resultp= det(M);
      ASSERT_EQ(resultp,expectedResultp);

   }
   TEST_F(MatrixTest,determinant_large_10_10){
      /* read in the files created by mathematica */
      std::string input_file {"test/inputs_MatDim10_PolyDegree10.csv"};
      std::string result_file {"test/result_MatDim10_PolyDegree10.csv"};

      /* Create the input matrix*/
      using f=long double;
      using e = Polynomial<f>
      Matrix<entryT> M (10,10);
      createMatrixWithPolynomialEntries<FieldT>(input_file,&M);

      /* read the expected result from file */
      entryT expectedResultp= readPolynomialFromFile<FieldT>(result_file);

      /* calculate the det */
      entryT resultp= det(M);
      ASSERT_EQ(resultp,expectedResultp);

   }
  }
int main(int argc,char **argv){
   ::testing::InitGoogleTest(&argc,argv);
   return RUN_ALL_TESTS();
}
