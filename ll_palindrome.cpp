#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
/****************************************************************/

    //Following is the class structure of the Node class:

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
//https://www.codingninjas.com/codestudio/problems/check-if-linked-list-is-palindrome_985248?leftPanelTab=1
//Approch 1 to store ll in array and then check if it is palindrome or not 
//Approch 2 to reverse the string from mid point and compare from start of ll and start of mid point.
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
bool isPalindrome(Node *head)
{
    Node* temp = head;
    int size = 1;
    while(temp)
    {
        temp = temp->next;
        size++;
    }
    temp = head;
    int n = 1;
    while(temp and n < size/2)
    {
        temp = temp->next;
        n++;
    }
    Node* midnode = reverseLinkedList(temp);
    temp = head;
    while(temp and midnode)
    {
        if(temp->data == midnode->data)
        { 
        temp = temp->next;
        midnode = midnode->next;
        }
        else return false;
    }
    return true;
    
}
int main()
{
    return 0;
}