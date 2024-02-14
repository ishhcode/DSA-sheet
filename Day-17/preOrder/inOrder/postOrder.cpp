//inorder,preorder,postorder traversal in a binary tree

vector<vector<int>> getTreeTraversal(TreeNode *root) {
    vector<vector<int>> ans(3, vector<int>());
    stack<pair<TreeNode*, int>> st;
    if (!root) return ans;
    st.push({root, 1});
    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second == 1) {
            ans[1].push_back(it.first->data); // Store in pre-order vector
            it.second++; // Move to the next stage of traversal
            st.push(it);
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        } else if (it.second == 2) {
            ans[0].push_back(it.first->data); // Store in in-order vector
            it.second++; // Move to the next stage of traversal
            st.push(it);
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        } else {
            ans[2].push_back(it.first->data); // Store in post-order vector
        }
    }
    return ans;
}