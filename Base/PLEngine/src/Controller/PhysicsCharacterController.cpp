/*********************************************************\
 *  File: PhysicsCharacterController.cpp                 *
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
#include "PLEngine/Controller/PhysicsCharacterController.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLInput;
namespace PLEngine {


//[-------------------------------------------------------]
//[ RTTI interface                                        ]
//[-------------------------------------------------------]
pl_implement_class(PhysicsCharacterController)


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
PhysicsCharacterController::PhysicsCharacterController() : Controller(ControllerVirtual, "PhysicsCharacterController", "Physics character input controller"),
	TransX		(this, "TransX",		"X translation axis: Strafe left/right (+/-)"),
	TransY		(this, "TransY",		"Y translation axis: Move up/down (+/-)"),
	TransZ		(this, "TransZ",		"Z translation axis: Move forwards/backwards (+/-)"),
	RotY		(this, "RotY",			"Y rotation axis: Yaw (also called 'heading') change is turning to the left or right"),
	Forward		(this, "Forward",		"Move forwards",			0x00),
	Backward	(this, "Backward",		"Move backwards",			0x00),
	Left		(this, "Left",			"Move (rotate) left",		0x00),
	Right		(this, "Right",			"Move (rotate) right",		0x00),
	StrafeLeft	(this, "StrafeLeft",	"Strafe left",				0x00),
	StrafeRight	(this, "StrafeRight",	"Strafe right",				0x00),
	Up			(this, "Up",			"Move up",					0x00),
	Down		(this, "Down",			"Move down",				0x00),
	Run			(this, "Run",			"Keep pressed to run",		0x00),
	Crouch		(this, "Crouch",		"Keep pressed to crouch",	0x00),
	Jump		(this, "Jump",			"Jump",						0x00)
{
}

/**
*  @brief
*    Destructor
*/
PhysicsCharacterController::~PhysicsCharacterController()
{
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLEngine
