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

#include "ToolsAPI.h"
#include "Core/Core.h"

namespace DTools
{

	class DTOOLS_API Logger
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
		class DTOOLS_API LogImpl;
		Scope<LogImpl> m_LogImpl;

	};

  DTOOLS_API Ref<Logger> GetCoreLogger();
  DTOOLS_API Ref<Logger> GetClientLogger();

} // namespace DTools


// Macros for Logging
#if defined(DK_DEBUG)
// Core Logger Macros
#define DK_CORE_TRACE(...)					DTools::GetCoreLogger()->Trace(__VA_ARGS__)
#define DK_CORE_INFO(...)						DTools::GetCoreLogger()->Info(__VA_ARGS__)
#define DK_CORE_WARN(...)						DTools::GetCoreLogger()->Warn(__VA_ARGS__)
#define DK_CORE_ERROR(...)					DTools::GetCoreLogger()->Error(__VA_ARGS__)
#define DK_CORE_CRITICAL(...)				DTools::GetCoreLogger()->Critical(__VA_ARGS__)

// Client Logger Macros
#define DK_TRACE(...)								DTools::GetClientLogger()->Trace(__VA_ARGS__)
#define DK_INFO(...)								DTools::GetClientLogger()->Info(__VA_ARGS__)
#define DK_WARN(...)								DTools::GetClientLogger()->Warn(__VA_ARGS__)
#define DK_ERROR(...)								DTools::GetClientLogger()->Error(__VA_ARGS__)
#define DK_CRITICAL(...)						DTools::GetClientLogger()->Critical(__VA_ARGS__)
#elif defined(DK_RELEASE)
// Core Logger Macros
#define DK_CORE_TRACE(...)
#define DK_CORE_INFO(...)
#define DK_CORE_WARN(...)
#define DK_CORE_ERROR(...)
#define DK_CORE_CRITICAL(...)

// Client Logger Macros
#define DK_TRACE(...)								DTools::GetClientLogger()->Trace(__VA_ARGS__)
#define DK_INFO(...)								DTools::GetClientLogger()->Info(__VA_ARGS__)
#define DK_WARN(...)								DTools::GetClientLogger()->Warn(__VA_ARGS__)
#define DK_ERROR(...)								DTools::GetClientLogger()->Error(__VA_ARGS__)
#define DK_CRITICAL(...)						DTools::GetClientLogger()->Critical(__VA_ARGS__)
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
#define DK_CORE_ASSERT(x, ...)			if(!(x)) { DK_CORE_CRITICAL("Assertion Failed: %s", __VA_ARGS__); __debugbreak(); }
#define DK_ASSERT(x, ...)						if(!(x)) { DK_CRITICAL("Assertion Failed: %s", __VA_ARGS__); __debugbreak(); }
#else
#define DK_CORE_ASSERT(x, ...)
#define DK_ASSERT(x, ...)
#endif