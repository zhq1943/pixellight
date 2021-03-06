/*********************************************************\
 *  File: XmlText.h                                      *
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


#ifndef __PLCORE_XML_TEXT_H__
#define __PLCORE_XML_TEXT_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLCore/Xml/XmlNode.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    XML text node - contained in an XML element
*/
class XmlText : public XmlNode {


	//[-------------------------------------------------------]
	//[ Friends                                               ]
	//[-------------------------------------------------------]
	friend class XmlNode;
	friend class XmlElement;


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Default constructor
		*/
		XmlText();

		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] sValue
		*    Value of this text node
		*/
		PLCORE_API XmlText(const String &sValue);

		/**
		*  @brief
		*    Copy constructor
		*
		*  @param[in] cSource
		*    Source to copy from
		*/
		PLCORE_API XmlText(const XmlText &cSource);

		/**
		*  @brief
		*    Destructor
		*/
		PLCORE_API virtual ~XmlText();

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
		PLCORE_API XmlText &operator =(const XmlText &cSource);

		/**
		*  @brief
		*    Queries whether this represents text using a CDATA section
		*
		*  @return
		*    'true' if this is input and output as a CDATA style text element, else 'false'
		*/
		inline bool IsCDATA() const;

		/**
		*  @brief
		*    Turns on or off a CDATA representation of text
		*
		*  @param[in] bCDATA
		*    'true' if this should be input and output as a CDATA style text element, else 'false'
		*/
		inline void SetCDATA(bool bCDATA);


	//[-------------------------------------------------------]
	//[ Public virtual XmlBase functions                      ]
	//[-------------------------------------------------------]
	public:
		PLCORE_API virtual bool Save(File &cFile, uint32 nDepth = 0) override;
		PLCORE_API virtual String ToString(uint32 nDepth = 0) const override;
		PLCORE_API virtual const char *Parse(const char *pszData, XmlParsingData *pData = nullptr, EEncoding nEncoding = EncodingUnknown) override;


	//[-------------------------------------------------------]
	//[ Public virtual XmlNode functions                      ]
	//[-------------------------------------------------------]
	public:
		PLCORE_API virtual XmlNode *Clone() const override;


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		bool m_bCDATA;	/**< 'true' if this should be input and output as a CDATA style text element */


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore


//[-------------------------------------------------------]
//[ Implementation                                        ]
//[-------------------------------------------------------]
#include "PLCore/Xml/XmlText.inl"


#endif // __PLCORE_XML_TEXT_H__
