//children sum property in a binary tree

bool isParentSum(Node *root){
    // Write your code here.
    if (!root || (!root->left && !root->right))
        return true;
    int child =0;
    if(root->left){
        child+= root->left->data;
    }
    if(root->right){
        child+= root->right->data;
    }

    if(child !=root->data){
        return false;
    }
     return isParentSum(root->left) && isParentSum(root->right);
}