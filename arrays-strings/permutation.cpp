#include <iostream>
#include <unordered_map>

bool permutation(std::string s, std::string t) {
    if (s.size() != t.size()) {
        return false;
    }
    std::unordered_map <char, int> letters;
    for (const auto& c : s) {
        letters[c]++;
    }
    for (const auto& c : t) {
        if(letters[c] < 0) return false;
        letters[c]--;
    } 
    return true;
}

int main() {
    std::string str1 = "hello";
    std::string str2 = "olleh";
    std::cout << permutation(str1, str2);
    
    return 0;
}
