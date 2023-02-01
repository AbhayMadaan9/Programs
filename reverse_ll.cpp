#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
/****************************************************************/

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

/*****************************************************************/
//approch on copy
//https://www.codingninjas.com/codestudio/problems/reverse-linked-list_920513?leftPanelTab=1
Node* reverseLinkedList(Node *head)
{
    Node*prev = NULL;
    Node*curr = head;
    Node*forward = NULL;
    
    while(curr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}


int main()
{
    return 0;
}