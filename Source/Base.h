#ifndef BASE_H_
#define BASE_H_
#include <Gorgon/Graphics/Bitmap.h>
namespace EdgeDetections {
class Base {
public:
    virtual Gorgon::Graphics::Bitmap Detect(const Gorgon::Graphics::Bitmap &bmp) = 0;
};
}
#endif
