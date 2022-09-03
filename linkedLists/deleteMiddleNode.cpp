#include <iostream>
#include "nodeHeader.hpp"

bool removeMiddleElem(node*);


int main() {
    node* head = new node(13);
    head->push_back(20);
    head->push_back(10);
    head->push_back(5);
    head->push_back(8);
    head->push_back(7);
    head->push_back(12);

    std::cout << removeMiddleElem(head);


    while(head != nullptr) {
        auto tmp = head;
        head = head->next;
        delete tmp;
    }


    return 0;
}

bool removeMiddleElem(node* head) {
    if(!head || !head->next) return false;
    auto tmp = head->next;
    head->value = head->next->value;
    head->next = head->next->next;
    delete tmp;
    tmp = nullptr;
    return true;
};
