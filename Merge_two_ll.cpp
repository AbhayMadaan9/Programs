#include <bits/stdc++.h> 
//https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=1
/************************************************************/

  //  Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

/************************************************************/
//Approch 1 to take pointer on both list and compare their data and creating new linklist from that but this approch takes extra space complexity
//approch 2 to take pointer on both and compare their data instead of forming new node change their next pointer.(by striver)
//approch 3 take any one list and for two of nodes of taken list check if we can place node of another ll if yes then insert and change the pointer if not then move ahead in another ll(by babber)
Node<int>* solve(Node<int>* first, Node<int>* second)
{
      Node<int>* curr1 = first;
    Node<int>* next1 = curr1 -> next;
    
    Node<int>*curr2 = second;
    Node<int>*next2 = NULL;  //or Node<int>*next2 = curr2 -> next;
    //this will not affect because of the pattern of updating the current pointer to the node.
    
    while(next1 != NULL && curr2 != NULL) {
        
        if( (curr2 -> data >= curr1 -> data ) && ( curr2 -> data <= next1 -> data)) {
           
            curr1 -> next = curr2;
            next2 = curr2->next;
            curr2 -> next = next1;
            
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            curr1 = next1;
            next1 = next1->next;
            if(!next1) 
            {
                curr1->next = curr2;
                return first;
            }
        }
        
    }

    return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first) return second;
    if(!second) return first;
    //handled special case
    if(!first->next and !second->next) 
    {
        if(first->data >= second->data) {second->next = first; return second;}
    else 
    {
        first->next = second; return first;
    }
    }
    if(first->data >= second->data) return solve(second, first);
    else return solve(first, second);
}
