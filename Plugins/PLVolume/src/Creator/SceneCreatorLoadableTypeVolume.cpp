/*********************************************************\
 *  File: SceneCreatorLoadableTypeVolume.cpp             *
 *
 *  Copyright (C) 2002-2012 The PixelLight Team (http://www.pixellight.org/)
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


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLScene/Scene/SceneContainer.h>
#include <PLEngine/Application/EngineApplication.h>
#include "PLVolume/Creator/SceneCreatorLoadableTypeVolume.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLCore;
using namespace PLScene;
namespace PLVolume {


//[-------------------------------------------------------]
//[ RTTI interface                                        ]
//[-------------------------------------------------------]
pl_implement_class(SceneCreatorLoadableTypeVolume)


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Default constructor
*/
SceneCreatorLoadableTypeVolume::SceneCreatorLoadableTypeVolume()
{
}

/**
*  @brief
*    Destructor
*/
SceneCreatorLoadableTypeVolume::~SceneCreatorLoadableTypeVolume()
{
}


//[-------------------------------------------------------]
//[ Public virtual SceneCreator functions                 ]
//[-------------------------------------------------------]
SNCamera *SceneCreatorLoadableTypeVolume::Create(SceneContainer &cSceneContainer) const
{
	{ // [HACK][TODO] Scene creator: Make it possible to specify preferred scene renderer
		const PLCore::String sFilename = "Volume.sr";
		static_cast<PLEngine::EngineApplication*>(PLCore::CoreApplication::GetApplication())->GetSceneRendererTool().SetSceneRenderer(&cSceneContainer, sFilename, sFilename);
	}

	// Create a scene node representing the volume, most volumes look better with a 180 degree rotation around the z-axis
	SceneNode *pPrimarySceneNode = cSceneContainer.Create("PLVolume::SNVolume", "Volume", "Rotation=\"0 0 180\" VolumeFilename=\"" + Filename.Get() + '\"');

	// Configure a generic scene and return the preferred camera scene node
	SNCamera *pCamera = SceneCreator::ConfigureGenericScene(cSceneContainer, pPrimarySceneNode);

	// When using volume rendering, a common use case is to move the camera really close to or even into the volume
	// -> The default value of the camera z-near plane is 0.1 because this value has proven
	//    to be useful when trying to cover many use cases with a single default value
	// -> When using a small scaled volume, a z-near plane value of 0.1 may cause the premature clipping of the
	//    volume, so use a smaller value instead
	{ // Update free camera
		SceneNode *pFreeCamera = cSceneContainer.GetByName("FreeCamera");
		if (pFreeCamera)
			pFreeCamera->SetAttribute("ZNear", Var<float>(0.01f));
	}
	{ // Update orbiter camera
		SceneNode *pOrbiterCamera = cSceneContainer.GetByName("OrbiterCamera");
		if (pOrbiterCamera)
			pOrbiterCamera->SetAttribute("ZNear", Var<float>(0.01f));
	}

	// Done
	return pCamera;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLVolume