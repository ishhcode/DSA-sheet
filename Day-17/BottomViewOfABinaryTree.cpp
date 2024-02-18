//bottom view of a binary tree
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
    if (root == NULL) return ans;
    
    map<int, int> mpp; // stores lines and values
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        
        if (node->left != NULL) {
            q.push({node->left, line - 1});
        }
        if (node->right != NULL) {
            q.push({node->right, line + 1});
        }
    } 
    
    for (auto x : mpp) {
        ans.push_back(x.second);
    }
    return ans;
    }
};