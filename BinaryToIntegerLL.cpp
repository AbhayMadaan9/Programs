/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/
//https://www.codingninjas.com/codestudio/problems/binary-to-integer_2421938?leftPanelTab=0
void reverseLinklist(Node*head)
{
    Node*Cur = head;
    Node*Prev = NULL;
    Node*Forward = NULL;
    while(Cur)
    {
        Forward = Cur->next;
        Cur->next = Prev;
        Prev = Cur;
        Cur = Forward;
    }

}
int binaryToInteger(int n, Node *head) {
    if(!head) return 0;
    
    int ans = 0, twoPow = pow(2, n-1);
    // int ans = 0, twoPow = 2;
   // reverseLinklist(head);
    Node* temp = head;
    while(temp)
    {
        int num = temp->data;
        ans += twoPow*num;
        temp = temp->next;
         twoPow /= 2;
        //twoPow *= 2;
    }
    return ans;
}