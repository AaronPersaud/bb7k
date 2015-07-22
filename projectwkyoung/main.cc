#include "controller.h"
#include "textdisplay.h"
#include "view.h"
#include <iostream> //remove after testing
#include <cstdlib>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
  Controller c;
  if(argc >= 2) {
    if(strcmp(argv[1], "-load")==0){
      if (argc == 2) {
        cout << "No file specified. Please try again." << endl;
      }
      else{
        cout << "File loading..." << endl;
        c.load(argv[2]);
      }
    }
    else if(strcmp(argv[1], "-testing")==0) {
      cout << "Testing has been turned on." << endl; //TODO
    }
    else{
      cout << "Invalid command. Please try again." << endl;
    }
  }
  else{
    c.noParameter();
  }
}
