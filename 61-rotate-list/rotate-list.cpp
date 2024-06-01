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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        if (!head->next || k == 0) {
            return head;
        }

        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* newHead = nullptr;
        int size = 0;

        // Get size of list
        while (cur) {
            size++;
            cur = cur->next;
        }

        int rotate = k % size;
        if (rotate == 0) {
            return head;
        }
        
        cur = head;
        for (int i = 0; i < size - rotate; i++) {
            prev = cur;
            cur = cur->next;
        }

        prev->next = nullptr;
        newHead = cur;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = head;

        return newHead;
    }
};