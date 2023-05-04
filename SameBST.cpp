#include <bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/same-bst_920453
void traverse(TreeNode<int> *root, set<int> &st) {
  if (!root)
    return;
  st.insert(root->data);
  if (root->left)
    traverse(root->left, st);
  if (root->right)
    traverse(root->right, st);
}
bool checkBSTs(TreeNode<int> *root1, TreeNode<int> *root2) {
  set<int> st1;
  set<int> st2;
  traverse(root1, st1);
  traverse(root2, st2);
  return (st1 == st2);
}