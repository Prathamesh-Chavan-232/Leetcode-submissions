/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int ct = 0;
public:
    void dfs(TreeNode* root, int currMax) {
        if(root == nullptr) return;
        
        if(root->val >= currMax) {
            ct++;
            currMax = root->val;
        }
        dfs(root->left,currMax);
        dfs(root->right,currMax);
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ct;
    }
};