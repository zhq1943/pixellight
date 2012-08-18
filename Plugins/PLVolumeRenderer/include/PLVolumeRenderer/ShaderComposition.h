/*********************************************************\
 *  File: ShaderComposition.h                            *
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


#ifndef __PLVOLUMERENDERER_SHADERCOMPOSITION_H__
#define __PLVOLUMERENDERER_SHADERCOMPOSITION_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLVolumeRenderer/ShaderCompositionID.h"


//[-------------------------------------------------------]
//[ Forward declarations                                  ]
//[-------------------------------------------------------]
namespace PLRenderer {
	class Program;
	class Renderer;
}
namespace PLScene {
	class SQCull;
	class VisNode;
}
namespace PLVolumeRenderer {
	class SRPVolume;
	class ShaderFunction;
	class ShaderFunctionRaySetup;
	class ShaderFunctionJitterPosition;
	class ShaderFunctionClipRay;
	class ShaderFunctionRayTraversal;
	class ShaderFunctionClipPosition;
	class ShaderFunctionReconstruction;
	class ShaderFunctionFetchScalar;
	class ShaderFunctionShading;
	class ShaderFunctionClassification;
	class ShaderFunctionGradient;
	class ShaderFunctionGradientInput;
	class ShaderFunctionIllumination;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLVolumeRenderer {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Shader composition class
*/
class ShaderComposition {


	//[-------------------------------------------------------]
	//[ Friends                                               ]
	//[-------------------------------------------------------]
	friend class ShaderCompositor;


	//[-------------------------------------------------------]
	//[ Public definitions                                    ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Direct access to shader function instances this shader composition consists of, the given instance are just shared (do not destroy them)
		*
		*  @note
		*    - In here it's safe to store direct pointers, their address will not change during runtime
		*    - If this ID is valid, all pointers are no null pointer
		*/
		struct SShaderFunction {
			// 1.0 - Ray Setup
			ShaderFunctionRaySetup			*pShaderFunctionRaySetupClass;
			// 1.1 - Clip Ray
			ShaderFunctionClipRay			*pShaderFunctionClipRayClass;
			// 1.2 - Jitter Position
			ShaderFunctionJitterPosition	*pShaderFunctionJitterPositionClass;
			// 2.0 - Ray Traversal
			ShaderFunctionRayTraversal		*pShaderFunctionRayTraversalClass;
			// 2.1 - Clip Position
			ShaderFunctionClipPosition		*pShaderFunctionClipPositionClass;
			// 2.2 - Reconstruction
			ShaderFunctionReconstruction	*pShaderFunctionReconstructionClass;
			// 2.2 - Fetch Scalar
			ShaderFunctionFetchScalar		*pShaderFunctionFetchScalarClass;
			// 2.3 - Shading
			ShaderFunctionShading			*pShaderFunctionShadingClass;
			// 2.4 - Classification
			ShaderFunctionClassification	*pShaderFunctionClassificationClass;
			// 2.5 - Gradient
			ShaderFunctionGradient			*pShaderFunctionGradientClass;
			// 2.5 - Gradient Input
			ShaderFunctionGradientInput		*pShaderFunctionGradientInputClass;
			// 2.6 - Illumination
			ShaderFunctionIllumination		*pShaderFunctionIlluminationClass;
		};


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Check for equality
		*
		*  @param[in] cOther
		*    Other shader composition to compare with
		*
		*  @return
		*    'true' if the two shader compositions are equal, else 'false'
		*/
		PLVOLUMERENDERER_API bool operator ==(const ShaderComposition &cOther) const;

		/**
		*  @brief
		*    Returns the shader composition ID
		*
		*  @return
		*    Shader composition ID
		*/
		PLVOLUMERENDERER_API const ShaderCompositionID &GetShaderCompositionID() const;

		/**
		*  @brief
		*    Returns direct access to shader function instances this shader composition consists of
		*
		*  @return
		*    Direct access to shader function instances this shader composition consists of
		*/
		PLVOLUMERENDERER_API const SShaderFunction &GetShaderFunctions() const;

		/**
		*  @brief
		*    Returns a list of shader function instances this shader composition consists of
		*
		*  @return
		*    List of shader function instances this shader composition consists of
		*/
		PLVOLUMERENDERER_API const PLCore::Array<ShaderFunction*> &GetShaderFunctionsList() const;

		/**
		*  @brief
		*    Returns the GPU program of this shader composition
		*
		*  @return
		*    the GPU program of this shader composition
		*/
		PLVOLUMERENDERER_API PLRenderer::Program &GetProgram() const;

		// [TODO] Just a test
		void SetProgram(PLRenderer::Renderer &cRenderer, const PLScene::SQCull &cCullQuery, const PLScene::VisNode &cVisNode, SRPVolume &cSRPVolume);

		/**
		*  @brief
		*    Returns a human readable representation of this shader composition
		*
		*  @return
		*    Human readable representation of this shader shader composition
		*
		*  @note
		*    - For debugging
		*/
		PLVOLUMERENDERER_API PLCore::String ToString() const;


	//[-------------------------------------------------------]
	//[ Protected functions                                   ]
	//[-------------------------------------------------------]
	protected:
		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] cShaderCompositionID
		*    Shader composition ID
		*  @param[in] cProgram
		*    GPU program of this shader composition, we're now responsible for destroying this instance
		*  @param[in] lstShaderFunction
		*    Shader function instances this shader composition consists of, the given instance are just shared (do not destroy them)
		*/
		PLVOLUMERENDERER_API ShaderComposition(const ShaderCompositionID &cShaderCompositionID, PLRenderer::Program &cProgram, const PLCore::Array<ShaderFunction*> &lstShaderFunction);

		/**
		*  @brief
		*    Destructor
		*/
		PLVOLUMERENDERER_API ~ShaderComposition();


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
		ShaderComposition(const ShaderComposition &cSource);

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
		ShaderComposition &operator =(const ShaderComposition &cSource);


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		ShaderCompositionID				m_cShaderCompositionID;	/**< Shader composition ID */
		PLRenderer::Program			   *m_pProgram;				/**< GPU program of this shader composition, always valid */
		SShaderFunction					m_sShaderFunction;		/**< Direct access to shader function instances this shader composition consists of, the given instance are just shared (do not destroy them) */
		PLCore::Array<ShaderFunction*>  m_lstShaderFunction;	/**< List of shader function instances this shader composition consists of, the given instance are just shared (do not destroy them) */


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLVolumeRenderer


#endif // __PLVOLUMERENDERER_SHADERCOMPOSITION_H__