#include <sys/ioctl.h>
#include <unistd.h>

#include "arp/framebuffer.h"

int main() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  ConsoleFramebuffer fb{w.ws_col, w.ws_row - 1};
  std::cout << "\x1b[?25l" << std::flush;
  
  while(true) {
    //fb.Clear();
    fb.PutPixel(3, 3, 1, {0xff, 0xff, 0xff});
    fb.Display();
  }

  return 0;
}
