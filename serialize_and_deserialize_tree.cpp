#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/serialise-deserialise-a-binary-tree_920328?leftPanelTab=1
/************************************************************/

//    Following is the TreeNode class structure

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

/************************************************************/

string serializeTree(TreeNode<int> *root)
{       
     if(!root) return "";
        
        string s ="";
        queue<TreeNode<int>*> q;
        q.push(root);
        while(!q.empty()) {
           TreeNode<int>* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->data)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;


}

TreeNode<int>* deserializeTree(string &data)
{
  if(data.size() == 0) return NULL; 
        stringstream s(data);
        string str; 
        getline(s, str, ',');//The getline() function extracts characters from the input stream and appends it to the string object until the delimiting character is encountered. syntax: istream& getline(istream& is,    string& str, char delim);
        TreeNode<int>*root = new TreeNode<int>(stoi(str));
        queue<TreeNode<int>*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            TreeNode<int>*node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
                TreeNode<int>* leftNode = new TreeNode<int>(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                TreeNode<int>* rightNode = new TreeNode<int>(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root;    }


    



int main()
{
    return 0;
}