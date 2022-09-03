#include <iostream>


std::string compress(const std::string&);

int main() {

    std::string a = "aaabc";
    std::cout << compress(a);
}


std::string compress(const std::string& str) {
    if(str.size() <= 2) return str;
    std::string res{};
    int i = 1;
    int count = 1;
    char tmp = str[0];
    while(i < str.size()) {
        if(tmp != str[i]) {
            res += tmp + std::to_string(count);
            tmp = str[i];
            count = 1;
            i++;
            
        } else {
            count++; 
            i++;
        }
        if(i == str.size()) res += tmp + std::to_string(count);
    }
    return str.size() > res.size() ? res : str;
}

