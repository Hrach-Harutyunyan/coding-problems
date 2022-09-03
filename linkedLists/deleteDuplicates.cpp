#include <iostream>
#include <unordered_set>
#include "nodeHeader.hpp"

void removeDuplicates(node*);

int main() {
    node* head = new node(13);
    head->push_back(13);
    head->push_back(10);
    head->push_back(5);
    head->push_back(6);
    head->push_back(10);
    head->push_back(10);

    node* t = head;
    removeDuplicates(t);
    t = head;

    while(t != nullptr) {
        std::cout << t->value << " ";
        t = t->next;
    }

    while(head != nullptr) {
        auto tmp = head;
        head = head->next;
        delete tmp;
    }
}

void removeDuplicates(node* root) {
    if(!root || !root->next) return;
    std::unordered_set <int> cache{};
    node* prev = nullptr;
    while(root != nullptr) {
        if(cache.find(root->value) == cache.end()) {
            cache.insert(root->value);
            prev = root;
            root = root->next;
        } else {
            root = root->next;
            prev->next = root;
        }
    }
}
