/*********************************************************\
 *  File: Application30.h                                *
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


#ifndef __PLSAMPLE_30_H__
#define __PLSAMPLE_30_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLCore/Base/Event/EventHandler.h>
#include <PLCore/Frontend/FrontendApplication.h>


//[-------------------------------------------------------]
//[ Forward declarations                                  ]
//[-------------------------------------------------------]
namespace PLInput {
	class Control;
}


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Application class
*/
class Application30 : public PLCore::FrontendApplication {


	//[-------------------------------------------------------]
	//[ RTTI interface                                        ]
	//[-------------------------------------------------------]
	pl_class(pl_rtti_export, Application30, "", PLCore::FrontendApplication, "Application class")
		// Constructors
		pl_constructor_1(ParameterConstructor,	PLCore::Frontend&,	"Parameter constructor. Frontend this application instance is running in as first parameter.",	"")
	pl_class_end


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] cFrontend
		*    Frontend this application instance is running in
		*/
		Application30(PLCore::Frontend &cFrontend);

		/**
		*  @brief
		*    Destructor
		*/
		virtual ~Application30();

		/**
		*  @brief
		*    Test: List devices
		*/
		void TestDevices();

		/**
		*  @brief
		*    Test: Controller
		*/
		void TestController();

		/**
		*  @brief
		*    Test: Input
		*
		*  @param[in] sDevice
		*    Name of device
		*/
		void TestInput(const PLCore::String &sDevice);

		/**
		*  @brief
		*    Test: GetChar() functionality
		*
		*  @param[in] sDevice
		*    Name of device
		*/
		void TestGetChar(const PLCore::String &sDevice);

		/**
		*  @brief
		*    Test: Connections
		*/
		void TestConnections();


	//[-------------------------------------------------------]
	//[ Private functions                                     ]
	//[-------------------------------------------------------]
	private:
		/**
		*  @brief
		*    Called when a control of the input controller has been activated
		*/
		void OnControl(PLInput::Control &cControl);

		/**
		*  @brief
		*    Called when a control of the input controller has been activated
		*/
		void OnControlExit(PLInput::Control &cControl);


	//[-------------------------------------------------------]
	//[ Private virtual PLCore::AbstractLifecycle functions   ]
	//[-------------------------------------------------------]
	private:
		virtual bool OnStart() override;


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		// Event handlers
		PLCore::EventHandler<PLInput::Control&> EventHandlerOnControl;
		PLCore::EventHandler<PLInput::Control&> EventHandlerOnControlExit;

		// Status
		bool m_bExit;


};


#endif // __PLSAMPLE_30_H__