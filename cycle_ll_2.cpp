#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
/****************************************************************/

    // Following is the class structure of the Node class:

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
//Approch 1 same as of detect cycle part1
//Approch 2 also similiar to detect cycle part1 but here inorder to find the start node we use logic that when slow and fast pointer collide we make and entry node initially pointing to head then make both slow and entry pointer to move ahead untill they collide
//https://www.codingninjas.com/codestudio/problems/detect-the-first-node-of-the-loop_1112628?leftPanelTab=1
Node *firstNode(Node *head)
{
	Node* slow = head;
    Node* fast = head;
    while(fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            Node*entry = head;
            while(entry != slow)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
}
int main()
{
    return 0;
}