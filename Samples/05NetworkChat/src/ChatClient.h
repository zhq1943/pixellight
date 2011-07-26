/*********************************************************\
 *  File: ChatClient.h                                   *
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


#ifndef __PLSAMPLE_05_CHATCLIENT_H__
#define __PLSAMPLE_05_CHATCLIENT_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLCore/Network/Client.h>


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace NetworkChat {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Chat client network class
*/
class ChatClient : public PLCore::Client {


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Constructor
		*/
		ChatClient();

		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] nPort
		*    Number of the port to use
		*  @param[in] nMaxConnections
		*    Maximum number of allowed connections
		*/
		ChatClient(PLCore::uint32 nPort, PLCore::uint32 nMaxConnections);


	//[-------------------------------------------------------]
	//[ Private functions                                     ]
	//[-------------------------------------------------------]
	private:
		/**
		*  @brief
		*    Copy constructor
		*
		*  @param[in] cSource
		*    Source to copy from
		*/
		ChatClient(const ChatClient &cSource);

		/**
		*  @brief
		*    Copy operator
		*
		*  @param[in] cSource
		*    Source to copy from
		*
		*  @return
		*    Reference to this instance
		*/
		ChatClient &operator =(const ChatClient &cSource);


	//[-------------------------------------------------------]
	//[ Private virtual PLCore::Client functions              ]
	//[-------------------------------------------------------]
	private:
		virtual PLCore::Connection *CreateOutgoingConnection();


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // NetworkChat


#endif // __PLSAMPLE_05_CHATCLIENT_H__