/*********************************************************\
 *  File: Frontend.h                                     *
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


#ifndef __PLCORE_FRONTEND_H__
#define __PLCORE_FRONTEND_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLCore/Base/Object.h"
#include "PLCore/Frontend/AbstractFrontend.h"
#include "PLCore/Core/AbstractLifecycle.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Forward declarations                                  ]
//[-------------------------------------------------------]
class String;
class FrontendImpl;
class FrontendContext;
template <class ValueType> class Array;


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Abstract frontend base class
*
*  @remarks
*    This base class provides an abstract frontend API which is used to develop
*    an actual PixelLight frontend class. Concrete wrappers for certain browsers,
*    such as MS Internet Explorer or Mozilla Firefox are used to map the browser
*    specific frontend API to this general base class.
*
*    The focus of this class is on applications with just one window (if there's a window
*    at all, this depends on the used frontend implementation). This focus makes application development
*    somewhat easier because you only have to concentrate our realizing your project and not how it
*    will be presented (in a window with border, without border, just rendering into an image etc.) to
*    the user.
*
*    The PixelLight technology is designed to be as flexible as possible and so, although this
*    class has a clear focus, it can also be used to develop multi-window applications as well.
*
*    Please note that the frontend system is not designed to be a replacement for a decent GUI
*    system. In here, only primitive and commonly used GUI related feature are offered with a
*    limited feature set. For more complex stuff one has to use a real GUI system.
*
*  @note
*    - Do only interact with the frontend when it really makes sense because it's not guaranteed
*      that every frontend implementation provides every feature exposed by this interface
*    - Stuff like window border, window title bar etc. isn't interesting for the frontend, therefore
*      methods like "GetNativeWindowHandle()" or "GetWidth()" return only information relevant for e.g.
*      rendering into the frontend
*/
class Frontend : public Object, protected AbstractLifecycle, protected AbstractFrontend {


	//[-------------------------------------------------------]
	//[ Friends                                               ]
	//[-------------------------------------------------------]
	friend class FrontendImpl;


	//[-------------------------------------------------------]
	//[ RTTI interface                                        ]
	//[-------------------------------------------------------]
	pl_class(PLCORE_RTTI_EXPORT, Frontend, "PLCore", PLCore::Object, "Abstract frontend base class")
		#ifdef PLCORE_EXPORTS	// The following is only required when compiling PLCore
			// Methods
			pl_method_0(Redraw,						pl_ret_type(void),										"Redraw frontend.",																																											"")
			pl_method_0(Ping,						pl_ret_type(void),										"Give the frontend a chance to process OS messages.",																																		"")
			pl_method_0(RedrawAndPing,				pl_ret_type(void),										"Redraw frontend and give the frontend a chance to process OS messages.",																													"")
			pl_method_0(GetTitle,					pl_ret_type(String),									"Returns the frontend title.",																																								"")
			pl_method_1(SetTitle,					pl_ret_type(void),		const String&,					"Sets the frontend title.",																																									"")
			// Position and size methods
			pl_method_0(GetX,						pl_ret_type(int),										"Returns the x position of the frontend (in screen coordinates).",																															"")
			pl_method_0(GetY,						pl_ret_type(int),										"Returns the y position of the frontend (in screen coordinates).",																															"")
			pl_method_0(GetWidth,					pl_ret_type(uint32),									"Returns the frontend width.",																																								"")
			pl_method_0(GetHeight,					pl_ret_type(uint32),									"Returns the frontend height.",																																								"")
			pl_method_4(SetPositionSize,			pl_ret_type(void),		int,	int,	uint32,	uint32,	"Set frontend position and size. X and y position of the frontend (in screen coordinates) as the first two parameters, width and height of the frontend as third and fourth parameters.",	"")
			// Fullscreen methods
			pl_method_0(GetToggleFullscreenMode,	pl_ret_type(bool),										"Returns whether it's allowed to toggle the fullscreen mode using hotkeys. 'true' if it's possible to toggle the fullscreen mode using hotkeys, else 'false'.",								"")
			pl_method_1(SetToggleFullscreenMode,	pl_ret_type(void),		bool,							"Sets whether it's allowed to toggle the fullscreen mode using hotkeys. 'true' as first parameter to allow it, else 'false'.",																"")
			pl_method_0(GetFullscreenAltTab,		pl_ret_type(bool),										"Returns whether it's allowed to use Alt-Tab if fullscreen mode is used. 'true' if it's possible to use Alt-Tab if fullscreen mode is used, else 'false'.",									"")
			pl_method_1(SetFullscreenAltTab,		pl_ret_type(void),		bool,							"Sets whether it's allowed to use Alt-Tab if fullscreen mode is used. 'true' as first parameter to allow it, else 'false'.",																"")
			pl_method_0(IsFullscreen,				pl_ret_type(bool),										"Returns whether or not the frontend is currently fullscreen or not. Returns 'true' if the frontend is currently fullscreen, else 'false'.",												"")
			pl_method_1(SetFullscreen,				pl_ret_type(void),		bool,							"Sets whether or not the frontend is currently fullscreen or not. 'true' as first parameter if the frontend is currently fullscreen, else 'false'.",										"")
			// Mouse methods
			pl_method_0(IsMouseOver,				pl_ret_type(bool),										"Returns whether or not the mouse cursor is currently over the frontend. Returns 'true' if the mouse cursor is currently over the frontend, else 'false'.",									"")
			pl_method_0(GetMousePositionX,			pl_ret_type(int),										"Returns the current mouse cursor X position inside the frontend, negative value if the mouse cursor isn't currently over the frontend",													"")
			pl_method_0(GetMousePositionY,			pl_ret_type(int),										"Returns the current mouse cursor Y position inside the frontend, negative value if the mouse cursor isn't currently over the frontend",													"")
			pl_method_0(IsMouseVisible,				pl_ret_type(bool),										"Returns whether or not the mouse cursor is currently visible. Returns 'true' if the mouse cursor is currently visible, else 'false'.",														"")
			pl_method_1(SetMouseVisible,			pl_ret_type(void),		bool,							"Set the mouse cursor visibility. 'true' as first parameter if the mouse cursor shall be visible.",																							"")
			pl_method_1(SetTrapMouse,				pl_ret_type(void),		bool,							"Trap the mouse inside the frontend. 'true' as first parameter if the mouse should be trapped inside the frontend, else 'false'.",															"")
		#endif
	pl_class_end


	//[-------------------------------------------------------]
	//[ Public static functions                               ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Run the frontend
		*
		*  @param[in] cFrontendContext
		*    Frontend context to use (just shared, the given instance must stay valid as long as this frontend lives)
		*
		*  @return
		*    Exit code (usually 0 means no error), usually <0 when there was an error
		*    (e.g. an embedded frontend implementation is run and controlled by another application and can't be run by using this method)
		*/
		static PLCORE_API int Run(const FrontendContext &cFrontendContext);


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] cFrontendContext
		*    Frontend context to use (just shared, the given instance must stay valid as long as this frontend lives)
		*  @param[in] cFrontendImpl
		*    Frontend implementation instance
		*/
		PLCORE_API Frontend(const FrontendContext &cFrontendContext, FrontendImpl &cFrontendImpl);

		/**
		*  @brief
		*    Destructor
		*/
		PLCORE_API virtual ~Frontend();

		/**
		*  @brief
		*    Get frontend context
		*
		*  @return
		*    Frontend context
		*/
		PLCORE_API const FrontendContext &GetContext() const;

		/**
		*  @brief
		*    Get native window handle
		*
		*  @return
		*    Native window handle for the frontend window, can be a null pointer
		*/
		PLCORE_API handle GetNativeWindowHandle() const;

		/**
		*  @brief
		*    Redraw frontend
		*
		*  @remarks
		*    There are situations were an application may do some heavy work without letting
		*    the frontend a chance to redraw. In such situations, it may be wise
		*    to call this method from time to time to give the frontend a chance to do redraw
		*    itself.
		*
		*  @note
		*    - Whenever possible, don't use this method, do heavy work within e.g. threads
		*    - Depending on the frontend implementation, the redraw may not be immediate
		*    - Doesn't include "Ping()"
		*/
		PLCORE_API void Redraw();

		/**
		*  @brief
		*    Give the frontend a chance to process OS messages
		*
		*  @remarks
		*    There are situations were an application may do some heavy work without letting
		*    the frontend a chance to process OS messages. In such situations, it may be wise
		*    to call this method from time to time to give the frontend a chance to do some
		*    message processing.
		*
		*  @note
		*    - Whenever possible, don't use this method, do heavy work within e.g. threads
		*    - Doesn't include "Redraw()"
		*/
		PLCORE_API void Ping() const;

		/**
		*  @brief
		*    Redraw frontend and give the frontend a chance to process OS messages
		*
		*  @remarks
		*    Calls "Redraw()", then "Ping()".
		*
		*  @note
		*    - Whenever possible, don't use this method, do heavy work within e.g. threads
		*/
		PLCORE_API void RedrawAndPing();

		/**
		*  @brief
		*    Get frontend title
		*
		*  @return
		*    Frontend title
		*
		*  @remarks
		*    When the frontend has a window, this title can be seen within the window
		*    title bar. Please note that there's no guarantee that there's a window
		*    title bar or even a window. By default, the title is set to the frontend
		*    context name ("GetContext().GetName()") which is usually sufficient. So,
		*    unless you have a good reason to explicitly set an individual frontend
		*    title, just use the default setting and don't touch the frontend.
		*/
		PLCORE_API String GetTitle() const;

		/**
		*  @brief
		*    Set frontend title
		*
		*  @param[in] sTitle
		*    Frontend title
		*
		*  @see
		*    - GetTitle()
		*/
		PLCORE_API void SetTitle(const String &sTitle);

		//[-------------------------------------------------------]
		//[ Position and size                                     ]
		//[-------------------------------------------------------]
		/**
		*  @brief
		*    Get the x position of the frontend (in screen coordinates)
		*
		*  @return
		*    X position of the frontend
		*/
		PLCORE_API int GetX() const;

		/**
		*  @brief
		*    Get the y position of the frontend (in screen coordinates)
		*
		*  @return
		*    Y position of the frontend
		*/
		PLCORE_API int GetY() const;

		/**
		*  @brief
		*    Get frontend width
		*
		*  @return
		*    Width of the frontend
		*/
		PLCORE_API uint32 GetWidth() const;

		/**
		*  @brief
		*    Get frontend height
		*
		*  @return
		*    Height of the frontend
		*/
		PLCORE_API uint32 GetHeight() const;

		/**
		*  @brief
		*    Set frontend position and size
		*
		*  @param[in] nX
		*    X position of the frontend (in screen coordinates)
		*  @param[in] nY
		*    Y position of the frontend (in screen coordinates)
		*  @param[in] nWidth
		*    Width of the frontend
		*  @param[in] nHeight
		*    Height of the frontend
		*
		*  @remarks
		*    The primary argument to allow the user to request a frontend position and size change is,
		*    that it should be possible to restore the frontend position and size of a previous session
		*    (may be important for the usability). Do not misuse this method to frequently manipulate
		*    the frontend appearance. Please note that, as for all other frontend methods, this is only
		*    considered to be a request. A frontend implementation may deny the request in general or
		*    just improper settings (e.g. a too small size, position outside the visible screen etc.).
		*/
		PLCORE_API void SetPositionSize(int nX, int nY, uint32 nWidth, uint32 nHeight);

		//[-------------------------------------------------------]
		//[ Fullscreen                                            ]
		//[-------------------------------------------------------]
		/**
		*  @brief
		*    Gets whether it's allowed to toggle the fullscreen mode using hotkeys
		*
		*  @return
		*    'true' if it's possible to toggle the fullscreen mode using hotkeys, else 'false'
		*/
		PLCORE_API bool GetToggleFullscreenMode() const;

		/**
		*  @brief
		*    Sets whether it's allowed to toggle the fullscreen mode using hotkeys
		*
		*  @param[in] bToggleFullscreenMode
		*    Is it allowed to toggle the fullscreen mode using hotkeys?
		*
		*  @note
		*    - By default, it's allowed to switch widgets into fullscreen mode using Alt-Return or AltGr-Return
		*/
		PLCORE_API void SetToggleFullscreenMode(bool bToggleFullscreenMode);

		/**
		*  @brief
		*    Gets whether it's allowed to use Alt-Tab if fullscreen mode is used
		*
		*  @return
		*    'true' if it's possible to use Alt-Tab if fullscreen mode is used, else 'false'
		*
		*  @note
		*    - Widgets only
		*/
		PLCORE_API bool GetFullscreenAltTab() const;

		/**
		*  @brief
		*    Sets whether it's allowed to use Alt-Tab if fullscreen mode is used
		*
		*  @param[in] bAllowed
		*    Is it allowed to use Alt-Tab within fullscreen mode?
		*
		*  @note
		*    - By default, it's allowed to use Alt-Tab
		*
		*  @see
		*    - GetFullscreenAltTab()
		*/
		PLCORE_API void SetFullscreenAltTab(bool bAllowed);

		/**
		*  @brief
		*    Returns whether the frontend is in fullscreen mode or not
		*
		*  @return
		*    'true' if the frontend is in fullscreen mode, else 'false'
		*/
		PLCORE_API bool IsFullscreen() const;

		/**
		*  @brief
		*    Sets the frontend's fullscreen mode
		*
		*  @param[in] bFullscreen
		*    'true' if the frontend should be in fullscreen mode, else 'false'
		*/
		PLCORE_API void SetFullscreen(bool bFullscreen);

		/**
		*  @brief
		*    Something related to fullscreen mode has been changed (e.g. the display resolution)
		*/
		PLCORE_API void RefreshFullscreen();

		//[-------------------------------------------------------]
		//[ Mouse                                                 ]
		//[-------------------------------------------------------]
		/**
		*  @brief
		*    Check if the mouse is currently over the frontend
		*
		*  @return
		*    'true' if mouse-over, else 'false'
		*/
		PLCORE_API bool IsMouseOver() const;

		/**
		*  @brief
		*    Get current mouse cursor X position inside the frontend
		*
		*  @return
		*    Current mouse cursor X position inside the frontend, negative value if the mouse cursor isn't currently over the frontend
		*/
		PLCORE_API int GetMousePositionX() const;

		/**
		*  @brief
		*    Get current mouse cursor Y position inside the frontend
		*
		*  @return
		*    Current mouse cursor Y position inside the frontend, negative value if the mouse cursor isn't currently over the frontend
		*/
		PLCORE_API int GetMousePositionY() const;

		/**
		*  @brief
		*    Check if the mouse cursor is visible
		*
		*  @return
		*    'true' if the mouse cursor is visible, else 'false'
		*
		*  @note
		*    - If the mouse cursor is visible in general, it's still possible that it's
		*      invisible over some special widgets.
		*    - If the mouse cursor is invisible in general, it will NEVER be visible!
		*    - Do only hide the mouse cursor when it really makes sense (e.g. during the period
		*      the mouse is used to control a "camera look around")
		*/
		PLCORE_API bool IsMouseVisible() const;

		/**
		*  @brief
		*    Set mouse cursor visibility
		*
		*  @param[in] bVisible
		*    Shall the mouse cursor be visible?
		*
		*  @see
		*    - IsMouseVisible()
		*/
		PLCORE_API void SetMouseVisible(bool bVisible);

		/**
		*  @brief
		*    Trap mouse inside the frontend
		*
		*  @param[in] bTrap
		*    'true' if the mouse should be trapped inside the frontend, else 'false'
		*
		*  @note
		*    - Do only trap the mouse cursor when it really makes sense (e.g. during the period
		*      the mouse is used to control a "camera look around")
		*/
		PLCORE_API void SetTrapMouse(bool bTrap);


	//[-------------------------------------------------------]
	//[ Public virtual Frontend functions                     ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Returns whether or not the frontend is currently running
		*
		*  @return
		*    'true' if the frontend is currently running, else 'false'
		*/
		virtual bool IsRunning() const = 0;


	//[-------------------------------------------------------]
	//[ Protected functions                                   ]
	//[-------------------------------------------------------]
	protected:
		/**
		*  @brief
		*    Get frontend implementation
		*
		*  @return
		*    Pointer to the implementation backend, can be a null pointer
		*/
		PLCORE_API FrontendImpl *GetImpl() const;


	//[-------------------------------------------------------]
	//[ Protected virtual Frontend functions                  ]
	//[-------------------------------------------------------]
	protected:
		/**
		*  @brief
		*    Called when the frontend is run
		*
		*  @param[in] sExecutableFilename
		*    Absolute application executable filename
		*  @param[in] lstArguments
		*    List of arguments to the program
		*
		*  @remarks
		*    This frontend method is called just before the frontend calls it's run-method in order to
		*    enter it's main-loop. This means that this method is called between "AbstractLifecycle::OnCreate()"
		*    and "AbstractLifecycle::OnStart()". Use this method for instance to pre-process command line arguments.
		*
		*    The default implementation does the following tasks:
		*    - none (implement in derived classes)
		*/
		PLCORE_API virtual void OnRun(const String &sExecutableFilename, const Array<String> &lstArguments);


	//[-------------------------------------------------------]
	//[ Protected data                                        ]
	//[-------------------------------------------------------]
	protected:
		const FrontendContext &m_cFrontendContext;	/**< Frontend context to use (just shared, the given instance must stay valid as long as this frontend lives) */
		FrontendImpl		  *m_pFrontendImpl;		/**< Pointer to implementation backend, can be a null pointer */


	//[-------------------------------------------------------]
	//[ Private static functions                              ]
	//[-------------------------------------------------------]
	private:
		/**
		*  @brief
		*    Creates a frontend implementation instance
		*
		*  @param[in] cFrontendContext
		*    Frontend context to use
		*
		*  @return
		*    Frontend implementation instance, null pointer on error
		*/
		static FrontendImpl *CreateFrontendImplementation(const FrontendContext &cFrontendContext);


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore


#endif // __PLCORE_FRONTEND_H__
