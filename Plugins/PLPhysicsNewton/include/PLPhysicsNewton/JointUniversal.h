/*********************************************************\
 *  File: JointUniversal.h                               *
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


#ifndef __PLPHYSICSNEWTON_JOINTUNIVERSAL_H__
#define __PLPHYSICSNEWTON_JOINTUNIVERSAL_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLPhysics/JointUniversal.h>
#include "PLPhysicsNewton/PLPhysicsNewton.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLPhysicsNewton {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Newton physics universal joint implementation
*/
class JointUniversal : public PLPhysics::JointUniversal {


	//[-------------------------------------------------------]
	//[ Friends                                               ]
	//[-------------------------------------------------------]
	friend class World;


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Destructor
		*/
		PLPHYSICSNEWTON_API virtual ~JointUniversal();


	//[-------------------------------------------------------]
	//[ Public Newton callback functions                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Static Newton joint user callback function
		*
		*  @param[in] pNewtonJoint
		*    Newton joint (always valid!)
		*  @param[in] pDesc
		*    Description (always valid!)
		*
		*  @return
		*     0 if the joint acceleration is not set, 1 if only the joint linear acceleration is set,
		*     2 if only the joint angular acceleration is set, 3 if the joint linear and angular acceleration is set
		*/
		static PLPHYSICSNEWTON_API unsigned JointUserCallback(const Newton::NewtonJoint *pNewtonJoint, Newton::NewtonHingeSliderUpdateDesc *pDesc);


	//[-------------------------------------------------------]
	//[ Private functions                                     ]
	//[-------------------------------------------------------]
	private:
		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] cWorld
		*    World this joint is in
		*  @param[in] pParentBody
		*    Pointer to the parent rigid body, can be a null pointer
		*  @param[in] pChildBody
		*    Pointer to the attached rigid body, can be a null pointer
		*  @param[in] vPivotPoint
		*    Origin of the universal in world space
		*  @param[in] vPinDir1
		*    First axis of rotation fixed on THIS body and perpendicular to 'PinDir2' in world space
		*  @param[in] vPinDir2
		*    Second axis of rotation fixed on 'Parent' body and perpendicular to 'PinDir1' in world space
		*/
		JointUniversal(PLPhysics::World &cWorld, PLPhysics::Body *pParentBody, PLPhysics::Body *pChildBody, const PLMath::Vector3 &vPivotPoint,
					   const PLMath::Vector3 &vPinDir1, const PLMath::Vector3 &vPinDir2);


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		PLMath::Vector3 m_vLocalAnchor;	/**< Anchor position in body object space it's attached to */


	//[-------------------------------------------------------]
	//[ Public virtual PLPhysics::Joint functions             ]
	//[-------------------------------------------------------]
	public:
		PLPHYSICSNEWTON_API virtual void GetCurrentPivotPoint(PLMath::Vector3 &vPosition) const override;


	//[-------------------------------------------------------]
	//[ Public virtual PLPhysics::JointUniversal functions    ]
	//[-------------------------------------------------------]
	public:
		PLPHYSICSNEWTON_API virtual void AddOmega(float fOmega1, float fOmega2) override;


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLPhysicsNewton


#endif // __PLPHYSICSNEWTON_JOINTUNIVERSAL_H__
