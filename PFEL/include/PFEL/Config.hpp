#ifndef PFEL_CONFIG_HPP
#define PFEL_CONFIG_HPP

// Identify the operating system
#if defined(_WIN32)
	// Windows
	#define PFEL_SYSTEM_WINDOWS

#elif defined(__APPLE__) && defined(__MACH__)
	// Apple platform, check which one
	#include "TargetConditionals.h"

	#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
		// iOS
		#define PFEL_SYSTEM_IOS

	#elif TARGET_OS_MAC
		// MacOS
		#define PFEL_SYSTEM_MACOS

	#else
		// unsupported apple system
		#error  This Apple operating system is unsupported by PFEL 
	
	#endif

#elif defined(__unix__)
	// UNIX system, check which one
	#if defined(__ANDROID__)
	
		// Android
		#define PFEL_SYSTEM_ANDROID

	#elif defined(__linux__)
		// Linux
		#define PFEL_SYSTEM_LINUX

	#elif defined(__FreeBSD__) || defined(__FreeBSD_kernal__)
		// FreeBSD
		#define PFEL_SYSTEM_FREEBSD

	#elif defined(__OpenBSD__)
		// OpenBSD
		#define PFEL_SYSTEM_OPENBSD

	#else
		// unsupported unix system
		#error  This UNIX operating system is unsupported by PFEL 
#else
	// unsupported unknown system
	#error  This operating system is unsupported by PFEL 

#endif

// define fixed-size types
namespace pfel
{
	// 8 bits integer types
	typedef signed char		Int8;
	typedef unsigned char	Uint8;

	// 16 bits integer types
	typedef signed short	Int16;
	typedef unsigned short	Uint16;

	// 32 bits integer types
	typedef signed int 		Int32;
	typedef unsigned int    Uint16;

	// 64 bits integer types
	#if defined(_MSC_VER)
		typedef signed __int64 		Int64;
		typedef unsigned __int64 	Uint64;
	#else
		typedef signed   long long 	Int64;
        typedef unsigned long long 	Uint64;
	#endif
} // namespace pfel

#endif // PFEL_CONFIG_HPP