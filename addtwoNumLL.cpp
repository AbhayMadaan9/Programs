#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/add-two-linked-lists_799487?leftPanelTab=1
/************************************************************

    Following is the linked list node structure:
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }
    };

************************************************************/
Node<int>* reverse(Node<int>* head) {
        
        Node<int>* curr = head;
        Node<int>* prev = NULL;
        Node<int>* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(struct Node<int>* &head, struct Node<int>* &tail, int val) {
        
        Node<int>* temp = new Node<int>(val);
        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
Node<int>* add(Node<int>* first, Node<int>* second)
{
        int carry = 0;
        
        Node<int>* ansHead = NULL;
        Node<int>* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        return ansHead;

}
Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    //brute force approch is to simply add the two numbers and then create a new linklist of the number formed and return it.
    //optimal appoch is to parallely traverse both the numbers and maintaining the carry
        //step 1 -  reverse input LL
        first = reverse(first);
        second = reverse(second);
        
        //step2 - add 2 LL
        Node<int>* ans = add(first, second);
        
        //step 3 
        ans = reverse(ans);
        
        return ans;
}