#pragma once

#include <iostream>
#include <vector>
#include <limits>

struct Color {
  unsigned char red;
  unsigned char green;
  unsigned char blue;

  float luminance() const {
    return 0.2126f * red + 0.7152f * green + 0.0722f * blue;
  }
};

class IFramebuffer {
public:
  virtual std::pair<int, int> GetDimensions() const = 0;
  virtual void PutPixel(int x, int y, float z, Color color) = 0;
  virtual void Display() = 0;
  virtual void Clear() = 0;

  virtual ~IFramebuffer() = default;
};

class ConsoleFramebuffer : public IFramebuffer {
public:
  ConsoleFramebuffer(int width, int height) {
    this->width_ = width;
    this->height_ = height;

    this->z_buffer_.resize(width * height);
    this->buffer_.resize(width * height);

    Clear();
  }

  std::pair<int, int> GetDimensions() const {
    return std::pair{width_, height_};
  }

  void PutPixel(int x, int y, float z, Color color) {
    int a{y * width_ + x};
    if (z < z_buffer_[a]) {
      buffer_[a] = color;
      z_buffer_[a] = z;
    }
  }

  void Clear() {
    this->z_buffer_.assign(width_ * height_, std::numeric_limits<float>::max());
    this->buffer_.assign(width_ * height_, {});
  }

  void Display() {
    std::string frame;
    frame.reserve(width_ * height_ + height_);
    int len{static_cast<int>(kColors.length())};

    for (int j = 0; j < height_; j++) {
      for (int i = 0; i < width_; i++) {
        int idx(kColors.length() / 255.0f *
                buffer_[j * width_ + i].luminance());
        if (idx >= len)
          idx = len - 1;
        frame += kColors[idx];
      }
      if (j != height_ - 1) {
        frame += '\n';
      }
    }
    std::cout << "\x1b[H" << frame << std::flush;
  }

private:
  std::vector<float> z_buffer_;
  std::vector<Color> buffer_;

  int width_;
  int height_;

  const std::string kColors{" .:-=+*#%@"};
};
