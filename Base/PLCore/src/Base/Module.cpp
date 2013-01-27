/*********************************************************\
 *  File: Module.cpp                                     *
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


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLCore/System/DynLib.h"
#include "PLCore/Base/Module.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Private functions                                     ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
Module::Module(uint32 nModuleID) :
	m_nModuleID(nModuleID),
	m_bPlugin(false),
	m_pDynLib(nullptr),
	m_sName("Unknown"),
	m_sVendor("Unknown"),
	m_sLicense("Unknown"),
	m_sDescription("Unknown module")
{
}

/**
*  @brief
*    Destructor
*/
Module::~Module()
{
	// If there's a dynamic library instance, destroy it right now
	if (m_pDynLib)
		delete m_pDynLib;
}

/**
*  @brief
*    Set module information
*/
void Module::SetModuleInfo(const String &sName, const String &sVendor, const String &sLicense, const String &sDescription)
{
	// Save data
	m_sName			= sName;
	m_sVendor		= sVendor;
	m_sLicense		= sLicense;
	m_sDescription	= sDescription;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore
