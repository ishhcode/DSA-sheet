//Flatten BST to sorted list
//Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution
{
public:
    Node *ans = NULL,*prev = NULL;
    void help(Node *root){
        if(!root) return;
        help(root->left);
        if(prev){
            prev->left=NULL;
            prev->right=root;
        }
        else{
            ans = root;
        }
        prev=root;
        help(root->right);
        prev->left= NULL;
    }
    Node *flattenBST(Node *root)
    {
        // code here
        help(root);
        return ans;
        
    }
};