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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* p1 = &dummy;

        ListNode* p = list1;
        ListNode* q = list2;

        // Merging loop
        while (p != nullptr && q != nullptr) {
            if (p->val < q->val) {
                p1->next = p;
                p = p->next;
            } else {
                p1->next = q;
                q = q->next;
            }
            p1 = p1->next;
        }

        if (p != nullptr) {
            p1->next = p;
        }
        if (q != nullptr) {
            p1->next = q;
        }

        return dummy.next;
    }
};
