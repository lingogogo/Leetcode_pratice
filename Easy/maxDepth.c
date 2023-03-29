int maxDepth(struct TreeNode* root){
    int recursive(struct TreeNode*);
    if(!root)
    {
        return 0;
    }
    int r1 = recursive(root->left);
    int r2 = recursive(root->right);
    if(r1 >= r2)
    {
        return r1;
    }else{
        return r2;
    }
    
}
int recursive(struct TreeNode* p){
    if(!p)
    {
        return 1;
    }
    int num1 = recursive(p->left);
    int num2 = recursive(p->right);
    if(num1 >=num2)
    {
        return ++num1;
    }else{
        return ++num2;
    }
    
}
