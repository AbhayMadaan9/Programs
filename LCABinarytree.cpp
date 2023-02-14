/**********************************************************
    Following is the Binary Tree Node class structure.

    template <typename T>
    class BinaryTreeNode {
    public :
	    T data;
	    BinaryTreeNode<T> *left;
	    BinaryTreeNode<T> *right;

	    BinaryTreeNode(T data) {
	        this -> data = data;
	        left = NULL;
	        right = NULL;
	    }
    };

***********************************************************/
//https://www.codingninjas.com/codestudio/problems/lca-of-three-nodes_794944?leftPanelTab=1
//approch on new copy
BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) 
   {
    if(!root)
    {
        return root;
    }
    if(root->data == node1 || root->data == node2 || root->data == node3)
    {
        return root;
    }
    BinaryTreeNode<int>* left = lcaOfThreeNodes(root->left, node1, node2, node3);
    BinaryTreeNode<int>* right = lcaOfThreeNodes(root->right, node1, node2, node3);
    if(!left && !right)
    {
        return NULL;
    }
    if(!left && right)
    {
        return right;
    }
    if(left && !right)
    {
        return left;
    }
    return root;
}
