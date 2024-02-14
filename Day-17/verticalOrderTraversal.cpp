//vertical order traversal of a binary tree
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            TreeNode* temp = it.first;
            //x->vertical y->level
            int x = it.second.first, y=it.second.second;

            nodes[x][y].insert(temp->val);

            if(temp->left != NULL){
                q.push({temp->left,{x-1,y+1}});
            }
            if(temp->right != NULL){
                q.push({temp->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int>col;
            for (auto q: p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};