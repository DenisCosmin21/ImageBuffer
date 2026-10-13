#include <iostream>
#include <stack>
#include "ImageBuffer.h"

using namespace std;

stack<ImageBuffer> changes_stack;

ImageBuffer undo_change(const ImageBuffer &current_buffer) {
    if (changes_stack.empty()) {
        cout<<"Nu exista modificari facute inainte"<<endl;
        return current_buffer;
    }

    cout<<"Scoatem de pe stiva versiunea anterioara"<<endl;

    ImageBuffer old_buffer = changes_stack.top();
    changes_stack.pop();

    old_buffer.printInfo();

    return old_buffer;
}


void apply_change(ImageBuffer &buffer, const size_t x, const size_t y, const unsigned char elem) {
    changes_stack.push(buffer);
    cout<<"Aplicam modificari"<<endl;
    buffer.changePixel(x, y, elem);
    cout<<"Modificare aplicata"<<endl;
    buffer.printInfo();
}

int main() {
    cout << "=== 1. Initializare ==="<<endl;
    ImageBuffer myImage(5, 5);

    cout << "=== 2. Modificare si Salvare in Stack ==="<<endl;

    apply_change(myImage, 2, 2, 255);

    cout<<"Imaginea de dupa modificare"<<endl;

    myImage.printInfo();

    cout << "\n=== 3. Aplicare Undo ===\n";

    ImageBuffer old_image = undo_change(myImage);

    cout<<"Imaginea de dinainte de modificari"<<endl;
    old_image.printInfo();

    cout << "=== 4. Sfarsit program (Curatare Memorie) ==="<<endl;
    return 0;
}