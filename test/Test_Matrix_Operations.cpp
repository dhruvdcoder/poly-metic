/*! @file Test_Matrix_Operations.cpp 
 * @brief Contains the tests for the matrix class with polynomial entries and arithmetic operations on that. 
 */
#include "../include/Matrix.ipp"
#include "../include/Polynomial.ipp"
#include "gtest/gtest.h"
namespace{
   class MatrixTest : public ::testing::Test{
      public:

      using FieldT = int;
      using entryT = Polynomial<FieldT>;
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
   
   
   

   TEST_F(MatrixTest,addition){
      entryT p1 {1,2,3};
      entryT p2 {4,5,6};
      entryT p3 {1};
      entryT p4 {7,8,9,10};
      Matrix<entryT> m (2,2);
      m(0,0)=p1;
      m(0,1)=p2;
      m(1,0)=p3;
      m(1,1)=p4;
      entryT p5 {0,0,2};
      entryT p6 {0};
      entryT p7 {6,5};
      entryT p8 {7,10};
      Matrix<entryT> m2 (2,2);
      m2(0,0)=p5;
      m2(0,1)=p6;
      m2(1,0)=p7;
      m2(1,1)=p8;
      
      Matrix<entryT> m3 = m+m2;      
      entryT r1 {1,2,5};
      entryT r2 {4,5,6};
      entryT r3 {7,5};
      entryT r4 {14,18,9,10};

      ASSERT_EQ(m3(0,0),r1);
      ASSERT_EQ(m3(0,1),r2);
      ASSERT_EQ(m3(1,0),r3);
      ASSERT_EQ(m3(1,1),r4);


   }
   TEST_F(MatrixTest,product){
      entryT p1 {1,2,3};
      entryT p2 {4,5,6};
      entryT p3 {1};
      entryT p4 {7,8,9,10};
      Matrix<entryT> m (2,2);
      m(0,0)=p1;
      m(0,1)=p2;
      m(1,0)=p3;
      m(1,1)=p4;

      
      Matrix<entryT> m3 =prod(m,m);      
      entryT r1 {5,9,16,12,9};
      entryT r2 {32,80,146,160,122,60};
      entryT r3 {8,10,12,10};
      entryT r4 {53,117,196,284,241,180,100};

      ASSERT_EQ(m3(0,0),r1);
      ASSERT_EQ(m3(0,1),r2);
      ASSERT_EQ(m3(1,0),r3);
      ASSERT_EQ(m3(1,1),r4);


   }
   TEST_F(MatrixTest,trace){
      using namespace boost::numeric::ublas;
      entryT p1 {1,2,3};
      entryT p2 {4,5,6};
      entryT p3 {1};
      entryT p4 {7,8,9,10};
      Matrix<entryT> m (2,2);
      m(0,0)=p1;
      m(0,1)=p2;
      m(1,0)=p3;
      m(1,1)=p4;

      
      entryT t = trace(m);      

      ASSERT_EQ(t, entryT ({8,10,12,10}));
      /* Assert exception when the matrix is not square */
      Matrix<entryT> m1 (2,3);
      m1(0,0)=p1;
      m1(0,1)=p2;
      m1(0,2)=p1;
      m1(1,0)=p3;
      m1(1,1)=p4;
      m1(1,2)=p3;
      ASSERT_THROW(trace(m1),std::invalid_argument);


   }
}
   /* Utility Function */
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

int main(int argc,char **argv){
   ::testing::InitGoogleTest(&argc,argv);
   return RUN_ALL_TESTS();
}
