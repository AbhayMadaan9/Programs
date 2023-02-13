#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/rearrange-linked-list_764146?leftPanelTab=1
// Approch is dividing given LL into two halves and reversing the second half
// and then merging them alternatively
/************************************************************

    Following is the linked list node structure

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

************************************************************/
Node<int> *getMid(Node<int> *head) {
  Node<int> *slow = head;
  Node<int> *fast = head;
  while (fast and fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

Node<int> *merge(Node<int> *l1, Node<int> *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    Node<int>*dummy = new Node<int>(-1);
    Node<int>* cur = dummy;
    while (l1 && l2)
    {
        cur->next = l1;
        l1 = l1->next;
        cur = cur->next;
        cur->next = l2;
        l2 = l2->next;
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy->next;
}
Node<int> *bruteforce(Node<int> *head) {
  Node<int> *tmp = head;
  vector<int> ans;
  while (tmp) {
    int x = tmp->data;
    ans.push_back(x);
    tmp = tmp->next;
  }
  tmp = head;
  int n = ans.size();
  int i = 0, j = n - 1;
  while (tmp) {
    tmp->data = ans[i];
    if (tmp->next)
      tmp->next->data = ans[j];
    i++;
    j--;
    if (tmp->next)
      tmp = tmp->next->next;
    else
      break;
  }
  return head;
}
Node<int>* optimised(Node<int>*head)
{
     //dividing
  Node<int>*Mid = getMid(head);
  Node<int>*FirstHalf = head;
  Node<int>*SecondHalf = Mid->next;
  Mid->next = NULL;

  //merging alteratively
  return merge(FirstHalf, SecondHalf);
}
Node<int> *rearrangeList(Node<int> *head) {
 
  //return bruteforce(head);
  return optimised(head);
}