#include <iostream>
#include <stack>
#include "nodeHeader.hpp"

node* findloop(node*);

int main() {

    node* head = new node(12);
    head->push_back(7);
    head->push_back(8);
    head->push_back(5);
    head->push_back(55);
    head->push_back(44);
    head->push_back(88);
    
    auto tmp = head;
    while(tmp->next) tmp = tmp->next;
    tmp->next = head->next->next->next->next;

    auto found = findloop(head);
    if(found) std::cout << found->value;
    else std::cout << "no loop";

    
    return 0;
}

node* findloop(node* head) {
    if(!head || !head->next) return nullptr;
    auto slow = head;
    auto fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(!fast || !fast->next) return nullptr;

    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
};
