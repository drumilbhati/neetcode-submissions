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
    bool isBalanced(TreeNode* root) {
        
        bool ans = true;
        auto dfs = [&](auto& dfs, TreeNode* node) -> int {
            if (!node) return 0;

            if (!node->left && !node->right) return 0;

            int left = 0, right = 0;
            if (node->left) {
                left = 1 + dfs(dfs, node->left);
            }
            if (node->right) {
                right = 1 + dfs(dfs, node->right);
            }

            if (abs(left - right) > 1) {
                ans = false;
            }
            return max(left, right);
        };

        dfs(dfs, root);

        return ans;
    }
};
