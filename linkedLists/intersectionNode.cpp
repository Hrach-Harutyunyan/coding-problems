#include <iostream>
#include <unordered_set>
#include "nodeHeader.hpp"

node* intersectionNode(node*, node*);

int main() {

    node* head1 = new node(12);
    head1->push_back(7);
    head1->push_back(8);
    head1->push_back(5);
    head1->push_back(8);
    head1->push_back(7);
    head1->push_back(12);

    node* head2 = new node(10);
    head2->next = head1->next->next->next;
    
    std::cout << intersectionNode(head1, head2)->value;

    return 0;
}

node* intersectionNode(node* head1, node* head2) {
    if(!head1 || !head2) return nullptr;
    std::unordered_set <node*> cache{};
    auto tmp1 = head1;
    auto tmp2 = head2;
    while(tmp1) {
        cache.insert(tmp1);
        tmp1 = tmp1->next;
    }
    while(tmp2) {
        if(cache.find(tmp2) != cache.end()) return tmp2;
        tmp2 = tmp2->next;
    }
    return nullptr;
};
