#include <iostream>
#include "nodeHeader.hpp"

node* kth_node_to_last(node*, int);

int main() {
    node* head = new node(13);
    head->push_back(20);
    head->push_back(10);
    head->push_back(5);
    head->push_back(8);
    head->push_back(7);
    head->push_back(12);

    auto el = kth_node_to_last(head, 1);
    std::cout << el->value;

    while(head != nullptr) {
        auto tmp = head;
        head = head->next;
        delete tmp;
    }

}
node* kth_node_to_last(node* root, int k) {
    if(!root) return nullptr;
    auto tmp = root;
    auto find = root;

    while(k > 0) {
        if(tmp == nullptr) return nullptr;
        tmp = tmp->next;
        k--;
    }
    while(tmp != nullptr) {
        find = find->next;
        tmp = tmp->next;
    }
    return find;

};
