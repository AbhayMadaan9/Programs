#include <bits/stdc++.h> 
/************************************************************/

    //Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
        ~Node() {
            if(next != NULL || prev != NULL){
                delete next;
            }
        }
};

/************************************************************/
//https://www.codingninjas.com/codestudio/problems/insertion-in-doubly-linked-list_4609682
Node* insert(int k, int val, Node *head) {
    // Write Your Code Here.
    if(head==NULL){
        return head;
    }Node* newnode=new Node(val);
    if(k==0){
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return head;
    }Node* temp=head;
    int count=0;
    while(temp->next!=NULL && count<k-1){
        temp=temp->next;
        count++;
    }if(temp->next==NULL){
        temp->next=newnode;
        newnode->prev=temp;
        return head;
    }else{
    Node* remainingNodes=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=remainingNodes;
    remainingNodes->prev=newnode;
    return head;
    }
}