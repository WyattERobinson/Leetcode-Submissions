class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int num) { 
        val = num;
        next = nullptr;
    }
    Node(int num, Node* node) { 
        val = num;
        next = node;
    }
};

class MyLinkedList {
    Node* head;
    Node* tail;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size) {
            return -1;
        }
        Node* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* cur = new Node(val, head);
        head = cur;
        if (tail == nullptr) {
            tail = cur;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* cur = new Node(val, nullptr);
        if (tail) {
            tail->next = cur;
        }
        tail = cur;
        if (head == nullptr) {
            head = cur;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
        }
        else if (index == size) {
            addAtTail(val);
        }
        else {
            Node* prev = head;
            for (int i = 0; i < index - 1; i++) {
                prev = prev->next;
            }
            Node* cur = new Node(val, prev->next);
            prev->next = cur;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (size == 0 || index >= size) {
            return;
        }
        if (index == 0) {
            head = head->next;
        }
        else if (index == size - 1) {
            Node* prev = head;
            for (int i = 0; i < index - 1; i++) {
                prev = prev->next;
            }
            prev->next = nullptr;
            tail = prev;
        }
        else {
            Node* prev = head;
            for (int i = 0; i < index - 1; i++) {
                prev = prev->next;
            }
            prev->next = prev->next->next;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */