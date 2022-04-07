#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> msg {"Hello", "C++", "World", "from", "VS Code"};
    
    for(auto str: msg) {
        std::cout << str << " ";
    }

    std::cout << std::endl;

    return 0;
}