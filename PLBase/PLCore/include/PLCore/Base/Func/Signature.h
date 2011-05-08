/*********************************************************\
 *  File: Signature.h                                    *
 *
 *  Copyright (C) 2002-2011 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  PixelLight is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PixelLight is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with PixelLight. If not, see <http://www.gnu.org/licenses/>.
\*********************************************************/


#ifndef __PLCORE_SIGNATURE_H__
#define __PLCORE_SIGNATURE_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLCore/Base/Type/Type.h"
#include "PLCore/Base/Tools/TypeTraits.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Convert signature to string
*/
template <typename R = NullType, typename T0 = NullType, typename T1 = NullType, typename T2 = NullType, typename T3 = NullType, typename T4 = NullType, typename T5 = NullType, typename T6 = NullType, typename T7 = NullType, typename T8 = NullType, typename T9 = NullType, typename T10 = NullType, typename T11 = NullType, typename T12 = NullType, typename T13 = NullType, typename T14 = NullType, typename T15 = NullType>
class SignatureString {


	//[-------------------------------------------------------]
	//[ Public static functions                               ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Get signature as a string
		*
		*  @return
		*    Signature description (e.g. "void(int,float)")
		*/
		static PLGeneral::String GetSignatureID() {
			// On runtime the signature doesn't change, so construct it only once and then just reuse it
			static PLGeneral::String sSignature;
			if (sSignature.GetLength()) {
				// Return the already constructed signature
				return sSignature;
			} else {
				PLGeneral::String sType;

				// Return type
				sSignature = Type<R>::GetTypeName() + '(';

				// Type 0
				sType = Type<T0>::GetTypeName();
				if (sType != "") sSignature += sType;

				// Type 1
				sType = Type<T1>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 2
				sType = Type<T2>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 3
				sType = Type<T3>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 4
				sType = Type<T4>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 5
				sType = Type<T5>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 6
				sType = Type<T6>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 7
				sType = Type<T7>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 8
				sType = Type<T8>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 9
				sType = Type<T9>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 10
				sType = Type<T10>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 11
				sType = Type<T11>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 12
				sType = Type<T12>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 13
				sType = Type<T13>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 14
				sType = Type<T14>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Type 15
				sType = Type<T15>::GetTypeName();
				if (sType != "") sSignature += "," + sType;

				// Done
				sSignature = sSignature + ')';
				return sSignature;
			}
		}
};


/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for up to 16 parameters
*/
template <typename R = NullType, typename T0 = NullType, typename T1 = NullType, typename T2 = NullType, typename T3 = NullType, typename T4 = NullType, typename T5 = NullType, typename T6 = NullType, typename T7 = NullType, typename T8 = NullType, typename T9 = NullType, typename T10 = NullType, typename T11 = NullType, typename T12 = NullType, typename T13 = NullType, typename T14 = NullType, typename T15 = NullType>
class Signature {


	//[-------------------------------------------------------]
	//[ Public data types                                     ]
	//[-------------------------------------------------------]
	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15);	// Function pointer


	//[-------------------------------------------------------]
	//[ Public static functions                               ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Get signature as a string
		*
		*  @return
		*    Signature description (e.g. "void(int,float)")
		*/
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 15 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
class Signature<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 14 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
class Signature<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 13 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
class Signature<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 12 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
class Signature<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 11 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
class Signature<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 10 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
class Signature<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4, T5, T6, T7, T8, T9);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 9 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
class Signature<R, T0, T1, T2, T3, T4, T5, T6, T7, T8> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4, T5, T6, T7, T8);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 8 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
class Signature<R, T0, T1, T2, T3, T4, T5, T6, T7> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4, T5, T6, T7);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 7 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Signature<R, T0, T1, T2, T3, T4, T5, T6> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4, T5, T6);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 6 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
class Signature<R, T0, T1, T2, T3, T4, T5> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4, T5);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 5 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3, typename T4>
class Signature<R, T0, T1, T2, T3, T4> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3, T4);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 4 parameters
*/
template <typename R, typename T0, typename T1, typename T2, typename T3>
class Signature<R, T0, T1, T2, T3> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2, T3);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 3 parameters
*/
template <typename R, typename T0, typename T1, typename T2>
class Signature<R, T0, T1, T2> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1, T2);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 2 parameters
*/
template <typename R, typename T0, typename T1>
class Signature<R, T0, T1> {


	public:
		// Composed types
		typedef R (*FuncType)(T0, T1);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 1 parameters
*/
template <typename R, typename T0>
class Signature<R, T0> {


	public:
		// Composed types
		typedef R (*FuncType)(T0);	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a function
*
*  @remarks
*    Implementation for 0 parameters
*/
template <typename R>
class Signature<R> {


	public:
		// Composed types
		typedef R (*FuncType)();	// Function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for up to 16 parameters
*/
template <typename CLASS = NullType, typename R = NullType, typename T0 = NullType, typename T1 = NullType, typename T2 = NullType, typename T3 = NullType, typename T4 = NullType, typename T5 = NullType, typename T6 = NullType, typename T7 = NullType, typename T8 = NullType, typename T9 = NullType, typename T10 = NullType, typename T11 = NullType, typename T12 = NullType, typename T13 = NullType, typename T14 = NullType, typename T15 = NullType>
class MethodSignature {


	//[-------------------------------------------------------]
	//[ Public data types                                     ]
	//[-------------------------------------------------------]
	public:
		// Storage types
		typedef typename Type<R>  ::_Type _R;
		typedef typename Type<T0> ::_Type _T0;
		typedef typename Type<T1> ::_Type _T1;
		typedef typename Type<T2> ::_Type _T2;
		typedef typename Type<T3> ::_Type _T3;
		typedef typename Type<T4> ::_Type _T4;
		typedef typename Type<T5> ::_Type _T5;
		typedef typename Type<T6> ::_Type _T6;
		typedef typename Type<T7> ::_Type _T7;
		typedef typename Type<T8> ::_Type _T8;
		typedef typename Type<T9> ::_Type _T9;
		typedef typename Type<T10>::_Type _T10;
		typedef typename Type<T11>::_Type _T11;
		typedef typename Type<T12>::_Type _T12;
		typedef typename Type<T13>::_Type _T13;
		typedef typename Type<T14>::_Type _T14;
		typedef typename Type<T15>::_Type _T15;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10, _T11, _T12, _T13, _T14, _T15);			// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10, _T11, _T12, _T13, _T14, _T15);	// Member function pointer


	//[-------------------------------------------------------]
	//[ Public static functions                               ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Get signature as a string
		*
		*  @return
		*    Signature description (e.g. "void(int,float)")
		*/
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 15 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
class MethodSignature<CLASS, R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14> {


	public:
		// Storage types
		typedef typename Type<R>  ::_Type _R;
		typedef typename Type<T0> ::_Type _T0;
		typedef typename Type<T1> ::_Type _T1;
		typedef typename Type<T2> ::_Type _T2;
		typedef typename Type<T3> ::_Type _T3;
		typedef typename Type<T4> ::_Type _T4;
		typedef typename Type<T5> ::_Type _T5;
		typedef typename Type<T6> ::_Type _T6;
		typedef typename Type<T7> ::_Type _T7;
		typedef typename Type<T8> ::_Type _T8;
		typedef typename Type<T9> ::_Type _T9;
		typedef typename Type<T10>::_Type _T10;
		typedef typename Type<T11>::_Type _T11;
		typedef typename Type<T12>::_Type _T12;
		typedef typename Type<T13>::_Type _T13;
		typedef typename Type<T14>::_Type _T14;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10, _T11, _T12, _T13, _T14);				// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10, _T11, _T12, _T13, _T14);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 14 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
class MethodSignature<CLASS, R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13> {


	public:
		// Storage types
		typedef typename Type<R>  ::_Type _R;
		typedef typename Type<T0> ::_Type _T0;
		typedef typename Type<T1> ::_Type _T1;
		typedef typename Type<T2> ::_Type _T2;
		typedef typename Type<T3> ::_Type _T3;
		typedef typename Type<T4> ::_Type _T4;
		typedef typename Type<T5> ::_Type _T5;
		typedef typename Type<T6> ::_Type _T6;
		typedef typename Type<T7> ::_Type _T7;
		typedef typename Type<T8> ::_Type _T8;
		typedef typename Type<T9> ::_Type _T9;
		typedef typename Type<T10>::_Type _T10;
		typedef typename Type<T11>::_Type _T11;
		typedef typename Type<T12>::_Type _T12;
		typedef typename Type<T13>::_Type _T13;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10, _T11, _T12, _T13);			// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10, _T11, _T12, _T13);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 13 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
class MethodSignature<CLASS, R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12> {


	public:
		// Storage types
		typedef typename Type<R>  ::_Type _R;
		typedef typename Type<T0> ::_Type _T0;
		typedef typename Type<T1> ::_Type _T1;
		typedef typename Type<T2> ::_Type _T2;
		typedef typename Type<T3> ::_Type _T3;
		typedef typename Type<T4> ::_Type _T4;
		typedef typename Type<T5> ::_Type _T5;
		typedef typename Type<T6> ::_Type _T6;
		typedef typename Type<T7> ::_Type _T7;
		typedef typename Type<T8> ::_Type _T8;
		typedef typename Type<T9> ::_Type _T9;
		typedef typename Type<T10>::_Type _T10;
		typedef typename Type<T11>::_Type _T11;
		typedef typename Type<T12>::_Type _T12;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10, _T11, _T12);				// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10, _T11, _T12);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 12 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
class MethodSignature<CLASS, R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11> {


	public:
		// Storage types
		typedef typename Type<R>  ::_Type _R;
		typedef typename Type<T0> ::_Type _T0;
		typedef typename Type<T1> ::_Type _T1;
		typedef typename Type<T2> ::_Type _T2;
		typedef typename Type<T3> ::_Type _T3;
		typedef typename Type<T4> ::_Type _T4;
		typedef typename Type<T5> ::_Type _T5;
		typedef typename Type<T6> ::_Type _T6;
		typedef typename Type<T7> ::_Type _T7;
		typedef typename Type<T8> ::_Type _T8;
		typedef typename Type<T9> ::_Type _T9;
		typedef typename Type<T10>::_Type _T10;
		typedef typename Type<T11>::_Type _T11;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10, _T11);			// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10, _T11);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 11 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
class MethodSignature<CLASS, R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> {


	public:
		// Storage types
		typedef typename Type<R>  ::_Type _R;
		typedef typename Type<T0> ::_Type _T0;
		typedef typename Type<T1> ::_Type _T1;
		typedef typename Type<T2> ::_Type _T2;
		typedef typename Type<T3> ::_Type _T3;
		typedef typename Type<T4> ::_Type _T4;
		typedef typename Type<T5> ::_Type _T5;
		typedef typename Type<T6> ::_Type _T6;
		typedef typename Type<T7> ::_Type _T7;
		typedef typename Type<T8> ::_Type _T8;
		typedef typename Type<T9> ::_Type _T9;
		typedef typename Type<T10>::_Type _T10;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10);				// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9, _T10);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 10 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
class MethodSignature<CLASS, R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9> {


	public:
		// Storage types
		typedef typename Type<R> ::_Type _R;
		typedef typename Type<T0>::_Type _T0;
		typedef typename Type<T1>::_Type _T1;
		typedef typename Type<T2>::_Type _T2;
		typedef typename Type<T3>::_Type _T3;
		typedef typename Type<T4>::_Type _T4;
		typedef typename Type<T5>::_Type _T5;
		typedef typename Type<T6>::_Type _T6;
		typedef typename Type<T7>::_Type _T7;
		typedef typename Type<T8>::_Type _T8;
		typedef typename Type<T9>::_Type _T9;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9);			// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8, _T9);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 9 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
class MethodSignature<CLASS, R, T0, T1, T2, T3, T4, T5, T6, T7, T8> {


	public:
		// Storage types
		typedef typename Type<R> ::_Type _R;
		typedef typename Type<T0>::_Type _T0;
		typedef typename Type<T1>::_Type _T1;
		typedef typename Type<T2>::_Type _T2;
		typedef typename Type<T3>::_Type _T3;
		typedef typename Type<T4>::_Type _T4;
		typedef typename Type<T5>::_Type _T5;
		typedef typename Type<T6>::_Type _T6;
		typedef typename Type<T7>::_Type _T7;
		typedef typename Type<T8>::_Type _T8;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8);			// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7, T8>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 8 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
class MethodSignature<CLASS, R, T0, T1, T2, T3, T4, T5, T6, T7> {


	public:
		// Storage types
		typedef typename Type<R> ::_Type _R;
		typedef typename Type<T0>::_Type _T0;
		typedef typename Type<T1>::_Type _T1;
		typedef typename Type<T2>::_Type _T2;
		typedef typename Type<T3>::_Type _T3;
		typedef typename Type<T4>::_Type _T4;
		typedef typename Type<T5>::_Type _T5;
		typedef typename Type<T6>::_Type _T6;
		typedef typename Type<T7>::_Type _T7;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7);				// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6, _T7);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6, T7>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 7 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class MethodSignature<CLASS, R, T0, T1, T2, T3, T4, T5, T6> {


	public:
		// Storage types
		typedef typename Type<R> ::_Type _R;
		typedef typename Type<T0>::_Type _T0;
		typedef typename Type<T1>::_Type _T1;
		typedef typename Type<T2>::_Type _T2;
		typedef typename Type<T3>::_Type _T3;
		typedef typename Type<T4>::_Type _T4;
		typedef typename Type<T5>::_Type _T5;
		typedef typename Type<T6>::_Type _T6;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6);				// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4, _T5, _T6);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5, T6>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 6 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
class MethodSignature<CLASS, R, T0, T1, T2, T3, T4, T5> {


	public:
		// Storage types
		typedef typename Type<R> ::_Type _R;
		typedef typename Type<T0>::_Type _T0;
		typedef typename Type<T1>::_Type _T1;
		typedef typename Type<T2>::_Type _T2;
		typedef typename Type<T3>::_Type _T3;
		typedef typename Type<T4>::_Type _T4;
		typedef typename Type<T5>::_Type _T5;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4, _T5);			// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4, _T5);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4, T5>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 5 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3, typename T4>
class MethodSignature<CLASS, R, T0, T1, T2, T3, T4> {


	public:
		// Storage types
		typedef typename Type<R> ::_Type _R;
		typedef typename Type<T0>::_Type _T0;
		typedef typename Type<T1>::_Type _T1;
		typedef typename Type<T2>::_Type _T2;
		typedef typename Type<T3>::_Type _T3;
		typedef typename Type<T4>::_Type _T4;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3, _T4);			// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3, _T4);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3, T4>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 4 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2, typename T3>
class MethodSignature<CLASS, R, T0, T1, T2, T3> {


	public:
		// Storage types
		typedef typename Type<R> ::_Type _R;
		typedef typename Type<T0>::_Type _T0;
		typedef typename Type<T1>::_Type _T1;
		typedef typename Type<T2>::_Type _T2;
		typedef typename Type<T3>::_Type _T3;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2, _T3);				// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2, _T3);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2, T3>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 3 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1, typename T2>
class MethodSignature<CLASS, R, T0, T1, T2> {


	public:
		// Storage types
		typedef typename Type<R> ::_Type _R;
		typedef typename Type<T0>::_Type _T0;
		typedef typename Type<T1>::_Type _T1;
		typedef typename Type<T2>::_Type _T2;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1, _T2);				// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1, _T2);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1, T2>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 2 parameters
*/
template <typename CLASS, typename R, typename T0, typename T1>
class MethodSignature<CLASS, R, T0, T1> {


	public:
		// Storage types
		typedef typename Type<R> ::_Type _R;
		typedef typename Type<T0>::_Type _T0;
		typedef typename Type<T1>::_Type _T1;

		// Composed types
		typedef _R (*FuncType)(_T0, _T1);			// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0, _T1);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0, T1>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 1 parameter
*/
template <typename CLASS, typename R, typename T0>
class MethodSignature<CLASS, R, T0> {


	public:
		// Storage types
		typedef typename Type<R> ::_Type _R;
		typedef typename Type<T0>::_Type _T0;

		// Composed types
		typedef _R (*FuncType)(_T0);			// Function pointer
		typedef _R (CLASS::*MemFuncType)(_T0);	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R, T0>::GetSignatureID();
		}


};

/**
*  @brief
*    Signature for a method
*
*  @remarks
*    Implementation for 0 parameter
*/
template <typename CLASS, typename R>
class MethodSignature<CLASS, R> {


	public:
		// Storage types
		typedef typename Type<R>::_Type _R;

		// Composed types
		typedef _R (*FuncType)();			// Function pointer
		typedef _R (CLASS::*MemFuncType)();	// Member function pointer

		// Get signature as a string
		static PLGeneral::String GetSignatureID() {
			return SignatureString<R>::GetSignatureID();
		}


};


template <typename R = NullType, typename T0 = NullType, typename T1 = NullType, typename T2 = NullType, typename T3 = NullType, typename T4 = NullType, typename T5 = NullType, typename T6 = NullType, typename T7 = NullType, typename T8 = NullType, typename T9 = NullType, typename T10 = NullType, typename T11 = NullType, typename T12 = NullType, typename T13 = NullType, typename T14 = NullType, typename T15 = NullType>
class Typelist {
	public:
		typedef typename Type<R>  ::_Type TypeR;
		typedef typename Type<T0> ::_Type Type0;
		typedef typename Type<T1> ::_Type Type1;
		typedef typename Type<T2> ::_Type Type2;
		typedef typename Type<T3> ::_Type Type3;
		typedef typename Type<T4> ::_Type Type4;
		typedef typename Type<T5> ::_Type Type5;
		typedef typename Type<T6> ::_Type Type6;
		typedef typename Type<T7> ::_Type Type7;
		typedef typename Type<T8> ::_Type Type8;
		typedef typename Type<T9> ::_Type Type9;
		typedef typename Type<T10>::_Type Type10;
		typedef typename Type<T11>::_Type Type11;
		typedef typename Type<T12>::_Type Type12;
		typedef typename Type<T13>::_Type Type13;
		typedef typename Type<T14>::_Type Type14;
		typedef typename Type<T15>::_Type Type15;
};

template <typename CLASS, typename TYPELIST>
class ClassTypelist {
	public:
		typedef CLASS	Class;
		typedef typename TYPELIST::TypeR	TypeR;
		typedef typename TYPELIST::Type0	Type0;
		typedef typename TYPELIST::Type1	Type1;
		typedef typename TYPELIST::Type2	Type2;
		typedef typename TYPELIST::Type3	Type3;
		typedef typename TYPELIST::Type4	Type4;
		typedef typename TYPELIST::Type5	Type5;
		typedef typename TYPELIST::Type6	Type6;
		typedef typename TYPELIST::Type7	Type7;
		typedef typename TYPELIST::Type8	Type8;
		typedef typename TYPELIST::Type9	Type9;
		typedef typename TYPELIST::Type10	Type10;
		typedef typename TYPELIST::Type11	Type11;
		typedef typename TYPELIST::Type12	Type12;
		typedef typename TYPELIST::Type13	Type13;
		typedef typename TYPELIST::Type14	Type14;
		typedef typename TYPELIST::Type15	Type15;

		typedef MethodSignature<Class, TypeR, Type0, Type1, Type2, Type3, Type4, Type5, Type6, Type7,
								Type8, Type9, Type10, Type11, Type12, Type13, Type14, Type15>	TypeMethodSignature;
};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore


#endif // __PLCORE_SIGNATURE_H__
