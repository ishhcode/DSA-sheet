//check if binary tree is symmetric or not


class Solution {
public:

bool isSymmetrisUtil(TreeNode *root1, TreeNode* root2){
    if(!root1 ||!root2) return root1 == root2;
    return root1->val == root2->val && isSymmetrisUtil(root1->left,
     root2->right) && isSymmetrisUtil(root1->right, root2->left);
}
    bool isSymmetric(TreeNode* root) {
         if(!root) return true;
    return isSymmetrisUtil(root->left,root->right);
    }
};