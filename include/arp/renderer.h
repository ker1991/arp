#pragma once

#include "arp/matrices.h"
#include "arp/framebuffer.h"
#include "arp/math.h"

class Renderer {
public:
  Camera camera;

  Renderer(IFramebuffer &fb) : fb_(fb) {}
  void drawTriangle(Vec3 v1, Vec3 v2, Vec3 v3);

private:
  IFramebuffer &fb_;
  
};
