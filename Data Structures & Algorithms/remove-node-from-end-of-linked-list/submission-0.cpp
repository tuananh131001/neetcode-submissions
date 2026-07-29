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
        cout << total << endl;
        // total = 4
        int removeIndex = total - n; //4 - 2 = 2 - total = 4
        if (removeIndex == 0) {
            return head->next;
        }

        curr = head;
        for (int i = 0; i < total - 1; i++) { // i < 1
            if ((i + 1) == removeIndex) { // 
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};
