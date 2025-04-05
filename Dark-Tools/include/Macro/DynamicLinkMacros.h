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

Date: 2024/10/15
Description:
This header file defines macros for managing dynamic linking on the Windows platform. It includes:
- A macro to prevent multiple inclusions of this header file.
- Conditional definitions for the `DARK_API` macro, which handles the import and export of symbols when building or using a DLL.
- A compile-time error if the code is not being compiled on a Windows platform.
**************************************************/

#pragma once

#ifdef DK_PLATFORM_WINDOWS
#if DK_DYNAMIC_LINK
#ifdef DK_BUILD_DLL
#define DARK_API _declspec(dllexport)
#else
#define DARK_API _declspec(dllimport)
#endif
#else
#define DARK_API
#endif
#else
#error Dark Currently Supports Windows Only!
#endif
