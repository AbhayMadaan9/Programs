#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

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

************************************************************/
//https://www.codingninjas.com/codestudio/problems/merge-linkedlist_3125813?leftPanelTab=1
void merge(Node* head1, Node* head2)
{
        //base conditions
    if(!head1) return ;
    if(!head2) return ;

    Node*ptr1 = head1;
    Node*ptrNex1;
    if(head1->next) ptrNex1 = head1->next;
    else {
        head1->next = head2;
        return ;
    }
    Node*ptr2 = head2;
    Node*ptrNex2;
    if(head2->next) ptrNex2 = head2->next;
    else {
        head1->next = head2;
        head2->next = ptrNex2;
        return;
    }
    if(!head1->next and !head2->next) {head1->next = head2; return;}
    while (ptr1 and ptr2) {
      ptr1->next = ptr2;
      ptr2->next = ptrNex1;
      ptr1 = ptrNex1;
      ptr2 = ptrNex2;
      if(ptrNex1) ptrNex1 = ptrNex1->next;
      if(ptrNex2) ptrNex2 = ptrNex2->next;
    }
   return;
}