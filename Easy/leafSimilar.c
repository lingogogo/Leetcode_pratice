/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void Recursion(struct TreeNode* root, int* array,int* count)
{
    if(root==NULL) return;
    if(root->left == NULL && root->right == NULL)
    {
        array[*count] = root->val;
        *count+=1; //*count++ cannot use.
        return;
    }
    
    Recursion(root->left,array,count);
    Recursion(root->right,array,count);
    
    
}
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int array1[100] = {0};
    int array2[100] = {0};
    int* count1 = malloc(sizeof(int)*1);
    *count1 = 0;
    int* count2 = malloc(sizeof(int)*1);
    *count2 = 0;
 
    Recursion(root1,array1,count1);
    Recursion(root2,array2,count2);
    
    int length = (*count1 > *count2)?*count1:*count2;

    for(int i = 0;  i < length; i++)
    {
        if(array1[i] != array2[i])
        {
            return false;
        }
    }
    return true;

}
