#include <iostream>

bool oneEditReplace(std::string, std::string);
bool oneEditinsert(std::string, std::string);
bool oneEditAway(std::string, std::string);

int main() {
    std::string s1 = "pale";
    std::string s2 = "pale";
    std::cout << oneEditAway(s1, s2);

    return 0;
}


bool oneEditReplace(std::string s1, std::string s2) { 
    bool found = false;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] = ! s2[i]) {
            if (found) { 
                return false;
            }
            found = true;
        }
    }
    return true;
}

bool oneEditinsert(std::string s1, std::string s2) {
    int index1 = 0;
    int index2 = 0;
    while (index2 < s2.size() && index1 < s1.size()) {
        if (s1[index1] != s2[index2]) {
            if (index1 != index2) {
                return false;
            }
            index2++;
            } else {
                index1++;
                index2++;
            }
        }
    return true;
}

bool oneEditAway(std::string first, std::string second) {
    if (first.size()== second.size()) {
        return oneEditReplace(first, second);
    } else if (first.size() + 1 == second.size()) {
        return oneEditinsert(first, second);
    } else if (first.size() - 1 == second.size()) {
        return oneEditinsert(second, first);
    }
    return false;
}