/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/
//https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?leftPanelTab=1
Node * uniqueSortedList(Node * head) {
    if(!head or !head->next) return head;
    Node*ptr1 = head;
    Node*ptr2 = head->next;
    while(ptr2)
    {
        if(ptr1->data == ptr2->data)
        {
            if(ptr2->next)
            {
                ptr1->next = ptr2->next;
                ptr2 = ptr1->next;
            }
            else{
                ptr1->next = NULL;
                break;
            }
        }
        else{
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    return head;
}