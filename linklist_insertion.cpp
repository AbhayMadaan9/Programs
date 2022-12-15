#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
/************************************************************/

    //Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

/************************************************************/
//https://www.codingninjas.com/codestudio/problems/insertion-in-a-singly-linked-list_4609646?leftPanelTab=1
Node* getpos(Node * ( & head), int n, int pos)
{
    Node*temp = head;
    int index = 0;
    while(temp->next != NULL and index+1 != pos)
    {
        index++;
        temp = temp->next;
    }
    return temp;
}

void insert(Node * ( & head), int n, int pos, int val) {
    //start, end, in between
    if(pos == 0) 
    {
        Node* NewNode = new Node(val);
        NewNode->next = head;
        head = NewNode;
    }
    else if(pos == n)
    {
        Node*temp = getpos(head, n, pos);
        Node* NewNode = new Node(val);
        temp->next = NewNode;
    }
    else 
    {
        Node*temp1 = getpos(head, n, pos);
        Node*temp2 = temp1->next;
        Node* NewNode = new Node(val);
        temp1->next = NewNode;
        NewNode->next = temp2;
    }
}
int main()
{
    return 0;
}