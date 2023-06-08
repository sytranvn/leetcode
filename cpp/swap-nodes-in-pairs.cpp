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
    ListNode* swapPairs(ListNode* head) {
        ListNode* left, * right;
        left = head;
        int tmp;
        while (left != NULL) {
            right = left->next;
            if (right != NULL) {
                tmp = left->val;
                left->val = right->val;
                right->val = tmp;
                left = right->next;
            } else break;
        }
        return head;
    }
};
