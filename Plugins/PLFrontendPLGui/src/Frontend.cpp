/*********************************************************\
 *  File: Frontend.cpp                                   *
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
#include <PLCore/Runtime.h>
#include <PLCore/File/File.h>
#include <PLCore/System/System.h>
#include <PLCore/Tools/Timing.h>
#include <PLCore/Tools/LoadableManager.h>
#include <PLCore/Frontend/Frontend.h>
#include <PLCore/Frontend/FrontendContext.h>
#include <PLGui/Gui/Gui.h>
#include <PLGui/Gui/Base/Keys.h>
#include <PLGui/Widgets/Windows/Window.h>
#include "PLFrontendPLGui/Frontend.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLCore;
using namespace PLMath;
using namespace PLGraphics;
using namespace PLGui;
namespace PLFrontendPLGui {


//[-------------------------------------------------------]
//[ RTTI interface                                        ]
//[-------------------------------------------------------]
pl_implement_class(Frontend)


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
Frontend::Frontend() :
	EventHandlerDestroyMainWindow (&Frontend::OnDestroyMainWindow,  this),
	EventHandlerActivateMainWindow(&Frontend::OnActivateMainWindow, this),
	EventHandlerDrawMainWindow    (&Frontend::OnDrawMainWindow,     this),
	EventHandlerSizeMainWindow    (&Frontend::OnSizeMainWindow,     this),
	EventHandlerKeyDownMainWindow (&Frontend::OnKeyDownMainWindow,  this),
	EventHandlerDropMainWindow    (&Frontend::OnDropMainWindow,     this),
	m_pMainWindow(nullptr),
	m_nHotkeyIDAltTab(0),
	m_bToggleFullscreenMode(true),
	m_bFullscreenAltTab(true),
	m_bIsFullscreen(false),
	m_bMainWindowPositionSizeBackup(false)
{
}

/**
*  @brief
*    Destructor
*/
Frontend::~Frontend()
{
}

/**
*  @brief
*    Get main window
*/
Widget *Frontend::GetMainWindow() const
{
	// Return pointer to main window
	return m_pMainWindow;
}

/**
*  @brief
*    Set main window
*/
void Frontend::SetMainWindow(Widget *pMainWindow)
{
	// Disconnect event handler
	if (m_pMainWindow) {
		m_pMainWindow->SignalDestroy .Disconnect(EventHandlerDestroyMainWindow);
		m_pMainWindow->SignalActivate.Disconnect(EventHandlerActivateMainWindow);
		m_pMainWindow->SignalDraw    .Disconnect(EventHandlerDrawMainWindow);
		m_pMainWindow->SignalSize    .Disconnect(EventHandlerSizeMainWindow);
		m_pMainWindow->SignalKeyDown .Disconnect(EventHandlerKeyDownMainWindow);
		m_pMainWindow->SignalDrop    .Disconnect(EventHandlerDropMainWindow);
		// [TODO] Linux: Currently we need to listen to the content widget key signals as well ("focus follows mouse"-topic)
		if (m_pMainWindow->GetContentWidget() != m_pMainWindow) {
			m_pMainWindow->GetContentWidget()->SignalKeyDown.Disconnect(EventHandlerKeyDownMainWindow);
			m_pMainWindow->GetContentWidget()->SignalDrop   .Disconnect(EventHandlerDropMainWindow);
		}
	}

	// Set pointer to main window
	m_pMainWindow = pMainWindow;

	// Connect event handler
	if (m_pMainWindow) {
		m_pMainWindow->SignalDestroy .Connect(EventHandlerDestroyMainWindow);
		m_pMainWindow->SignalActivate.Connect(EventHandlerActivateMainWindow);
		m_pMainWindow->SignalDraw    .Connect(EventHandlerDrawMainWindow);
		m_pMainWindow->SignalSize    .Connect(EventHandlerSizeMainWindow);
		m_pMainWindow->SignalKeyDown .Connect(EventHandlerKeyDownMainWindow);
		m_pMainWindow->SignalDrop    .Connect(EventHandlerDropMainWindow);
		// [TODO] Linux: Currently we need to listen to the content widget key signals as well ("focus follows mouse"-topic)
		if (m_pMainWindow->GetContentWidget() != m_pMainWindow) {
			m_pMainWindow->GetContentWidget()->SignalKeyDown.Connect(EventHandlerKeyDownMainWindow);
			m_pMainWindow->GetContentWidget()->SignalDrop   .Connect(EventHandlerDropMainWindow);
		}
	}
}


//[-------------------------------------------------------]
//[ Protected virtual PLCore::AbstractLifecycle functions ]
//[-------------------------------------------------------]
void Frontend::OnCreate()
{
	{ // PLGui requires some images stored within "Standard.zip", it's the responsibility of this frontend to ensure it has all it needs
		LoadableManager *pLoadableManager = LoadableManager::GetInstance();

		// Scan for packages in current "Data" directory
		String sFilename = System::GetInstance()->GetCurrentDir() + "/Data/Standard.zip";
		if (File(sFilename).IsFile()) {
			pLoadableManager->AddBaseDir(sFilename);
		} else {
			if (GetFrontend()) {
				// Scan for packages in application's "Data" directory
				sFilename = GetFrontend()->GetContext().GetAppDirectory() + "/Data/Standard.zip";
				if (File(sFilename).IsFile()) {
					pLoadableManager->AddBaseDir(sFilename);
				} else {
					// Scan PL-runtime directory for compatible data and register it?
					// [TODO] Only when runtime should be used
					// Get PixelLight runtime data directory
					const String sPLDataDirectory = Runtime::GetDataDirectory();
					if (sPLDataDirectory.GetLength()) {
						sFilename = sPLDataDirectory + "/Standard.zip";
						if (File(sFilename).IsFile())
							pLoadableManager->AddBaseDir(sFilename);
					}
				}
			}
		}
	}

	// Call the base implementation
	FrontendImpl::OnCreate();
}


//[-------------------------------------------------------]
//[ Protected virtual PLCore::FrontendImpl functions      ]
//[-------------------------------------------------------]
int Frontend::Run(const String &sExecutableFilename, const Array<String> &lstArguments)
{
	// Create main window
	OnCreateMainWindow();

	// The frontend main loop
	while (Gui::GetSystemGui()->IsActive() && m_pMainWindow && m_pMainWindow->GetNativeWindowHandle() && m_pFrontend && m_pFrontend->IsRunning()) {
		// Redraw & ping
		Redraw();
		Ping();
	}

	// Destroy main window
	if (m_pMainWindow) {
		m_pMainWindow->Destroy();
		m_pMainWindow = nullptr;
	}

	// Shut down system GUI
	Gui::GetSystemGui()->Shutdown();

	// Done
	return 0;
}

handle Frontend::GetNativeWindowHandle() const
{
	return (m_pMainWindow && m_pMainWindow->GetContentWidget()) ? m_pMainWindow->GetContentWidget()->GetNativeWindowHandle() : NULL_HANDLE;
}

void Frontend::Redraw()
{
	// Ask PLGui politly to update (and repaint) the widget
	if (m_pMainWindow)
		m_pMainWindow->Redraw();
}

void Frontend::Ping()
{
	// Check if there are system messages waiting (non-blocking)
	if (Gui::GetSystemGui()->HasPendingMessages()) {
		// Process all waiting messages
		Gui::GetSystemGui()->ProcessMessages();
	}

	// Check if we're allowed to perform an update right now
	if (Timing::GetInstance()->Update()) {
		// Let the frontend update it's states
		OnUpdate();
	}
}

uint32 Frontend::GetWidth() const
{
	// Query the main window
	return m_pMainWindow ? m_pMainWindow->GetSize().x : 0;
}

uint32 Frontend::GetHeight() const
{
	return m_pMainWindow ? m_pMainWindow->GetSize().y : 0;
}

bool Frontend::GetToggleFullscreenMode() const
{
	return m_bToggleFullscreenMode;
}

void Frontend::SetToggleFullscreenMode(bool bToggleFullscreenMode)
{
	m_bToggleFullscreenMode = bToggleFullscreenMode;
}

bool Frontend::GetFullscreenAltTab() const
{
	return m_bFullscreenAltTab;
}

void Frontend::SetFullscreenAltTab(bool bAllowed)
{
	// Is there a state change?
	if (m_bFullscreenAltTab != bAllowed) {
		// Set the new state
		m_bFullscreenAltTab = bAllowed;

		// Update the Alt-Tab handling
		UpdateAltTab();
	}
}

bool Frontend::IsFullscreen() const
{
	return m_bIsFullscreen;
}

void Frontend::SetFullscreen(bool bFullscreen)
{
	// Is there a state change?
	if (m_bIsFullscreen != bFullscreen) {
		// Set the new state
		m_bIsFullscreen = bFullscreen;

		// Update the Alt-Tab handling
		UpdateAltTab();

		// Backup the current window position & size?
		if (m_pMainWindow && bFullscreen && !m_bMainWindowPositionSizeBackup) {
			m_vMainWindowPositionBackup		= m_pMainWindow->GetPos();
			m_vMainWindowSizeBackup			= m_pMainWindow->GetSize();
			m_bMainWindowPositionSizeBackup	= true;
		}

		// Inform that the fullscreen mode was changed
		OnFullscreenMode();

		// Set widget into fullscreen state?
		if (m_pMainWindow) {
			if (bFullscreen) {
				m_pMainWindow->SetWindowState(StateFullscreen);
			} else {
				m_pMainWindow->SetWindowState(StateNormal);

				// Restore window position & size
				if (m_bMainWindowPositionSizeBackup) {
					m_pMainWindow->SetPos(m_vMainWindowPositionBackup);
					m_pMainWindow->SetSize(m_vMainWindowSizeBackup);
					m_bMainWindowPositionSizeBackup = false;
				}
			}
		}
	}
}

bool Frontend::IsMouseVisible() const
{
	return (m_pMainWindow && m_pMainWindow->GetGui()) ? m_pMainWindow->GetGui()->IsMouseVisible() : false;
}

void Frontend::SetMouseVisible(bool bVisible)
{
	if (m_pMainWindow && m_pMainWindow->GetGui())
		m_pMainWindow->GetGui()->SetMouseVisible(bVisible);
}

void Frontend::SetTrapMouse(bool bTrap)
{
	if (m_pMainWindow)
		m_pMainWindow->SetTrapMouse(bTrap);
}


//[-------------------------------------------------------]
//[ Protected virtual Frontend functions                  ]
//[-------------------------------------------------------]
/**
*  @brief
*    Function that is called to open the application's main window
*/
void Frontend::OnCreateMainWindow()
{
	// Create standard window
	Window *pWindow = new Window();
	pWindow->AddModifier("PLGui::ModClose", "ExitApplication=1");
	pWindow->SetSize(Vector2i(640, 480));
	pWindow->SetTitle(GetFrontend() ? GetFrontend()->GetContext().GetName() : "");

	// There's no need to have a widget background because we're render into it
	// (avoids flickering caused by automatic background overdraw)
	pWindow->GetContentWidget()->SetBackgroundColor(Color4::Transparent);

	// [TODO] Add within PLGui something like MessageOnEnterMoveSize&MessageOnLeaveMoveSize?
	//        Background: When moving/sizing the window, the application will also be paused during this period (WM_EXITSIZEMOVE/WM_ENTERSIZEMOVE MS Windows events)...
	//                    it's just annyoing when you move or size a window and the controlled scene camera is spinning around while you do so...

	// Set main window
	SetMainWindow(pWindow);

	// Show the window, but do not activate it right now
	pWindow->SetVisible(true);

	// Do the frontend lifecycle thing - start
	OnStart();

	// Show and activate the window
	pWindow->Activate();
}


//[-------------------------------------------------------]
//[ Private functions                                     ]
//[-------------------------------------------------------]
/**
*  @brief
*    Updates the Alt-Tab handling
*/
void Frontend::UpdateAltTab()
{
	if (m_pMainWindow) {
		// Register/unregister hotkey
		if (m_bFullscreenAltTab && m_bIsFullscreen) {
			// Catch Alt-Tab hotkey so it can't be used during fullscreen
			if (!m_nHotkeyIDAltTab)
				m_nHotkeyIDAltTab = m_pMainWindow->RegisterHotkey(PLGUIMOD_ALT, PLGUIKEY_TAB);
		} else {
			// Release Alt-Tab hotkey
			if (m_nHotkeyIDAltTab)
				m_pMainWindow->UnregisterHotkey(m_nHotkeyIDAltTab);
		}
	}
}

/**
*  @brief
*    Called when main window was destroyed
*/
void Frontend::OnDestroyMainWindow()
{
	// Do the frontend lifecycle thing - stop
	OnStop();

	// We lost our main window :/
	m_pMainWindow = nullptr;
}

/**
*  @brief
*    Called when main window was (de-)activated
*/
void Frontend::OnActivateMainWindow(bool bActivate)
{
	// Do the frontend lifecycle thing - resume/pause
	if (bActivate)
		OnResume();
	else
		OnPause();
}

/**
*  @brief
*    Called when main window was drawn
*/
void Frontend::OnDrawMainWindow(Graphics &cGraphics)
{
	// Let the frontend draw into it's window
	OnDraw();
}

/**
*  @brief
*    Called when the main window gets resized
*/
void Frontend::OnSizeMainWindow(const Vector2i &vSize)
{
	// Inform that the window size has been changed
	OnSize();
}

/**
*  @brief
*    Called when a key is pressed down
*/
void Frontend::OnKeyDownMainWindow(uint32 nKey, uint32 nModifiers)
{
	// Is it allowed to toggle the fullscreen mode using hotkeys? If so, toggle fullscreen right now? (Alt-Return or AltGr-Return)
	if (m_bToggleFullscreenMode && nKey == PLGUIKEY_RETURN && ((nModifiers & PLGUIMOD_ALT) != 0)) {
		// Toggle fullscreen mode
		SetFullscreen(!IsFullscreen());
	}
}

/**
*  @brief
*    Called when data has been dropped onto the main window
*/
void Frontend::OnDropMainWindow(const DataObject &cData)
{
	OnDrop(cData.GetFiles());
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLFrontendPLGui
