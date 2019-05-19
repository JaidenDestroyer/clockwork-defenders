#ifndef PFEL_OPENGL_HPP
#define PFEL_OPENGL_HPP

// Headers
#include <PFEL/Config.hpp>


// Simply includes the OpenGL headers,
// since they have different paths on each system
#if defined(PFEL_SYSTEM_WINDOWS)
	// Windows

	// The Visual C++ version of gl.h requires WINGDAPI and APIENTRY but does not define them
	#ifdef _MSC_VER
		#include <windows.h>
	#endif

	#include <GL/gl.h>

#elif defined(PFEL_SYSTEM_LINUX) || defined(PFEL_SYSTEM_FREEBSD) || defined(PFEL_SYSTEM_OPENBSD)
	// Linux / FreeBSD / OpenBSD
	
	#ifdef (PFEL_OPENGL_ES)
		#include <GLES/gl.h>
		#include <GLES/glext.h>
	#else 
		#include <GL/gl.h>
	#endif

#elif defined(PFEL_SYSTEM_ANDROID)
	// Android

	#include <GLES/gl.h>
	#include <GLES/glext.h>
	
	// [COMMENT_IDK]
	#include <GLES2/gl2platform.h>
	#include <GLES2/gl2ext.h>

#elif defined(PFEL_SYSTEM_MACOS)
	// Mac

	#include <OpenGL/gl.h>
	
#elif defined(PFEL_SYSTEM_IOS)
	// iOS

	#include <OpenGLES/ES1/gl.h>
	#include <OpenGLES/ES1/glext.h> 

#endif

#endif // PFEL_OPENGL_HPP

