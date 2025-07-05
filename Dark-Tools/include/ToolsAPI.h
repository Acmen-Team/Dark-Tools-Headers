#pragma once

#ifdef DK_PLATFORM_WINDOWS
#if DK_DYNAMIC_LINK
#ifdef DTOOLS_BUILD_DLL
#define DTOOLS_API _declspec(dllexport)
#else
#define DTOOLS_API _declspec(dllimport)
#endif
#else
#define DTOOLS_API
#endif
#else
#error Dark Currently Supports Windows Only!
#endif
