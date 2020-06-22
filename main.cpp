//
//  main.cpp
//  Linked List
//
//  Created by Ira Xavier Porchia on 5/7/20.
//  Copyright © 2020 Ira Xavier Porchia. All rights reserved.
//

#include <iostream>
using namespace std;


class node{
    friend class linkedList;
private:
    int _data;
    node *_next;
public:
    node(int data):
    _data(data), _next(nullptr){}
};

class linkedList{
private:
    node *_head;
public:
    linkedList():
    _head(nullptr){}
    
    ~linkedList(){
        clear();
    }
    
    void clear(){
        node *temp;
        while(_head != nullptr){
            temp = _head;
            _head = _head->_next;
            temp->_next = nullptr;
            delete temp;
        }
    }
    
    void prepend(int data){
        node *temp = _head;
        _head = new node(data);
        _head->_next = temp;
    }
    
    void remove(int data){
        node *p = _head;
        node *q = _head;
        while(p != nullptr){
            if(_head->_data == data){
                _head = _head->_next;
            }else if(p->_data == data){
                q->_next = p->_next;
            }
            q = p;
            p = p->_next;
        }
    }
    
    void traverse(){
        for(node *p = _head; p != nullptr; p = p->_next){
            if(p->_next != nullptr){
                cout << p->_data << ", ";
            }else{
                cout << p->_data;
            }
        }
        cout << endl;
    }
    
};

int main(int argc, const char * argv[]) {
    linkedList list;
    list.prepend(5);
    list.prepend(10);
    list.prepend(15);
    list.prepend(12);
    list.prepend(20);
    list.prepend(25);
    list.traverse();
    list.remove(12);
    list.traverse();
    return 0;
}
