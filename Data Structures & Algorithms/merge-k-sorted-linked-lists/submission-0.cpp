/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        
        for(auto& l: lists) {
            if (l) {
                pq.push({l->val, l});
            }
        }

        ListNode* res = new ListNode(0);
        ListNode* ans = res;
        while (!pq.empty()) {
            auto [v, node] = pq.top();
            pq.pop();

            if (node->next) {
                pq.push({node->next->val, node->next});
            }
            res->next = node;
            res = res->next;
        }
        return ans->next;
    }
};
