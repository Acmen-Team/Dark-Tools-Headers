#pragma once

#include "MathUtils.h"

namespace DTools {

  // Fixed-size vector class
  template<size_t N, typename T>
  class Vector
  {
  public:
    T data[N] = {};

    Vector() = default;

    explicit Vector(T scalar)
    {
      for (size_t i = 0; i < N; ++i)
        data[i] = scalar;
    }

    Vector(std::initializer_list<T> list)
    {
      size_t i = 0;
      for (T value : list)
      {
        if (i < N)
          data[i++] = value;
      }
    }

    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

    Vector operator+(const Vector& other) const
    {
      Vector result;
      for (size_t i = 0; i < N; ++i)
        result.data[i] = data[i] + other.data[i];
      return result;
    }

    Vector operator-(const Vector& other) const
    {
      Vector result;
      for (size_t i = 0; i < N; ++i)
        result.data[i] = data[i] - other.data[i];
      return result;
    }

    Vector operator*(T scalar) const
    {
      Vector result;
      for (size_t i = 0; i < N; ++i)
        result.data[i] = data[i] * scalar;
      return result;
    }

    Vector operator/(T scalar) const
    {
      Vector result;
      for (size_t i = 0; i < N; ++i)
        result.data[i] = data[i] / scalar;
      return result;
    }

    T Dot(const Vector& other) const
    {
      T result = T();
      for (size_t i = 0; i < N; ++i)
        result += data[i] * other.data[i];
      return result;
    }

    T Length() const
    {
      return std::sqrt(Dot(*this));
    }

    Vector Normalize() const
    {
      T len = Length();
      if (len < EPSILON) return *this; // Avoid division by zero

      return *this * (1.0f / len);
    }

  };

  template<typename T>
  class Vector<2, T>
  {
  public:
    union
    {
      struct { T x, y; };
      T data[2];
    };

    Vector() : x(0), y(0) {}

    explicit Vector(T scalar) : x(scalar), y(scalar) {}

    Vector(T x, T y) : x(x), y(y) {}

    Vector(std::initializer_list<T> list)
    {
      auto it = list.begin();
      x = (list.size() > 0) ? *it++ : T(0);
      y = (list.size() > 1) ? *it : T(0);
    }

    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

    Vector<2, T> operator+(const Vector<2, T>& other) const
    {
      return Vector<2, T>(x + other.x, y + other.y);
    }

    Vector<2, T> operator-(const Vector<2, T>& other) const
    {
      return Vector<2, T>(x - other.x, y - other.y);
    }

    Vector<2, T> operator*(T scalar) const
    {
      return Vector<2, T>(x * scalar, y * scalar);
    }

    Vector<2, T> operator/(T scalar) const
    {
      if (std::abs(scalar) < EPSILON) return *this; // Avoid division by zero
      return Vector<2, T>(x / scalar, y / scalar);
    }

    T Dot(const Vector<2, T>& other) const
    {
      return x * other.x + y * other.y;
    }

    T Length() const
    {
      return std::sqrt(Dot(*this));
    }

    Vector<2, T> Normalize() const
    {
      T len = Length();
      if (len < EPSILON) return *this; // Avoid division by zero

      return *this / (1.0f / len);
    }

  };

  template<typename T>
  class Vector<3, T>
  {
  public:
    union
    {
      struct { T x, y, z; }; // Commonly used for 3D coordinates
      struct { T r, g, b; }; // Commonly used for color representation
      T data[3];
    };

    Vector() : x(0), y(0), z(0) {}

    explicit Vector(T scalar) : x(scalar), y(scalar), z(scalar) {}

    Vector(T x, T y, T z) : x(x), y(y), z(z) {}

    Vector(std::initializer_list<T> list)
    {
      auto it = list.begin();
      x = (list.size() > 0) ? *it++ : T(0);
      y = (list.size() > 1) ? *it++ : T(0);
      z = (list.size() > 2) ? *it : T(0);
    }

    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

    Vector<3, T> operator+(const Vector<3, T>& other) const
    {
      return Vector<3, T>(x + other.x, y + other.y, z + other.z);
    }

    Vector<3, T> operator-(const Vector<3, T>& other) const
    {
      return Vector<3, T>(x - other.x, y - other.y, z - other.z);
    }

    Vector<3, T> operator*(T scalar) const
    {
      return Vector<3, T>(x * scalar, y * scalar, z * scalar);
    }

    Vector<3, T> operator/(T scalar) const
    {
      if (std::abs(scalar) < EPSILON) return *this; // Avoid division by zero
      return Vector<3, T>(x / scalar, y / scalar, z / scalar);
    }

    T Dot(const Vector<3, T>& other) const
    {
      return x * other.x + y * other.y + z * other.z;
    }

    T Length() const
    {
      return std::sqrt(Dot(*this));
    }

    Vector<3, T> Normalize() const
    {
      T len = Length();
      if (len < EPSILON) return *this; // Avoid division by zero

      return *this / (1.0f / len);
    }
  };

  template<typename T>
  class Vector<4, T>
  {
  public:
    union
    {
      struct { T x, y, z, w; }; // Commonly used for 4D coordinates or homogeneous coordinates
      struct { T r, g, b, a; }; // Commonly used for color representation
      T data[4];
    };

    Vector() : x(0), y(0), z(0), w(0) {}

    explicit Vector(T scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}

    Vector(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

    Vector(std::initializer_list<T> list)
    {
      auto it = list.begin();
      x = (list.size() > 0) ? *it++ : T(0);
      y = (list.size() > 1) ? *it++ : T(0);
      z = (list.size() > 2) ? *it++ : T(0);
      w = (list.size() > 3) ? *it : T(0);
    }

    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

    Vector<4, T> operator+(const Vector<4, T>& other) const
    {
      return Vector<4, T>(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    Vector<4, T> operator-(const Vector<4, T>& other) const
    {
      return Vector<4, T>(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    Vector<4, T> operator*(T scalar) const
    {
      return Vector<4, T>(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    Vector<4, T> operator/(T scalar) const
    {
      if (std::abs(scalar) < EPSILON) return *this; // Avoid division by zero
      return Vector<4, T>(x / scalar, y / scalar, z / scalar, w / scalar);
    }

    T Dot(const Vector<4, T>& other) const
    {
      return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    T Length() const
    {
      return std::sqrt(Dot(*this));
    }
  };

  // Type names for convenience
  using Vec2 = Vector<2, float>;
  using Vec3 = Vector<3, float>;
  using Vec4 = Vector<4, float>;

  inline Vec3 Cross(const Vec3& a, const Vec3& b)
  {
    return Vec3(
      a[1] * b[2] - a[2] * b[1],
      a[2] * b[0] - a[0] * b[2],
      a[0] * b[1] - a[1] * b[0]
    );
  }

}