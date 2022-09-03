#ifndef __NODE__HEADER__HPP__
#define __NODE__HEADER__HPP__

struct node {
    node(int num) : value {num}, next{nullptr} { }
    void push_back(int num) {
        node* end = new node(num);
        node* tmp = this;
        while(tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = end;
        end = nullptr;
        tmp = nullptr;
    }
    node* next;
    int value;
};

#endif