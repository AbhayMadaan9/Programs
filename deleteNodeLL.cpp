#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    if(!node) return;
    LinkedListNode<int> *Cur = node;
    //last node
    if(!Cur->next) 
    {
        Cur = NULL;
        delete Cur;
        return;
    }
    LinkedListNode<int> *Nex = Cur->next;
    Cur->data = Nex->data;
    Cur->next = Nex->next;
    delete Nex;
}