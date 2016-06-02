//=================================================================================================
/*!
//  \file blaze/math/shims/InvCbrt.h
//  \brief Header file for the invcbrt shim
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

#ifndef _BLAZE_MATH_SHIMS_INVCBRT_H_
#define _BLAZE_MATH_SHIMS_INVCBRT_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/shims/Cbrt.h>
#include <blaze/util/Assert.h>
#include <blaze/util/typetraits/IsFloatingPoint.h>


namespace blaze {

//=================================================================================================
//
//  INVCBRT SHIM
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Returns the inverse cubic root of the given floating point value.
// \ingroup math_shims
//
// \param a The given floating point value \f$[0..\infty]\f$.
// \return The inverse cubic root of the given value.
//
// The \a invcbrt shim represents an abstract interface for computation of the inverse cubic
// root of the given floating point value.
//
// \note: The given value must be in the range \f$[0..\infty]\f$. The validity of the value is
// only checked by an user assert.
*/
template< typename T >
inline EnableIf_< IsFloatingPoint<T>, T > invcbrt( T a ) noexcept
{
   BLAZE_USER_ASSERT( a > T(0), "Invalid floating point value detected" );
   return T(1) / cbrt( a );
}
//*************************************************************************************************

} // namespace blaze

#endif