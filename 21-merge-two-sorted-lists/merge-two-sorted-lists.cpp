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
        // If empty lists (could probably be better)
        if (!list1 && !list2) { return nullptr; }
        if (!list1) { return list2; }
        if (!list2) { return list1; }
        
        // Determine head node
        ListNode* head = nullptr;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }
        
        // Iterate through lists until one ends
        ListNode* prev = head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                prev->next = list1;
                list1 = list1->next;
            }
            else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        
        // Add any remaining nodes
        while (list1) {
            prev->next = list1;
            prev = prev->next;
            list1 = list1->next;
        }
        
        while (list2) {
            prev->next = list2;
            prev = prev->next;
            list2 = list2->next;
        }
        
        return head;
    }
};