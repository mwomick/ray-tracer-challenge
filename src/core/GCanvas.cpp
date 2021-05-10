#include "include/core/GCanvas.h"

#include <iostream>
#include <fstream>

using namespace std;

bool GCanvas::writeToFile(const char path[]) {
  ofstream file(path);
  if(file.is_open()) {
    file << "P3\n" << this->fWidth << " " << this->fHeight << "\n255\n";
    for(int y = 0; y < this->fHeight; y++) {
        for(int x = 0; x < this-> fWidth; x++) {
            if(x % 23 == 22) { file << "\n"; }
            GTuple* color = this->getAddr(x, y);
            file << color->fX*255 << " " << color->fY*255 << " " << color->fZ*255 << " ";
        }
        file << "\n";
    }
    file.close();
    return true;
  }
  else {
    cout << "Unable to open file";
    return false;
  }
}

void GCanvas::blit(int x, int y, GTuple& color) {
  *(this->getAddr(x, y)) = color;
}

void GCanvas::blitRow(int x, int y, int size, GTuple& color) {
  GTuple * ptr = this->getAddr(x, y);
  for(int i = 0; i < size; i++) {
    memcpy(ptr, &color, sizeof(GTuple));
    ptr++;
  }
}