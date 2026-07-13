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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](auto&& dfs, TreeNode* node, int mx) -> void {
            if (!node) return;

            if (node->val >= mx) {
                ans++;
            }

            dfs(dfs, node->left, max(mx, node->val));
            dfs(dfs, node->right, max(mx, node->val));
        };

        dfs(dfs, root, INT_MIN);
        return ans;
    }
};
