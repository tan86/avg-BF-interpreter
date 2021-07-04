#include <iostream>
#include <string>

int main() {
    char mem[256]{};
    std::uint8_t p = 0;
    std::string inputStr{};

    std::cout << "Brain Fuck Interpreter v1.0\n";
    for (;;) {
        std::cout << "> ";
        std::getline(std::cin, inputStr);

        if (inputStr == "exit") {
            break;
        }

        for (std::uint8_t i = 0; i < inputStr.size(); ++i) {
            switch (inputStr[i]) {
                case '>': ++p; break;
                case '<': --p; break;
                case '+': ++mem[p]; break;
                case '-': --mem[p]; break;
                case '.': std::cout << mem[p]; break;
                case ',': std::cin >> mem[p]; break;
                case '[':
                    if (mem[p] == 0) {
                        int open = 0;
                        while (inputStr[++i]) {
                            if (inputStr[i] == ']' && open == 0) {
                                break;
                            } else if (inputStr[i] == '[') {
                                ++open;
                            } else if (inputStr[i] == ']') {
                                --open;
                            }
                        }
                    }
                    break;
                case ']':
                    if (mem[p] != 0) {
                        int close = 0;
                        while (inputStr[--i]) {
                            if (inputStr[i] == '[' && close == 0) {
                                break;
                            } else if (inputStr[i] == ']') {
                                ++close;
                            } else if (inputStr[i] == '[') {
                                --close;
                            }
                        }
                    }
                    break;
                default: break;
            }
        }
    }
    return 0;
}
