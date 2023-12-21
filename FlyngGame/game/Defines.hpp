//
// Created by gaetz on 24/04/2023.
//

#ifndef ENGINEIMPL_DEFINES_HPP
#define ENGINEIMPL_DEFINES_HPP

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

// Types
using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
using i8 = signed char;
using i16 = signed short;
using i32 = signed int;
using i64 = signed long long;
using f32 = float;
using f64 = double;

#include <string>

using str = std::string;

// Platform specific
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_MSC_VER)
#define GPLATFORM_WINDOWS 1
#elif defined(__GNUC__)

#define GPLATFORM_LINUX 1
#endif

#if defined(GPLATFORM_WINDOWS)

// Microsoft
#define GAPI __declspec(dllexport)
#define GIMPORT __declspec(dllimport)
#elif defined(GPLATFORM_LINUX)
// GCC
#define GAPI __attribute__((visibility("default")))
#define GIMPORT
#else
// Do nothing and hope for the best?
#define GAPI
#define GIMPORT
#pragma warning Unknown dynamic link import/export semantics.
#endif

#endif //ENGINEIMPL_DEFINES_HPP