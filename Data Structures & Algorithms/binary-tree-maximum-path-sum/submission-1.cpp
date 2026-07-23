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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        auto dfs = [&](auto&& dfs, TreeNode* node, int sm) -> int {
            if (!node) {
                return 0;
            }

            int left = max(0, dfs(dfs, node->left, sm + node->val));
            int right = max(0, dfs(dfs, node->right, sm + node->val));
            ans = max(ans, left + right + node->val);

            return max(node->val + left, node->val + right);
        };
        dfs(dfs, root, 0);
        return ans;
    }
};
