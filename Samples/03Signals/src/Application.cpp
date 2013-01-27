/*********************************************************\
 *  File: Application.cpp                                *
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
#include <PLCore/System/System.h>
#include <PLCore/System/Console.h>
#include "Application.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLCore;


//[-------------------------------------------------------]
//[ RTTI interface                                        ]
//[-------------------------------------------------------]
pl_implement_class(Application)


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
Application::Application() : CoreApplication(),
	m_bExit(false)
{
}

/**
*  @brief
*    Destructor
*/
Application::~Application()
{
}


//[-------------------------------------------------------]
//[ Private virtual PLCore::CoreApplication functions     ]
//[-------------------------------------------------------]
void Application::Main()
{
	int i = 1;
	while (!m_bExit || i > 1) {
		System::GetInstance()->Sleep(500);
		System::GetInstance()->GetConsole().Print(String("Counting ") + i + '\n');
		i++;
		if (i > 10)
			i = 1;
	}
}

bool Application::OnSignal(ESignal nSignal)
{
	// Termination
	if (nSignal == SignalTerm) {
		// Start counter
		System::GetInstance()->GetConsole().Print("<Exit>: Caught TERM signal, will continue counting to 10 and then exit.\n");
		m_bExit = true;

		// Cancel signal
		return false;
	}

	// Go on with default signal handler
	return true;
}
