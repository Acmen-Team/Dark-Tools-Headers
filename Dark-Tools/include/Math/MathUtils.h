#pragma once

#include <initializer_list>
#include <cmath>

namespace DTools {

  // Mathematical constants
  constexpr float PI = 3.14159265359f;
  constexpr float DEG2RAD = PI / 180.0f;
  constexpr float RAD2DEG = 180.0f / PI;
  constexpr float EPSILON = 1e-6f;

  // Utility functions
  inline float Radians(float degrees) { return degrees * DEG2RAD; }
  inline float Degrees(float radians) { return radians * RAD2DEG; }
  inline float Clamp(float value, float min, float max) { return (value < min) ? min : (value > max) ? max : value; }
  inline float Lerp(float a, float b, float t) { return a + t * (b - a); }

}