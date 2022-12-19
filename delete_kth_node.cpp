#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************/

 //   Following is the class structure of the LinkedListNode class:

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

/*****************************************************************/
//approch on copy
//https://www.codingninjas.com/codestudio/problems/delete-kth-node-from-end-in-linked-list_799912?leftPanelTab=1
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(!head or K == 0) return head;
       LinkedListNode<int>* start = new LinkedListNode<int>(-1);
        start -> next = head;
        LinkedListNode<int>* fast = start;
        LinkedListNode<int>* slow = start;     

    for(int i = 1; i <= K; i++)
        fast = fast->next;
    
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    slow->next = slow->next->next;
    
    return start->next;
}
int main()
{
    return 0;
}