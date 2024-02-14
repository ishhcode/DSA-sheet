//top view of a binary tree
class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL) return ans;
    
    map<int, int> mpp; // stores lines and values
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode<int>* node = it.first;
        int line = it.second;
        if(mpp.find(line)==mpp.end())mpp[line]= node->data;
        
        if (node->left != nullptr) {
            q.push({node->left, line - 1});
        }
        if (node->right != nullptr) {
            q.push({node->right, line + 1});
        }
    } 
    
    for (auto x : mpp) {
        ans.push_back(x.second);
    }
    return ans;
}
