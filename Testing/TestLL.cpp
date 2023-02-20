#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<int> *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};
void print(Node<int> *head)
{
    Node<int> *temp = head;

    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
Node<int> *getMid(Node<int> *head)
{
    Node<int> *slow = head;
    Node<int> *fast = head;
    while (fast and fast->next)
    {
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
    Node<int>*dummy = new Node(-1);
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
Node<int> * segregateOddEven (Node<int> * head)
{
   if(!head or !head->next) return head;
  Node<int> *start = head;
  Node<int> *temp = head;
  int count = 0;
  while (temp) {
    count++;
    temp = temp->next;
  }
  cout<<count<<endl;
  Node<int> *end = temp;
  count = (count % 2 == 0) ? count / 2 + 1 : count / 2;
  
//   while (count--) {
//     end->next = start->next;
//     start->next = start->next->next;
//     end->next->next = NULL;
//     // update
//     end = end->next;
//     start = start->next;
//   }
  return head;
}
int main()
{
    Node<int> *LL1 = new Node(1);
    Node<int> *temp = LL1;
    temp->next = new Node(2);
    temp = temp->next;
    temp->next = new Node(3);
    temp = temp->next;

    Node<int> *LL2 = new Node(4);
    temp = LL2;
    temp->next = new Node(5);
    temp = temp->next;
    temp->next = new Node(6);
    temp = temp->next;
    //dividing
  Node<int>*Mid = getMid(LL1);
  Node<int>*FirstHalf = LL1;
  Node<int>*SecondHalf = Mid->next;
  Mid->next = NULL;
    // merging alteratively
    // Node<int>*newe = merge(FirstHalf, SecondHalf);
    segregateOddEven(LL1);
   // print(LL1);
    return 0;
}
