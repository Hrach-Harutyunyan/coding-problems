#include <iostream>
#include <stack>
#include "nodeHeader.hpp"

bool isPalindrome(node*);

int main() {

    node* head = new node(12);
    head->push_back(7);
    head->push_back(8);
    head->push_back(5);
    head->push_back(8);
    head->push_back(7);
    head->push_back(12);

    std::cout << isPalindrome(head);

    while(head != nullptr) {
        auto tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}

bool isPalindrome(node* head) {
    if(!head || !head->next) return true;
    std::stack<int> st{};
    auto slow = head;
    auto fast = head;
    while(fast && fast->next) {
        st.push(slow->value);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast != nullptr) {
        slow = slow->next;
    }
    while(slow) {
        auto tmp = st.top();
        st.pop();
        if(tmp != slow->value) return false;
        slow = slow->next;
    }

    return true;
};
