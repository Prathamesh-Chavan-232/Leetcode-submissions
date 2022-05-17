/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    
    TreeNode* ans, *target;
public:

    void preorder(TreeNode* original, TreeNode* cloned) {
        if(original == NULL) return;
        if(original == target) 
            ans = cloned;
        preorder(original->left,cloned->left);
        preorder(original->right,cloned->right);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        this->target = target;
        preorder(original,cloned);
        return ans;
    }
};