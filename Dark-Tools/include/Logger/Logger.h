/*************************************************
Copyright © 2020 - 2024 YxY. All Rights Reserved

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Date: 2024/10/23
Description: Logger
**************************************************/
#pragma once

#include "Core/Core.h"
#include "Macro/DynamicLinkMacros.h"

namespace DTools
{

	class DARK_API Logger
	{
	public:
		Logger(const char* tag);
		~Logger();

		// Log Levels
		void Trace(const char* format, ...);
		void Info(const char* format, ...);
		void Warn(const char* format, ...);
		void Error(const char* format, ...);
		void Critical(const char* format, ...);

	private:
		// Pointer to Implementation (Pimpl)
		class DARK_API LogImpl;
		Scope<LogImpl> m_LogImpl;

	};

	// Global Logger
	extern DARK_API Ref<Logger> s_CoreLogger;
	extern DARK_API Ref<Logger> s_ClientLogger;

} // namespace DTools


// Macros for Logging
#if defined(DK_DEBUG)
// Core Logger Macros
#define DK_CORE_TRACE(...)				DTools::s_CoreLogger->Trace(__VA_ARGS__)
#define DK_CORE_INFO(...)					DTools::s_CoreLogger->Info(__VA_ARGS__)
#define DK_CORE_WARN(...)					DTools::s_CoreLogger->Warn(__VA_ARGS__)
#define DK_CORE_ERROR(...)				DTools::s_CoreLogger->Error(__VA_ARGS__)
#define DK_CORE_CRITICAL(...)			DTools::s_CoreLogger->Critical(__VA_ARGS__)

// Client Logger Macros
#define DK_TRACE(...)			DTools::s_ClientLogger->Trace(__VA_ARGS__)
#define DK_INFO(...)				DTools::s_ClientLogger->Info(__VA_ARGS__)
#define DK_WARN(...)				DTools::s_ClientLogger->Warn(__VA_ARGS__)
#define DK_ERROR(...)			DTools::s_ClientLogger->Error(__VA_ARGS__)
#define DK_CRITICAL(...)		DTools::s_ClientLogger->Critical(__VA_ARGS__)
#elif defined(DK_RELEASE)
// Core Logger Macros
#define DK_CORE_TRACE(...)
#define DK_CORE_INFO(...)
#define DK_CORE_WARN(...)
#define DK_CORE_ERROR(...)
#define DK_CORE_CRITICAL(...)

// Client Logger Macros
#define DK_TRACE(...)			DTools::s_ClientLogger->Trace(__VA_ARGS__)
#define DK_INFO(...)				DTools::s_ClientLogger->Info(__VA_ARGS__)
#define DK_WARN(...)				DTools::s_ClientLogger->Warn(__VA_ARGS__)
#define DK_ERROR(...)			DTools::s_ClientLogger->Error(__VA_ARGS__)
#define DK_CRITICAL(...)		DTools::s_ClientLogger->Critical(__VA_ARGS__)
#else
// Core Logger Macros
#define DK_CORE_TRACE(...)
#define DK_CORE_INFO(...)
#define DK_CORE_WARN(...)
#define DK_CORE_ERROR(...)
#define DK_CORE_CRITICAL(...)

// Client Logger Macros
#define DK_TRACE(...)
#define DK_INFO(...)
#define DK_WARN(...)
#define DK_ERROR(...)
#define DK_CRITICAL(...)
#endif

// Assertion Macros
#if defined(DK_ENABLE_ASSERTS)
#define DK_CORE_ASSERT(x, ...)	if(!(x)) { DK_CORE_CRITICAL("Assertion Failed: %s", __VA_ARGS__); __debugbreak(); }
#define DK_ASSERT(x, ...)				if(!(x)) { DK_CRITICAL("Assertion Failed: %s", __VA_ARGS__); __debugbreak(); }
#else
#define DK_CORE_ASSERT(x, ...)
#define DK_ASSERT(x, ...)
#endif