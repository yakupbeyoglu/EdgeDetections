#ifndef SOBEL_H_
#define SOBEL_H_
#include "Base.h"
#include <Gorgon/ImageProcessing/Kernel.h>
#include <Gorgon/ImageProcessing/Filters.h>
#include "Process.hpp"

namespace EdgeDetections {
class Sobel:public Base {
public:
    virtual Gorgon::Graphics::Bitmap Detect(const Gorgon::Graphics::Bitmap &bmp)override {
        auto kernelx = Gorgon::ImageProcessing::Kernel::SobelFilter(Gorgon::Axis::X);
        auto kernely = Gorgon::ImageProcessing::Kernel::SobelFilter(Gorgon::Axis::Y);

        auto filteredx = ConvolutionFilter(bmp, kernelx, true);
        auto filteredy = ConvolutionFilter(bmp, kernely, true);
        
        filteredx.ExportPNG("X.png");
        filteredy.ExportPNG("Y.png");
        auto gradient = GradientMagniute(filteredx, filteredy);
        return gradient;
    }
private:
    Gorgon::Graphics::Bitmap GradientMagniute(const Gorgon::Graphics::Bitmap &bmp1, const Gorgon::Graphics::Bitmap &bmp2) {
        Gorgon::Graphics::Bitmap output = bmp1.Duplicate();
        int numberofchannel = bmp1.GetChannelsPerPixel();
        for (int j = 0; j < bmp1.GetHeight(); j++)
        {
            for (int i = 0; i < bmp1.GetWidth(); i++) {
                for (int nc = 0; nc < numberofchannel; nc++) {
                    float value = std::sqrt(std::pow(bmp1(i, j, nc), 2) + std::pow(bmp2(i, j, nc), 2));
                    if (value > 255)
                        value = 255;
                    else if (value < 0)
                        value = 0;
                    output(i, j, nc) = value;
                }
            }

        }
        return output;
    }
};

}
#endif
