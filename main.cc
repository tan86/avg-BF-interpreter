#include <cstdio>
#include <iostream>
#include <string>
#include <string_view>

void interpret(const std::string_view src) {
    char mem[256]{};
    std::uint8_t p = 0;
    for (std::uint8_t i = 0; src[i] != 0; ++i) {
        switch (src[i]) {
            case '>': ++p; break;
            case '<': --p; break;
            case '+': ++mem[p]; break;
            case '-': --mem[p]; break;
            case '.': std::cout << mem[p]; break;
            case ',': std::cin >> mem[p]; break;
            case '[':
                if (mem[p] == 0) {
                    std::uint8_t open = 0;
                    while (src[++i]) {
                        if (src[i] == ']' && open == 0) break;
                        else if (src[i] == '[') ++open;
                        else if (src[i] == ']') --open;
                    }
                }
                break;
            case ']':
                if (mem[p] != 0) {
                    std::uint8_t close = 0;
                    while (src[--i] != 0) {
                        if (src[i] == '[' && close == 0) break;
                        else if (src[i] == ']') ++close;
                        else if (src[i] == '[') --close;
                    }
                }
                break;
            default: break;
        }
    }
}

int main(int argc, char* argv[]) {
    std::string inputStr{};

    if (argc != 2) {
        std::cout << "Brain Fuck Interpreter v1.0\n";
        for (;;) {
            std::cout << "> ";
            std::getline(std::cin, inputStr);

            if (inputStr == "exit") break;
            if(!inputStr.empty()) interpret(inputStr);
        }
    } else {
        FILE* inputFile = nullptr;
        inputFile = fopen(argv[1], "r");

        if (inputFile) {
            char ch{};
            while ((ch = getc(inputFile)) != EOF) { inputStr += ch; }
            
            fclose(inputFile);
            
            if(!inputStr.empty()) interpret(inputStr);
        }
    }

    return 0;
}
