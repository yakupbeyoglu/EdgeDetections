#include <iostream>
#include <Gorgon/Graphics/Bitmap.h>
#include "Sobel.hpp"
int main() {
    
    Gorgon::Graphics::Bitmap bmp;
    bmp.Import("read.png");
    
    EdgeDetections::Sobel s;
    auto detected = s.Detect(bmp);
    detected.ExportPNG("Output.png");
    
    
}
