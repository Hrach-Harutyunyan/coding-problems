#include <iostream>

bool isUniqueChars(const std::string& str) {
    long cache = 0;
    for (int i = 0; i < str.size(); i++) {
        long index = str[i] - 65;
        if (cache & (1 << index)) {
            return false;
        }
        cache |= (1 << index);
    }
    return true;
}

int main() {

    std::cout << isUniqueChars("helo") << std::endl;
    std::cout << isUniqueChars("hello") << std::endl;

    return 0;
}
