#include <iostream>

void replaceSpaces(std::string& str) {
    std::string res{};
    int size = str.size();
    for (int i = size - 1; i >= 0; i-- ) {
        if (str[i] == ' ') {
            res = '0' + res;
            res = '2' + res;
            res = '%' + res;
        } else {
            res = str[i] + res;
        }
    }
    str = res;
}

int main() {
    std::string str = "Mr John Smith   ";
    replaceSpaces(str);
    std::cout << str << std::endl;
}
