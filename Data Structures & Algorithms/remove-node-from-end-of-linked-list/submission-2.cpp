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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        ListNode* curr = head;
        while(curr) {
            total++;
            curr = curr->next;
        }

        int removeIdx = total - n; // 0
        if (removeIdx == 0) {
            return head->next;
        }
        curr = head;
        for (int i = 0; i < total - 1; i++) {
            if ((i + 1) == removeIdx) {
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;

        
    }
};
