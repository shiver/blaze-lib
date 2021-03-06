//=================================================================================================
/*!
//  \file blazetest/mathtest/decomposition/DenseQRTest.h
//  \brief Header file for the dense matrix QR test
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZETEST_MATHTEST_DECOMPOSITION_DENSEQRTEST_H_
#define _BLAZETEST_MATHTEST_DECOMPOSITION_DENSEQRTEST_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <blaze/math/Aliases.h>
#include <blaze/math/typetraits/IsSquare.h>
#include <blaze/math/typetraits/RemoveAdaptor.h>
#include <blaze/util/Complex.h>
#include <blaze/util/Random.h>
#include <blazetest/system/LAPACK.h>


namespace blazetest {

namespace mathtest {

namespace decomposition {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Auxiliary class for all dense matrix QR tests.
//
// This class represents a test suite for the dense matrix QR decomposition functionality. It
// performs a series of QR decompositions on all dense matrix types of the Blaze library.
*/
class DenseQRTest
{
 public:
   //**Constructors********************************************************************************
   /*!\name Constructors */
   //@{
   explicit DenseQRTest();
   // No explicitly declared copy constructor.
   //@}
   //**********************************************************************************************

   //**Destructor**********************************************************************************
   // No explicitly declared destructor.
   //**********************************************************************************************

 private:
   //**Test functions******************************************************************************
   /*!\name Test functions */
   //@{
   template< typename Type >
   void testRandom();

   void testGeneral();
   void testSymmetric();
   void testHermitian();
   void testLower();
   void testUniLower();
   void testUpper();
   void testUniUpper();
   void testDiagonal();
   //@}
   //**********************************************************************************************

   //**Type definitions****************************************************************************
   typedef blaze::complex<float>   cfloat;   //!< Single precision complex test type.
   typedef blaze::complex<double>  cdouble;  //!< Double precision complex test type.
   //**********************************************************************************************

   //**Member variables****************************************************************************
   /*!\name Member variables */
   //@{
   std::string test_;  //!< Label of the currently performed test.
   //@}
   //**********************************************************************************************
};
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Test of the QR decomposition with a randomly initialized matrix of the given type.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function tests the dense matrix QR decomposition for a randomly initialized matrix of the
// given type. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
template< typename Type >
void DenseQRTest::testRandom()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   test_ = "QR decomposition";

   typedef blaze::RemoveAdaptor_<Type>  MT;

   const size_t m( blaze::rand<size_t>( 3UL, 8UL ) );
   const size_t n( blaze::IsSquare<Type>::value ? m : blaze::rand<size_t>( 3UL, 8UL ) );

   Type A;
   MT Q, R;

   resize( A, m, n );
   randomize( A );

   blaze::qr( A, Q, R );

   const MT QR( Q*R );

   if( QR != A ) {
      std::ostringstream oss;
      oss << " Test: " << test_ << "\n"
          << " Error: QR decomposition failed\n"
          << " Details:\n"
          << "   Matrix type:\n"
          << "     " << typeid( Type ).name() << "\n"
          << "   Element type:\n"
          << "     " << typeid( blaze::ElementType_<Type> ).name() << "\n"
          << "   Result:\n" << QR << "\n"
          << "   Expected result:\n" << A << "\n";
      throw std::runtime_error( oss.str() );
   }

#endif
}
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Testing the dense matrix QR decomposition.
//
// \return void
*/
void runTest()
{
   DenseQRTest();
}
//*************************************************************************************************




//=================================================================================================
//
//  MACRO DEFINITIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Macro for the execution of the dense matrix QR test.
*/
#define RUN_DENSE_QR_TEST \
   blazetest::mathtest::decomposition::runTest()
/*! \endcond */
//*************************************************************************************************

} // namespace decomposition

} // namespace mathtest

} // namespace blazetest

#endif
