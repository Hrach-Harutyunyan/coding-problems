#include <iostream>
#include <unordered_map>

bool isPalindrome(const std::string& str) {
    std::unordered_map <char, int> cache{};
    int odd = 0;
    for(const auto& el : str) {
        if(isalnum(el)) {
            char tmp = std::tolower(el);
            cache[tmp]++;
            if(cache[tmp] & 1) odd++;
            else odd--;
        }
    }
    return odd <= 1;
}


int main() {
    std::string s = "Tact Coa";
    std::cout << isPalindrome(s) << std::endl;


    return 0;
}
