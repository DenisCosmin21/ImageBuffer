#ifndef IMAGEBUFFER_H
#define IMAGEBUFFER_H

#include <iostream>
#include <cstddef>

class ImageBuffer {
private:
    unsigned char** pixels;
    size_t width;
    size_t height;

public:
    ImageBuffer(size_t w, size_t h);

    ~ImageBuffer();

    ImageBuffer(const ImageBuffer& other);

    ImageBuffer(ImageBuffer&& other) noexcept;

    void changePixel(size_t x, size_t y, unsigned char new_value);

    void printInfo() const;
};
#endif //IMAGEBUFFER_H
