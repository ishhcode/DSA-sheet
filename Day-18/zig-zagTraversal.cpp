//zig-zag traversal of a binary tree
class Solution {
public:
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans; // If the root is null, return empty vector
    
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level; // Don't preallocate size here, as it will be modified
        for (int i = 0; i < size; i++) {
            TreeNode* ele = q.front();
            q.pop();
            level.push_back(ele->val);
            
            // Here, you should check for left and right children of the current node, not the root
            if (ele->left) {
                q.push(ele->left);
            }
            if (ele->right) {
                q.push(ele->right);
            }
        }
        
        // If it's supposed to be reversed, reverse it
        if (!leftToRight) {
            reverse(level.begin(), level.end());
        }
        
        ans.push_back(level);
        leftToRight = !leftToRight;
    }
    return ans;
}

};