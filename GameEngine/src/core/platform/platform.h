#ifndef PLATFORM_H
#define PLATFORM_H

/*
This file contains all the preprocessors definitions
for recognizing platforms and Dll Export macros of the engine.
*/

#ifdef _WIN64
	#define PLATFORM_WIN64
#elif _WIN32
	#define PLATFORM_WIN32
#elif __APPLE__
	#include "TargetConditionals.h"
	#if TARGET_OS_IPHONE && TARGET_IPHONE_SIMULATOR
		#define PLATFORM_IOS_SIM
	#elif TARGET_OS_IPHONE
		#define PLATFORM_IPHONE
	#else
	#define PLATFORM_MACOS
#endif
#elif __linux
	#define PLATFORM_LINUX
#elif __unix // all unices not caught above
	#define PLATFORM_UNIX
#elif __posix
	#define PLATFORM_POSIX
#endif

#if defined(_MSC_VER)
	#define ENGINE_API __declspec(dllexport)
#elif defined(__GNUC__)
	#define EXPORT __attribute__((visibility("default")))
#else
	#define EXPORT
	#pragma warning Unknown dynamic link import/export semantics.
#endif


#endif // !PLATFORM_H
