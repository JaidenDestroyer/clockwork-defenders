#ifndef PFEL_WINDOWIMPLWIN32_HPP
#define PFEL_WINDOWIMPLWIN32_HPP

// Headers
#include <windows.h>

namespace pfel
{
	namespace priv
	{
		// Windows implementation of WindowImpl
		class WindowImplWin32 : public WindowImpl 
		{
			public:

				/**
				 * Construct the window implementation from an existing control
				 */
				WindowImplWin32(WindowHandle handle);

				WindowImplWin32(const std::string& title);

				// Destructor 
				~WindowImplWin32();

			private:

				// Member data
				HWND     m_handle;           ///< Win32 handle of the window
   	 			LONG_PTR m_callback;         ///< Stores the original event callback function of the control
			    bool     m_cursorVisible;    ///< Is the cursor visible or hidden?
			    HCURSOR  m_lastCursor;       ///< Last cursor used -- this data is not owned by the window and is required to be always valid
			    HICON    m_icon;             ///< Custom icon assigned to the window
			    bool     m_keyRepeatEnabled; ///< Automatic key-repeat state for keydown events
			    Vector2u m_lastSize;         ///< The last handled size of the window
			    bool     m_resizing;         ///< Is the window being resized?
			    Uint16   m_surrogate;        ///< First half of the surrogate pair, in case we're receiving a Unicode character in two events
			    bool     m_mouseInside;      ///< Mouse is inside the window?
			    bool     m_fullscreen;       ///< Is the window fullscreen?
			    bool     m_cursorGrabbed;    ///< Is the mouse cursor trapped?

		}
	} // namespace priv
} // namespace pfel

#endif // PFEL_WINDOWIMPLWIN32_HPP
