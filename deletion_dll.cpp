#include <bits/stdc++.h> 
/****************************************************************/

    //Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node *prev;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
                this->prev = NULL;
            }
        };

/*****************************************************************/
//https://www.codingninjas.com/codestudio/problems/deletion-in-doubly-linked-list_4609672?leftPanelTab=1
void deleteNode(Node *(&head), int pos)
{
    if (pos == 0)
    { // deletion at head position
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 0;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        // deletion at tail deletion
        if (curr->next == NULL)
        {
            prev->next = NULL;
            curr->next = curr->prev = NULL;
            delete curr;
            return;
        }
        else
        {
            // deletion at other positions
            prev->next = curr->next;
            curr->next->prev = prev;
            curr->next = curr->prev = NULL;
            delete curr;
            return;
        }
    }
}