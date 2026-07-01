#pragma once

#include "arp/framebuffer.h"
#include "arp/math.h"


class IShaderProgram {
    virtual Vec3 Vertex(Vec3 vertice) = 0;
    virtual Color Fragment(Vec2 screenCoords, Vec3 clipCoords) = 0;

    virtual ~IShaderProgram() = default;
}
