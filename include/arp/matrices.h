#pragma once

#include <cmath>

#include "arp/math.h"

struct Transform {
  float x{}, y{}, z{};
  float pitch{}, roll{}, yaw{};
  float scale{1.0f};

  Mat4 Matrix() const {
    float pr = pitch * kPi / 180.0f;
    float rr = roll * kPi / 180.0f;
    float yr = yaw * kPi / 180.0f;

    float cp = cosf(pr), sp = sinf(pr);
    float cr = cosf(rr), sr = sinf(rr);
    float cy = cosf(yr), sy = sinf(yr);

    float m00 = cy * cp;
    float m10 = sy * cp;
    float m20 = -sp;
    float m30 = 0.0f;

    float m01 = cy * sp * sr - sy * cr;
    float m11 = sy * sp * sr + cy * cr;
    float m21 = cp * sr;
    float m31 = 0.0f;

    float m02 = cy * sp * cr + sy * sr;
    float m12 = sy * sp * cr - cy * sr;
    float m22 = cp * cr;
    float m32 = 0.0f;

    float m03 = x;
    float m13 = y;
    float m23 = z;
    float m33 = 1.0f;

    return Mat4(m00 * scale, m10 * scale, m20 * scale, m30, m01 * scale,
                m11 * scale, m21 * scale, m31, m02 * scale, m12 * scale,
                m22 * scale, m32, m03, m13, m23, m33);
  }
};

class Camera {
public:
  float x{}, y{}, z{};
  Vec3 dir, up, right;

  Mat4 Matrix() const {
    return Mat4{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
  }
};

class Projection {
public:
  float near{}, far{};
  float fov{};
  float aspect = 16.0f / 9.0f;

  Mat4 Matrix() const {
    float fovRad = fov * 3.14159265359f / 180.0f;
    float tanHalfFov = tan(fovRad / 2.0f);

    return Mat4{1.0f / (aspect * tanHalfFov),
                0.0f,
                0.0f,
                0.0f,
                0.0f,
                1.0f / tanHalfFov,
                0.0f,
                0.0f,
                0.0f,
                0.0f,
                -(far + near) / (far - near),
                -1.0f,
                0.0f,
                0.0f,
                -(2.0f * far * near) / (far - near),
                0.0f};
  }
};
