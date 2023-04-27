#include <bits/stdc++.h>
using namespace std;

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
//https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331?leftPanelTab=1
Node *removeDuplicates(Node *head) {
    unordered_set<int> st;
    Node *prev = NULL;
    Node *curr = head;
    while (curr) {
        if (st.find(curr->data) != st.end()) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            st.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

