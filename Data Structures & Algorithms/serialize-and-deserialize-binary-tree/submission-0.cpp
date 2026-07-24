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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                ans += "null,";
                continue;
            }
            ans += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        deque<string> dq;
        string curr = "";
        for (char c: data) {
            if (c == ',') {
                dq.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }

        if (dq.empty() || dq.front() == "null") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dq.front()));
        dq.pop_front();

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            string left = dq.front();
            dq.pop_front();

            if (left != "null") {
                node->left = new TreeNode(stoi(left));
                q.push(node->left);
            }

            string right = dq.front();
            dq.pop_front();

            if (right != "null") {
                node->right = new TreeNode(stoi(right));
                q.push(node->right);
            }
        }
        return root;
    }
};
