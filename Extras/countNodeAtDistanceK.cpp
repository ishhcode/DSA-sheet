//Count the nodes at distance K from leaf
class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    void help(Node* root,int k,vector<Node*> &vec,unordered_set<Node*>&s,int level){
        if(!root) return;
        if(!root->left and !root->right){
            if(k==0){
                s.insert(root);
            }
            else if(level-k>=0){
                s.insert(vec[level-k]);
            }
            return;
        }
        vec.push_back(root);
        help(root->left,k,vec,s,level+1);
        help(root->right, k, vec, s, level+1);
        vec.pop_back();
        
    }
    
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here. 
    	vector<Node*> vec;
    	unordered_set<Node*> s;
    	help(root,k,vec,s,0);
    	return s.size();
    	
    }
};
