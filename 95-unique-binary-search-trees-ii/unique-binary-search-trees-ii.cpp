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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};

        vector<vector<TreeNode*>> dp(n + 1);
        dp[0].push_back(nullptr);
        for (int nodes = 1; nodes <= n; nodes++) {
            for (int root = 1; root <= nodes; root++) {
                for (TreeNode* left_tree : dp[root - 1]) {
                    for (TreeNode* right_tree : dp[nodes - root]) {
                        TreeNode* root_node = new TreeNode(root);
                        root_node->left = left_tree;
                        root_node->right = clone(right_tree, root);
                        dp[nodes].push_back(root_node);
                    }
                }
            }
        }
        return dp[n];
    }

private:
    TreeNode* clone(TreeNode* n, int offset) {
        if (n == nullptr) return nullptr;
        TreeNode* node = new TreeNode(n->val + offset);
        node->left = clone(n->left, offset);
        node->right = clone(n->right, offset);
        return node;
    }
};