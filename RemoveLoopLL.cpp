/*************************************************

    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
// approch on new copy
//https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0
Node *removeLoop(Node *head) {
  if (!head || !head->next) {
    return head;
  }

  Node *slow = head;
  Node *fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      slow = head;

      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      //now both are at node where loop starts
      while (slow->next != fast) {
        slow = slow->next;
      }
      
      slow->next = NULL;
      break;
    }
  }

  return head;
}
