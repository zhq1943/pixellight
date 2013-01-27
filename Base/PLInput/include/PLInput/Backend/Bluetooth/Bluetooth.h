/*********************************************************\
 *  File: Bluetooth.h                                    *
 *
 *  Copyright (C) 2002-2013 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 *  and associated documentation files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or
 *  substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
\*********************************************************/


#ifndef __PLINPUT_BLUETOOTH_H__
#define __PLINPUT_BLUETOOTH_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLCore/Core/Singleton.h>
#include <PLCore/Container/List.h>
#include "PLInput/PLInput.h"


//[-------------------------------------------------------]
//[ Forward declarations                                  ]
//[-------------------------------------------------------]
namespace PLInput {
	class BTImpl;
	class BTDevice;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLInput {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Class for accessing Bluetooth devices
*/
class Bluetooth : public PLCore::Singleton<Bluetooth> {


	//[-------------------------------------------------------]
	//[ Friends                                               ]
	//[-------------------------------------------------------]
	friend class PLCore::Singleton<Bluetooth>;


	//[-------------------------------------------------------]
	//[ Public static PLCore::Singleton functions             ]
	//[-------------------------------------------------------]
	// This solution enhances the compatibility with legacy compilers like GCC 4.2.1 used on Mac OS X 10.6
	// -> The C++11 feature "extern template" (C++11, see e.g. http://www2.research.att.com/~bs/C++0xFAQ.html#extern-templates) can only be used on modern compilers like GCC 4.6
	// -> We can't break legacy compiler support, especially when only the singletons are responsible for the break
	// -> See PLCore::Singleton for more details about singletons
	public:
		PLINPUT_API static Bluetooth *GetInstance();
		PLINPUT_API static bool HasInstance();


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Detect available Bluetooth devices
		*/
		PLINPUT_API void DetectDevices();

		/**
		*  @brief
		*    Get list of available Bluetooth devices
		*
		*  @return
		*    Device list
		*/
		PLINPUT_API const PLCore::List<BTDevice*> &GetDevices() const;


	//[-------------------------------------------------------]
	//[ Private functions                                     ]
	//[-------------------------------------------------------]
	private:
		/**
		*  @brief
		*    Constructor
		*/
		Bluetooth();

		/**
		*  @brief
		*    Destructor
		*/
		virtual ~Bluetooth();

		/**
		*  @brief
		*    Remove all devices
		*/
		void Clear();


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		BTImpl					*m_pBTImpl;		/**< Platform specific Bluetooth implementation */
		PLCore::List<BTDevice*>	 m_lstDevices;	/**< List of devices */


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLInput


#endif // __PLINPUT_BLUETOOTH_H__
