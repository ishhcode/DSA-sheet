//Min distance between two given nodes of a Binary Tree

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    void help(Node* root, vector<int> &curPath,vector<int>&pathA,vector<int>&pathB,int a,int b ){
        if(!root) return;
        curPath.push_back(root->data);
        if(root->data==a){
           pathA = curPath;
        }
        if(root->data==b){
           pathB = curPath;
        }
        help(root->left,curPath,pathA,pathB,a,b);
        help(root->right,curPath,pathA,pathB,a,b);
        curPath.pop_back();
        
        
        
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        vector<int>curPath, pathA, pathB;
        help(root,curPath,pathA,pathB,a,b);
        int i=0,j=0;
        while(i<pathA.size() and j< pathB.size()){
            if(pathA[i]!= pathB[j]) break;
            i++;
            j++;
        }
        
        return pathA.size() - i + pathB.size() - j;
        
    }
};