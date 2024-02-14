// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:

    void dfs(Node* ans, Node* node, unordered_map<int, Node*>& vis) {
        vis[ans->val] = ans;
        for (auto x : node->neighbors) {
            if (vis.find(x->val) == vis.end()) {
                Node* newNode = new Node(x->val);
                ans->neighbors.push_back(newNode);
                dfs(newNode, x, vis);
            }
            else {
                ans->neighbors.push_back(vis[x->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        Node* ans = new Node(node->val);
        unordered_map<int, Node*> vis;
        dfs(ans, node, vis);
        return ans;
    }
};