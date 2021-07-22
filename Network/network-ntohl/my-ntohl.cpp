#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

uint32_t readfile(string filename) {
    FILE * f1;
    unsigned int value = 0;
    f1 = fopen(filename.c_str(), "rb");
    fread(&value, 1, 4, f1);
    fclose(f1);
    return value;
}

uint32_t my_ntohl(uint32_t value) {
    u_char* array = (u_char*)&value;
    uint32_t retval = (array[0] << 24 | array[1] << 16 | array[2] << 8 | array[3]);
    return retval;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "파라미터를 입력해주세요!!!" << endl;
        return 0;
    }
    
    uint32_t aa = my_ntohl(readfile(argv[1]));
    uint32_t bb = my_ntohl(readfile(argv[2]));

    cout << dec << aa << "(0x" << hex << aa << ") + "
        << dec << bb << "(0x" << hex << bb << ") = "
        << dec << (aa + bb) << "(0x" << hex << (aa + bb) << ")" << endl;
}