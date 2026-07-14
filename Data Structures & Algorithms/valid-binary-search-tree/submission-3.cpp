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
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        auto dfs = [&](auto&& dfs, TreeNode* node) -> pair<int, int> {
            if (!node) return {INT_MAX, INT_MIN};

            if (!node->left && !node->right) {
                return {node->val, node->val};
            }

            pair<int, int> left = dfs(dfs, node->left);
            if (left.second >= node->val) {
                ans = false;
            }


            pair<int, int> right = dfs(dfs, node->right);
            if (right.first <= node->val) {
                ans = false;
            }

            return {min(node->val, left.first), max(node->val, right.second)};
        };

        dfs(dfs, root);
        return ans;
    }
};
