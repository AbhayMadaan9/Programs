#include<bits/stdc++.h>
using namespace std;
/***********************************************************/
   // Binary Tree node structure:
    
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
//https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?leftPanelTab=1
bool isLeaf(TreeNode<int>*root)
{
    if(!root->left and !root->right) return true;
    else return false;
}

void addLeftBoundary(TreeNode<int> * root, vector < int > & res) {
  TreeNode<int> * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(TreeNode<int> * root, vector < int > & res) {
  TreeNode<int> * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(TreeNode<int> * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeftBoundary(root, ans);   //here root is send so that it will take root node value
    addLeaves(root, ans);
    addRightBoundary(root, ans);
    return ans;
}
int main()
{
    return 0;
}