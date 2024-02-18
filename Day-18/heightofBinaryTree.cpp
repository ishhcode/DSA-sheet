//maxDepth of the binary tree
int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    if(root==NULL) return 0;
    int lh= heightOfBinaryTree(root->left);
    int rh = heightOfBinaryTree(root->right);

    return max(lh,rh)+1;
}
