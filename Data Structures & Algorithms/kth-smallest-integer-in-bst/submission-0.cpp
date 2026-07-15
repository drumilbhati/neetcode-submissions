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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        auto dfs = [&](auto&& dfs, TreeNode* node) -> void {
            if (!node) return;

            dfs(dfs, node->left);
            v.push_back(node->val);
            dfs(dfs, node->right);  
        };

        dfs(dfs, root);

        return v[k-1];
    }
};
