#include "controller.h"
#include "textdisplay.h"
#include "view.h"

#include <iostream> //remove after testing

int main(int argc, char *argv[]) {
  std::cout << "Args: " << argc << std::endl;
  Controller c;
  c.play();
}
