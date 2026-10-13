#include "ImageBuffer.h"

using namespace std;

ImageBuffer::ImageBuffer(const size_t w, const size_t h) : width(w), height(h)
{
    pixels = new unsigned char *[h];

    for (size_t i = 0;i < h;i++) {
        pixels[i] = new unsigned char[w];
    }

    cout<<"[Constructor] Am alocat matricea de pixeli de inaltime " << height << " si latime " << width<<endl;
}

ImageBuffer::~ImageBuffer(void) {
    for (size_t i = 0;i < height;i++) {
        delete[] pixels[i];
    }

    delete[] pixels;

    cout<<"[Destructor] Am eliberat memoria stergand liniile si coloanele matricii de pixeli"<<endl;
}

ImageBuffer::ImageBuffer(const ImageBuffer &other) : width(other.width), height(other.height) {
    pixels = new unsigned char *[other.height];

    for (int i = 0;i < other.height;i++) {
        pixels[i] = new unsigned char[other.width];
        for (int j = 0;j < other.width;j++) {
            pixels[i][j] = other.pixels[i][j];
        }
    }

    cout<<"[Copy constructor] Am copiat matricea de pixeli complet in noul obiect fara a copia doar adresa"<<endl;
}

ImageBuffer::ImageBuffer(ImageBuffer &&other) noexcept : pixels(other.pixels), width(other.width), height(other.height) {
    other.pixels = nullptr;
    other.width = 0;
    other.height = 0;

    cout<<"[Move constructor] Am transferat matricea de pixeli alaturi de dimensiuni altui obiect"<<endl;
}

void ImageBuffer::changePixel(const size_t x, const size_t y, const unsigned char new_value) {
    pixels[y][x] = new_value;
}

void ImageBuffer::printInfo() const {
    for (size_t i = 0;i < height;i++) {
        for (size_t j = 0;j < width;j++) {
            cout<<static_cast<unsigned short>(pixels[i][j])<<" ";
        }
        cout<<endl;
    }
}





