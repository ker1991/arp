#pragma once

inline constexpr float kPi = 3.141592653589793f;

struct Vec2 {
  float x{}, y{};

  Vec2() = default;

  Vec2(float x, float y) {
    this->x = x;
    this->y = y;
  }
};

struct Vec3 {
  float x{}, y{}, z{};

  Vec3() = default;

  Vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  Vec3(Vec2 v, float z) : Vec3(v.x, v.y, z) {}
};

struct Vec4 {
  float x{}, y{}, z{}, w{};

  Vec4() = default;

  Vec4(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
  }

  Vec4(Vec3 v, float w) : Vec4(v.x, v.y, v.z, w) {}
};

struct Mat3 {
  float M11, M12, M13;
  float M21, M22, M23;
  float M31, M32, M33;

  Mat3(float m11, float m12, float m13, float m21, float m22, float m23,
       float m31, float m32, float m33) {
    M11 = m11;
    M12 = m12;
    M13 = m13;

    M21 = m21;
    M22 = m22;
    M23 = m23;

    M31 = m31;
    M32 = m32;
    M33 = m33;
  }

  Mat3 operator+(const Mat3 &other) const {
    return Mat3{M11 + other.M11, M12 + other.M12, M13 + other.M13,
                M21 + other.M21, M22 + other.M22, M23 + other.M23,
                M31 + other.M31, M32 + other.M32, M33 + other.M33};
  }

  Mat3 operator*(const Mat3 &other) const {
    return Mat3{
        M11 * other.M11 + M12 * other.M21 + M13 * other.M31,
        M11 * other.M12 + M12 * other.M22 + M13 * other.M32,
        M11 * other.M13 + M12 * other.M23 + M13 * other.M33,

        M21 * other.M11 + M22 * other.M21 + M23 * other.M31,
        M21 * other.M12 + M22 * other.M22 + M23 * other.M32,
        M21 * other.M13 + M22 * other.M23 + M23 * other.M33,

        M31 * other.M11 + M32 * other.M21 + M33 * other.M31,
        M31 * other.M12 + M32 * other.M22 + M33 * other.M32,
        M31 * other.M13 + M32 * other.M23 + M33 * other.M33,
    };
  }

  Vec3 operator*(const Vec3 &v) {
    return Vec3{M11 * v.x + M12 * v.y + M13 * v.z,
                M21 * v.x + M22 * v.y + M23 * v.z,
                M31 * v.z + M32 * v.y + M33 * v.z};
  }
};

struct Mat4 {
  float M11, M12, M13, M14;
  float M21, M22, M23, M24;
  float M31, M32, M33, M34;
  float M41, M42, M43, M44;

  Mat4(float m11, float m12, float m13, float m14, float m21, float m22,
       float m23, float m24, float m31, float m32, float m33, float m34,
       float m41, float m42, float m43, float m44) {
    M11 = m11;
    M12 = m12;
    M13 = m13;
    M14 = m14;

    M21 = m21;
    M22 = m22;
    M23 = m23;
    M24 = m24;

    M31 = m31;
    M32 = m32;
    M33 = m33;
    M34 = m34;

    M41 = m41;
    M42 = m42;
    M43 = m43;
    M44 = m44;
  }

  Mat4 operator+(const Mat4 &other) const {
    return Mat4{
        M11 + other.M11, M12 + other.M12, M13 + other.M13, M14 + other.M14,
        M21 + other.M21, M22 + other.M22, M23 + other.M23, M24 + other.M24,
        M31 + other.M31, M32 + other.M32, M33 + other.M33, M34 + other.M34,
        M41 + other.M41, M42 + other.M42, M43 + other.M43, M44 + other.M44};
  }

  Mat4 operator*(const Mat4 &other) const {
    return Mat4{
        M11 * other.M11 + M12 * other.M21 + M13 * other.M31 + M14 * other.M41,
        M11 * other.M12 + M12 * other.M22 + M13 * other.M32 + M14 * other.M42,
        M11 * other.M13 + M12 * other.M23 + M13 * other.M33 + M14 * other.M43,
        M11 * other.M14 + M12 * other.M24 + M13 * other.M34 + M14 * other.M44,

        M21 * other.M11 + M22 * other.M21 + M23 * other.M31 + M24 * other.M41,
        M21 * other.M12 + M22 * other.M22 + M23 * other.M32 + M24 * other.M42,
        M21 * other.M13 + M22 * other.M23 + M23 * other.M33 + M24 * other.M43,
        M21 * other.M14 + M22 * other.M24 + M23 * other.M34 + M24 * other.M44,

        M31 * other.M11 + M32 * other.M21 + M33 * other.M31 + M34 * other.M41,
        M31 * other.M12 + M32 * other.M22 + M33 * other.M32 + M34 * other.M42,
        M31 * other.M13 + M32 * other.M23 + M33 * other.M33 + M34 * other.M43,
        M31 * other.M14 + M32 * other.M24 + M33 * other.M34 + M34 * other.M44,

        M41 * other.M11 + M42 * other.M21 + M43 * other.M31 + M44 * other.M41,
        M41 * other.M12 + M42 * other.M22 + M43 * other.M32 + M44 * other.M42,
        M41 * other.M13 + M42 * other.M23 + M43 * other.M33 + M44 * other.M43,
        M41 * other.M14 + M42 * other.M24 + M43 * other.M34 + M44 * other.M44};
  }

  Vec4 operator*(const Vec4 &v) {
    return Vec4{M11 * v.x + M12 * v.y + M13 * v.z + M14 * v.w,
                M21 * v.x + M22 * v.y + M23 * v.z + M24 * v.w,
                M31 * v.x + M32 * v.y + M33 * v.z + M34 * v.w,
                M41 * v.x + M42 * v.y + M43 * v.z + M44 * v.w};
  }
};
