#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
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
//approch on copy
//https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250?leftPanelTab=1
Node *findMiddle(Node *head) {
  Node*slow = head;
    Node*fast = head;
    while(fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
int main()
{
    return 0;
}