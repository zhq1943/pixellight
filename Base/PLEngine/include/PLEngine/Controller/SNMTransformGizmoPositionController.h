/*********************************************************\
 *  File: SNMTransformGizmoPositionController.h          *
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


#ifndef __PLENGINE_SCENENODEMODIFIER_TRANSFORMGIZMOPOSITIONCONTROLLER_H__
#define __PLENGINE_SCENENODEMODIFIER_TRANSFORMGIZMOPOSITIONCONTROLLER_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLScene/Scene/SceneNodeModifiers/SNMTransformGizmoPosition.h>
#include "PLEngine/PLEngine.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLEngine {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Position transform gizmo controller scene node modifier
*/
class SNMTransformGizmoPositionController : public PLScene::SNMTransformGizmoPosition {


	//[-------------------------------------------------------]
	//[ RTTI interface                                        ]
	//[-------------------------------------------------------]
	pl_class(PL_RTTI_EXPORT, SNMTransformGizmoPositionController, "PLEngine", PLScene::SNMTransformGizmoPosition, "Position transform gizmo controller scene node modifier")
		// Constructors
		pl_constructor_1(ParameterConstructor,	PLScene::SceneNode&,	"Parameter constructor",	"")
	pl_class_end


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] cSceneNode
		*    Owner scene node
		*/
		PL_API SNMTransformGizmoPositionController(PLScene::SceneNode &cSceneNode);

		/**
		*  @brief
		*    Destructor
		*/
		PL_API virtual ~SNMTransformGizmoPositionController();


	//[-------------------------------------------------------]
	//[ Private virtual PLScene::SNMTransformGizmo functions  ]
	//[-------------------------------------------------------]
	private:
		virtual void UpdateSelection(PLRenderer::Renderer &cRenderer, const PLScene::VisNode &cVisNode) override;
		virtual void PerformTransform() override;


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLEngine


#endif // __PLENGINE_SCENENODEMODIFIER_TRANSFORMGIZMOPOSITIONCONTROLLER_H__
