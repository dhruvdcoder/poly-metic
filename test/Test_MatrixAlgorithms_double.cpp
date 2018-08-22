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
/*! @file Test_MatrixAlgorithms_double.cpp 
 * @brief Contains the tests for the external/user defined functions like exp(), det(), etc,. on Matrix with double entries. 
 */
#include "../include/Matrix.ipp"
#include "../include/MatrixAlgorithms.ipp"
#include "gtest/gtest.h"
namespace{
   class MatrixTest : public ::testing::Test{
      public:

      using entryT = double;
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
      ASSERT_DOUBLE_EQ(tri,3);

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
      ASSERT_DOUBLE_EQ(tr2,4185);

      Matrix<entryT> m (3,3);
      m(0,0)=345.5;
      m(0,1)=55;
      m(0,2)=3;
      m(1,0)=2.3;
      m(1,1)=100.4;
      m(1,2)=3.7;
      m(2,0)=0.02;
      m(2,1)=30;
      m(2,2)=456;
       
            
      entryT tr = trace(m,3);
      ASSERT_DOUBLE_EQ(tr,1.37428563169e+8);



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
      ASSERT_DOUBLE_EQ(di,1);

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
      ASSERT_DOUBLE_EQ(d2,0);

      Matrix<entryT> m (3,3);
      m(0,0)=345.5;
      m(0,1)=55;
      m(0,2)=3;
      m(1,0)=2.3;
      m(1,1)=100.4;
      m(1,2)=3.7;
      m(2,0)=0.02;
      m(2,1)=30;
      m(2,2)=456;
       
            
      entryT d = det(m);
      ASSERT_DOUBLE_EQ(d,1.572198974600e+7);



   }
  }
int main(int argc,char **argv){
   ::testing::InitGoogleTest(&argc,argv);
   return RUN_ALL_TESTS();
}
