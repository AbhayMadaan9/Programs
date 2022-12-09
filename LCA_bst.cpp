#include<bits/stdc++.h>
using namespace std;
/************************************************************/
  //  Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

/************************************************************/
//approch on copy
//https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?leftPanelTab=1
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
   if(!root) return NULL;
    if(root->data > P->data and root->data > Q->data) return LCAinaBST(root->left, P, Q);
    if(root->data < P->data and root->data < Q->data) return LCAinaBST(root->right, P, Q);
    else return root;
}

int main()
{
    return 0;
}