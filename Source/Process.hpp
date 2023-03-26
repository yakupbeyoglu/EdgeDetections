#ifndef PROCESS_HPP_
#define PROCESS_HPP_
#include "Base.h"
#include <Gorgon/ImageProcessing/Kernel.h>

namespace EdgeDetections
{
    
Gorgon::Graphics::Bitmap ConvolutionFilter(const Gorgon::Graphics::Bitmap &bmp,const Gorgon::ImageProcessing::Kernel &kernel,bool is_edge_detection=false){
    //number of channel check how many channel do we have
    int numberofchannel = bmp.GetChannelsPerPixel();
    // alpha index check if we have alpha ;
    //if we have and our kernel for edge detection  alpha channel will take only 255 or except.
    int alphaindex = bmp.HasAlpha() ? bmp.GetAlphaIndex() : -1;
    Gorgon::Graphics::Bitmap bmpnew = bmp.Duplicate();
    float kerneltotal = kernel.GetTotal();
    Gorgon::Geometry::Point max = { bmp.GetWidth() - 1,bmp.GetHeight() - 1 };
    Gorgon::Geometry::Point min = { 0,0 };
    for (int j = 0; j < bmp.GetHeight(); j++) {
        for (int i = 0; i < bmp.GetWidth(); i++) {
            std::vector<float> sum(numberofchannel,0.0);
            for (int kj = -kernel.GetHeight() / 2; kj <= kernel.GetHeight()/2; kj++) {
                for (int ki = -kernel.GetWidth() / 2; ki <= kernel.GetWidth() / 2; ki++) {
                    for (unsigned int nc = 0; nc < numberofchannel; nc++) {
                    
                            Gorgon::Geometry::Point current = { i - ki,j - kj };
                            if (current.X > max.X)
                                current.X = max.X;
                            else if (current.X < min.X)
                                current.X = min.X;
                            if (current.Y > max.Y)
                                current.Y = max.Y;
                            else if (current.Y < min.Y)
                                current.Y = min.Y;
                            double kvalue = kernel.Get(ki + kernel.GetWidth() / 2, kj + kernel.GetHeight() / 2);
                            //sum += bmp.Get(current)*kvalue;
                            sum[nc] += bmp.Get(current, nc)*kvalue;
                    }
                }
            }
            for (int nc = 0; nc < numberofchannel; nc++) {
                if (nc == alphaindex && is_edge_detection)
                    bmpnew(i, j, nc) = 255;
                else {

                    if (sum[nc] < 0)
                        sum[nc] = is_edge_detection?std::abs(sum[nc]):0;
                    else if (sum[nc] > 255)
                        sum[nc] = 255;
                    bmpnew(i, j,nc) = sum[nc];
                }
            }
        }

    }
    return bmpnew;

}

}
#endif
