#include <bits/stdc++.h>
/**********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
    class TreeNode {
    public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
//https://www.codingninjas.com/codestudio/problems/check-if-all-levels-of-two-trees-are-anagrams-of-each-other-not_1214546?leftPanelTab=1
// approch 1 to make level order traversal and store it and sort them and then compare

// approch 2 to use map in which at each level for one tree of we
// increment the occurences of nodes and for another tree we decement the
// occurences of nodes if for each level map becomes empty then they are anagram

// approch 3 to make level order traversal for both trees, at each level check
// if the size of of the trees are same then continue else return false


bool solve(TreeNode<int> *root1, TreeNode<int> *root2) {
  vector<vector<int>> traversal;
  queue<TreeNode<int> *> q1;
  queue<TreeNode<int> *> q2;
  q1.push(root1);
  q2.push(root2);

  while (!q1.empty() and !q2.empty()) {

    int size1 = q1.size();
    int size2 = q2.size();
    if (size1 == size2) {
      for (int i = 0; i < size1; i++) {
        TreeNode<int> *node1 = q1.front();
        q1.pop();

        if (node1->left) {
          q1.push(node1->left);
        }
        if (node1->right) {
          q1.push(node1->right);
        }
      }
      for (int i = 0; i < size2; i++) {
        TreeNode<int> *node2 = q2.front();
        q2.pop();
        if (node2->left) {
          q2.push(node2->left);
        }
        if (node2->right) {
          q2.push(node2->right);
        }
      }
    } else {
      return false;
    }
  }
  if (q1.empty() and q2.empty())
    return true;
  else
    return false;
}

bool anagram(TreeNode<int> *root1, int n, TreeNode<int> *root2, int m) {
  if (n != m)
    return false;
  else {
    return solve(root1, root2);
  }
}
