/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) {
            return nullptr;
        }
        
        Node* cur = head;
        Node* sub = nullptr;
        while(cur) {
            Node* next = cur->next;                 // Next in this list
            if (cur->child) {
                cur->next = flatten(cur->child);    // add returned list to current node
                cur->next->prev = cur;
                cur->child = nullptr;               // remove child
                while (cur->next) {                 // go to end of new list
                    cur = cur->next;        
                }
                cur->next = next;                   // add rest of current list
                if (next) {
                    next->prev = cur;                   
                }
            }
            cur = next;
        }
        
        return head;
    }
};