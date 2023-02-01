#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/********************************/

 //   Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

/********************************/
//approch from striver youtube: https://www.youtube.com/watch?v=9VPm6nEbVPA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=40
//https://www.codingninjas.com/codestudio/problems/rotate-linked-list_920454

Node* solve(Node* head, int k)
{
        int count = 1;
    Node*temp = head;
    Node*cur = head;
     while(temp->next) {
        ++count;
        temp = temp->next;
     }
    temp->next = head;
    k = count-k%count;
    while(k--) cur = cur->next;
    head = cur->next;
    cur->next = NULL;
    return head;
}
Node *rotate(Node *head, int k) {
    if(!head or !head->next or k==0) return head;
    head = solve(head,k+1);
    return head;
}