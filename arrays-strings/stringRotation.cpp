#include <iostream>

bool stringRotate(std::string, std::string);

int main() {

    std::string s1 = "waterbottle";
    std::string s2 = "erbottlewat";
    std::cout << stringRotate(s1, s2);

    return 0;
}

bool stringRotate(std::string s1, std::string s2) {
    if(s1.size() == s2.size()) {
        for(int i{}; i < s2.size(); i++) {
            if(s1[i] == s2[0]) {
                return s2 == s1.substr(i,s2.size());
            } else {
                s1.push_back(s1[i]);
            }
        }
    }
    return false;
}