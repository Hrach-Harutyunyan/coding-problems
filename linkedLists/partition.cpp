#include <iostream>
#include <stack>
#include "nodeHeader.hpp"

node* partition(node*, int);

int main() {

    node* head = new node(3);
    head->push_back(5);
    head->push_back(8);
    head->push_back(5);
    head->push_back(10);
    head->push_back(2);
    head->push_back(1);

    auto el = partition(head, 5);


    while(el != nullptr) {
        std::cout << el->value << " ";
        el = el->next;
    }
    return 0;
}

node* partition(node* cur, int k) {
    auto head = cur;
    auto tail = cur;
    while(cur) {
        auto tmp = cur->next;
        if(cur->value < k) {
            cur->next = head;
            head = cur;
        }else {
            tail->next = cur;
            tail = cur;
        }
        cur = tmp;
    }
    tail->next = nullptr;
    return head;
};
