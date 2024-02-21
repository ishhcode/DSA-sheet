//build binary tree from inorder and postorder traversal
class Solution {
public:
TreeNode* constructTree(vector<int>& postOrder, int postStart, int postEnd, vector<int>& inOrder, int inStart, int inEnd, map<int,int>& mp) {
    if(postStart > postEnd || inStart > inEnd) return nullptr;
    
    TreeNode* root = new TreeNode(postOrder[postEnd]); // Create a new node

    int elem = mp[root->val];
    int nElem = elem - inStart;

    root->left = constructTree(postOrder, postStart, postStart + nElem - 1, inOrder, inStart, inStart + nElem - 1, mp);
    root->right = constructTree(postOrder, postStart + nElem, postEnd - 1, inOrder, elem + 1, inEnd, mp);
    
    return root;
}
    TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder) {
         int postStart = 0, postEnd = postOrder.size() - 1;
    int inStart = 0, inEnd = inOrder.size() - 1;

    map<int, int> mp;
    for(int i = inStart; i <= inEnd; i++) {
        mp[inOrder[i]] = i;
    }

    return constructTree(postOrder, postStart, postEnd, inOrder, inStart, inEnd, mp);
        
    }
};