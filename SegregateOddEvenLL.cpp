#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int value;
            Node *next;
            Node(int value) : value(value), next(nullptr){};
        };

*****************************************************************/
// logic on neww copy
//https://www.codingninjas.com/codestudio/problems/odd-and-even-positioned-linked-list-nodes_1229404?leftPanelTab=1
Node *oddEvenLinkedList(Node *head) {
//     if(!head or !head->next) return head;
    
//   Node *start = head;
//   Node *temp = head;
//   int count = 0;
//   while (temp) {
//     count++;
//     temp = temp->next;
//   }
//   Node *end = temp;
//   count = (count%2==0) ? count / 2 +1 : count / 2;
//   while (count--) {
//     if (start->value % 2 == 0) {
//       end->next = start->next;
//       start->next = start->next->next;
//       end->next->next = NULL;
//       // update
//       end = end->next;
//     }
//     start = start->next;
//   }
//   return head;
  if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* odd = head;
    Node* even = head->next;
    Node* even_head = even;

    while(even != NULL && even->next != NULL) {
        odd->next = odd ->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = even_head;
    return head;
}