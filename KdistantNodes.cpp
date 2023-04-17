#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// approch on new copy
//https://www.codingninjas.com/codestudio/problems/print-all-the-nodes-at-distance-k-from-the-given-node_982772?leftPanelTab=1
TreeNode<int> *findTarget(TreeNode<int> *root, int x) {
  if (!root)
    return NULL;
  if (root->data == x)
    return root;
  TreeNode<int> *left = findTarget(root->left, x);
  if (left) return left;
  TreeNode<int> *right = findTarget(root->right, x);
  if (right) return right;
  return NULL;
}

 void findParents(TreeNode<int>* root, unordered_map<TreeNode<int>*, TreeNode<int>*> &parent_track) {
        queue<TreeNode<int>*> queue;
        queue.push(root);
        while(!queue.empty()) { 
            TreeNode<int>* current = queue.front(); 
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
  vector<int> findKdistantNodes(TreeNode<int>* root, TreeNode<int>* target, unordered_map<TreeNode<int> *, TreeNode<int> *> parent_track, int k) {
        unordered_map<TreeNode<int>*, bool> visited; 
        queue<TreeNode<int>*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                TreeNode<int>* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode<int>* current = queue.front(); queue.pop();
            result.push_back(current->data);
        }
        return result;
    }
vector<int> kDistance(TreeNode<int> *root, int target, int k) {
  TreeNode<int> *Target = findTarget(root, target);
  unordered_map<TreeNode<int> *, TreeNode<int> *> parents;
  findParents(root, parents);
  vector<int> ans;
return findKdistantNodes(root, Target, parents, k);

}