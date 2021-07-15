#include <cstdio>
#include <cstdint>

int main(int argc, char* argv[]) {
    if (argc == 2) {
        if(FILE* inputFile = fopen(argv[1], "r")){
            char src[512]{},ch{};
            for(uint16_t i{}; (ch = getc(inputFile)) != EOF; ++i){ src[i] = ch; }
            fclose(inputFile);
            for (uint16_t i{},p{},mem[256]{}; src[i] != 0; ++i) {
                if(src[i] == '>'){ ++p; }
                else if(src[i] == '<') { --p; }
                else if(src[i] == '+') { ++mem[p]; }
                else if(src[i] == '-') { --mem[p]; }
                else if(src[i] == '.') { putchar(mem[p]); }
                else if(src[i] == ',') { mem[p] = getchar(); }
                else if(src[i] == '[' && mem[p] == 0){
                    for(uint8_t b{};src[++i];) {
                        if(src[i] == '[') ++b;
                        else if(src[i] == ']' && b-- == 0) break;
                    }
                }
                else if(src[i] == ']' && mem[p] != 0){
                    for(uint8_t b{};src[--i];) {
                        if(src[i] == ']') ++b;
                        else if(src[i] == '[' && b-- == 0) break;
                    }
                }
            }
        }
    }
    return 0;
}
