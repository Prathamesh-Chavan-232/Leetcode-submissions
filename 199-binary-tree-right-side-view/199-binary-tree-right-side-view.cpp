/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void recursion(TreeNode *root, int level, int &maxLvl, vector<int> &res)
        {
            if (root == NULL) return;
            if (level > maxLvl)
            {
                res.push_back(root->val);
                maxLvl = level;
            }
            recursion(root->right, level + 1, maxLvl, res);
            recursion(root->left, level + 1, maxLvl, res);
        }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        int maxLvl = 0;
        recursion(root, 1,maxLvl, res);
        return res;
    }
};