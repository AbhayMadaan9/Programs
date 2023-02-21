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
//Approch1 to use unorderedset if any node is already present then we say cycle exist 
//Approch2 to use slow, fast pointers if slow and fast pointer are same then there exist a cycle.
//https://www.codingninjas.com/codestudio/problems/cycle-detection-in-a-singly-linked-list_628974?leftPanelTab=1
bool detectCycle(Node *head)
{
	Node*slow = head;
    Node*fast = head;
    while(fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

