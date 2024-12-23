#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
};

class LinkedList {

public:
    ListNode* head;  
    ListNode* tail;  

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void pushFront(int value) {
        ListNode* newNode = new ListNode{value, head};
        if (head == nullptr) {
            tail = newNode;  
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pushBack(int value) {
        ListNode* newNode = new ListNode{value, nullptr};
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;  
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popFront() {
        if (head != nullptr) {
            ListNode* p = head;
            head = head->next;
            delete p;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

};

int main() {
    LinkedList list1;
    LinkedList list2;
    int input_n;
    int n = 0;
    while(std::cin >> input_n) {
        list1.pushBack(input_n);
        n++;
        }
    
    ListNode* current = list1.head;
    int i = 1;
    list2.pushFront(i);
    while (current != nullptr && i <= n && list2.head != nullptr){   
            
            if(current->value == list2.head->value){
                list2.popFront();
                current = current->next;
            }
            else{
                i++;
                list2.pushFront(i);
            }
        
        
    }
    

    if(list2.head == nullptr){
    std::cout << "YES" << std::endl;
    }else{
    std::cout << "NO" << std::endl;
    }

    return 0;
}