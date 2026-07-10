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
    void reverse(ListNode* head, ListNode* tail) {
        if (!head) return;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* limit = tail->next;

        while (curr != limit) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sz = 1;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevEnd = &dummy;

        ListNode* tail = head;
        ListNode* last = head;

        while (tail) {
            if (sz % k == 0) {
                ListNode* nextGroupStart = tail->next;
                reverse(last, tail);
                prevEnd->next = tail;
                last->next = nextGroupStart;

                prevEnd = last;
                last = nextGroupStart;
                tail = nextGroupStart;
            } else {
                tail = tail->next;
            }
            sz++;
        }
        return dummy.next;
    }
};
