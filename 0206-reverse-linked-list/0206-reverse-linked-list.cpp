
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x),   
 next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)   
 {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* x = head;
        ListNode* y = x->next;

        while (y != NULL) {
            ListNode* temp = y->next;
            y->next = x;
            x = y;
            y = temp;
        }

        head->next = NULL; 
        return x;
    }
};