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
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaf1;
        vector<int>leaf2;
        DFS(root1,leaf1);
        DFS(root2,leaf2);
        return leaf1==leaf2;
    }
    void DFS(TreeNode*root,vector<int>&v){
        if(root){
            if(root->left==nullptr && root->right==nullptr){
                v.push_back(root->val);
            }
            DFS(root->right,v);
            DFS(root->left,v);
        }
    }
};