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
    int getDecimalValue(ListNode* head) {
        
        queue<int> q;
        while(head != NULL) {
            q.push(head->val);
             head = head->next;
        }
        int res = 0;
        int size = q.size();

        for (int i = size - 1; i >= 0; i--) {
            res += pow(2, i) * q.front();
            q.pop();
        }
        return res;
        
    }
};