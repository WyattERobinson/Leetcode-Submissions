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
        ListNode* tail = nullptr;
        ListNode* newHead = nullptr;
        int size = 1;

        // Get size of list, track tail
        while (cur->next) {
            size++;
            cur = cur->next;
        }
        tail = cur;

        // We can only rotate n times, where n is the list size - 1
        // If k == size, then there's no rotation
        int rotate = k % size;
        if (rotate == 0) {
            return head;
        }
        
        // Place cur at the new head and prev... one previous
        cur = head;
        for (int i = 0; i < size - rotate; i++) {
            prev = cur;
            cur = cur->next;
        }
        
        // Make cur the new head pointer
        // connect the tail to the original head
        prev->next = nullptr;
        newHead = cur;
        tail->next = head;

        return newHead;
    }
};