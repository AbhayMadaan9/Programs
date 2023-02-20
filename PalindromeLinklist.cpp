#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
//https://www.codingninjas.com/codestudio/problems/palindrom-linked-list_799352?leftPanelTab=0
bool isPalindrome(LinkedListNode<int> *head) {
    vector<int>vec;
    LinkedListNode<int> *temp = head;
    while(temp)
    {
        vec.push_back(temp->data);
        temp = temp->next;
    }
    int n = vec.size();
    int start = 0;
    int end = n-1;
    while(start <= end)
    {
        if(vec[start] == vec[end]){ start++; end--;}
        else return false;
    }
    return true;

}