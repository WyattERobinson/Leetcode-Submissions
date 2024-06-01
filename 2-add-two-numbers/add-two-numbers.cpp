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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remainder = l1->val + l2->val >= 10 ? 1 : 0;
        int sum = l1->val + l2->val;
        ListNode* head = new ListNode(sum % 10);
        ListNode* prev = head;
        
        l1 = l1->next;
        l2 = l2->next;
        while (l1 && l2) {
            sum = l1->val + l2->val + remainder;
            remainder = l1->val + l2->val + remainder >= 10 ? 1 : 0;
            ListNode* cur = new ListNode(sum % 10);
            prev->next = cur;
            prev = cur;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            sum = (l1->val + remainder);
            remainder = sum >= 10 ? 1 : 0;
            ListNode* cur = new ListNode(sum % 10);
            prev->next = cur;
            prev = cur;
            l1 = l1->next;
        }
        
        while (l2) {
            sum = (l2->val + remainder);
            remainder = sum >= 10 ? 1 : 0;
            ListNode* cur = new ListNode(sum % 10);
            prev->next = cur;
            prev = cur;
            l2 = l2->next;
        }
        
        if (remainder) {
            ListNode* cur = new ListNode(1);
            prev->next = cur;
        }
        
        return head;
    }
};