/*********************************************************\
 *  File: SNMMeshMorphBlink.cpp                          *
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


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLGeneral/Tools/Timing.h>
#include "PLScene/Scene/SceneContext.h"
#include "PLScene/Scene/SceneNodeModifiers/SNMMeshMorphBlink.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLGeneral;
using namespace PLMath;
namespace PLScene {


//[-------------------------------------------------------]
//[ RTTI interface                                        ]
//[-------------------------------------------------------]
pl_implement_class(SNMMeshMorphBlink)


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
SNMMeshMorphBlink::SNMMeshMorphBlink(SceneNode &cSceneNode) : SNMMeshMorph(cSceneNode),
	Time(this),
	TimeBase(this),
	TimeRandom(this),
	Direction(this),
	Speed(this),
	SlotOnUpdate(this)
{
}

/**
*  @brief
*    Destructor
*/
SNMMeshMorphBlink::~SNMMeshMorphBlink()
{
}


//[-------------------------------------------------------]
//[ Protected virtual SceneNodeModifier functions         ]
//[-------------------------------------------------------]
void SNMMeshMorphBlink::OnActivate(bool bActivate)
{
	// Connect/disconnect event handler
	SceneContext *pSceneContext = GetSceneContext();
	if (pSceneContext) {
		if (bActivate)
			pSceneContext->EventUpdate.Connect(SlotOnUpdate);
		else
			pSceneContext->EventUpdate.Disconnect(SlotOnUpdate);
	}
}


//[-------------------------------------------------------]
//[ Private functions                                     ]
//[-------------------------------------------------------]
/**
*  @brief
*    Called when the scene node modifier needs to be updated
*/
void SNMMeshMorphBlink::OnUpdate()
{
	// Get time difference
	const float fTimeDiff = Timing::GetInstance()->GetTimeDifference();

	// Update animation start
	if (!Direction) {
		Time = Time - fTimeDiff;
		if (Time < 0.0f) {
			Time      = TimeBase + Math::GetRandFloat()*TimeRandom;
			Direction = true;
		}
	}

	// Update animation playback
	const float fPreviousWeight = m_fWeight;
	if (Direction) {
		m_fWeight += fTimeDiff*Speed;
		if (m_fWeight >= m_fMaxWeight) {
			m_fWeight = m_fMaxWeight;
			Direction = false;
		}
	} else {
		m_fWeight -= fTimeDiff*Speed;
		if (m_fWeight < m_fMinWeight)
			m_fWeight = m_fMinWeight;
	}

	// Update the morph target if required
	if (fPreviousWeight != m_fWeight)
		UpdateMorphTarget();
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLScene