#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
/****************************************************************/
 
 //   Following is the class structure of the Node class:

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
//https://www.codingninjas.com/codestudio/problems/intersection-of-linked-list_630457?leftPanelTab=1
int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *ptr1 = firstHead;
    Node *ptr2 = secondHead;
    
    // base case
    if( ptr1 == NULL || ptr2 == NULL){
        return -1;
    }
    
    while( ptr1 != ptr2){
     ptr1 = ptr1->next;   
     ptr2 = ptr2->next;   
       
      if(ptr1 == ptr2){
          if(ptr1 == NULL or ptr2 == NULL){
              return -1;
          }
         else{
         return ptr1->data;
          }
      }

      if( ptr1 == NULL){
      ptr1 = secondHead;
       } 
        
      if( ptr2 == NULL){
       ptr2 = firstHead;
       } 
        
    }    
    return ptr1->data;
}
int main()
{
    return 0;
}