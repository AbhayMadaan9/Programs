/****************************************************************

    Following is the class structure of the Node class:

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

*****************************************************************/
//https://www.codingninjas.com/codestudio/problems/segregate-odd-even_920524?topList=top-adobe-coding-interview-questions&leftPanelTab=1
Node * segregateOddEven (Node * head)
{
    Node *odd = NULL, *even = NULL;
    Node *oddEnd = NULL, *evenEnd = NULL;
    Node *curr = head;
    
    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            if (even == NULL) {
                even = evenEnd = curr;
            } else {
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        } else {
            if (odd == NULL) {
                odd = oddEnd = curr;
            } else {
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
        curr = curr->next;
    }
    
    if (odd == NULL) {
        return even;
    }
    
    oddEnd->next = even;
    
    if (even != NULL) {
        evenEnd->next = NULL;
    }
    
    return odd;
}

