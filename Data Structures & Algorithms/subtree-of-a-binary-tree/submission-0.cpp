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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> P, Q;

        auto inorder = [](auto&& inorder, TreeNode* node, vector<int>& v) -> void {
            if (!node) {
                v.push_back(-1);
                return;
            };

            v.push_back(node->val);
            inorder(inorder, node->left, v);
            inorder(inorder, node->right, v);
        };

        inorder(inorder, p, P);
        inorder(inorder, q, Q);

        return P == Q;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        auto dfs = [&](auto&& dfs, TreeNode* node) ->  void {
            if (!node) return;
            if (isSameTree(node, subRoot)) ans = true;
            dfs(dfs, node->left);
            dfs(dfs, node->right);
        };
        dfs(dfs, root);
        return ans;
    }
};
