#pragma once

#include <vector>

struct MeshData {
  std::vector<float> vertices;
};

struct Mesh {
  MeshData meshData;
};
