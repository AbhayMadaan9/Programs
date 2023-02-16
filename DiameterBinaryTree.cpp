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
//approch on new copy
//https://www.codingninjas.com/codestudio/problems/diameter-of-the-binary-tree_920552?leftPanelTab=1
int getheight(TreeNode<int> *root)
{
    if(!root) return 0;
    int leftSubtree = getheight(root->left);
    int rightSubtree = getheight(root->right);
    return max(leftSubtree, rightSubtree)+1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{ 
    if(!root) return 0;

    int opt1 = diameterOfBinaryTree(root->left);
    int opt2 = diameterOfBinaryTree(root->right);
    int opt3 = getheight(root->left) + getheight(root->right); // +1 to consider itself
    return max(opt1, max(opt2, opt3));
}
