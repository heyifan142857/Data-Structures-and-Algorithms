#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
};

class LinkedList {
private:
    ListNode* head;  
    ListNode* tail;  
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void pushFront(int value) {
        ListNode* newNode = new ListNode{value, head};
        if (head == nullptr) {
            tail = newNode;  
        }
        head = newNode;
    }

    void pushBack(int value) {
        ListNode* newNode = new ListNode{value, nullptr};
        if (tail == nullptr) {
            head = tail = newNode;  
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int search(int value) {
        ListNode* current = head;
        int find = 0;
        while (current!= nullptr) {
            if (current->value == value) {
                find = 1;
                break;
            }
            current = current->next;
        }
        return find;
    }

    void remove(int value) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        while (current!= nullptr) {
            if (current->value == value) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                if (current == tail) {
                    tail = prev;
                }
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }
    }

    void print() {
        ListNode* current = head;
        while (current!= nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
        }


};

int main() {
    LinkedList list;
    std::string word;

    while(std::cin >> word) {    
        if (word == "pushFront") {
            int value;
            std::cin >> value;
            list.pushFront(value);
        } else if (word == "pushBack") {
            int value;
            std::cin >> value;
            list.pushBack(value);
        } else if (word == "search") {
            int value;
            std::cin >> value;
            std::cout << list.search(value) << std::endl;
        } else if (word == "remove") {
            int value;
            std::cin >> value;
            list.remove(value);
        } else if (word == "print") {
            list.print();
        }    
    }

    return 0;
}

