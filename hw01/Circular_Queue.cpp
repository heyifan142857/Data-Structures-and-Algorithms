#include <iostream>
#include <vector>

class CircularArray {
private:
    std::vector<int> data;  
    int head = 0;
    int tail = 0;
    int capacity = 0;
    int elements = 0;
public:
    CircularArray(int size):capacity(size), data(size),head(0),tail(0),elements(0) {}

    void enqueue(int value) {
        if(isFull()){
            std::cout << "Overflow" << std::endl;
            return;
        }
        if(isEmpty()){
            data[tail] = value;
            }
        else{
            tail = (tail + 1) % capacity;
            data[tail] = value;
        }
        elements++;
    }

    void dequeue() {
        if(isEmpty()){
            std::cout << "Underflow" << std::endl;
            return;
        }
        if(head != tail){
            head = (head + 1) % capacity;
        }
        elements--;
    }

    bool isEmpty() {
        return elements == 0;
    }

    bool isFull() {
        return elements == capacity;
    }
    
    int front() {
        if(isEmpty()){
            //std::cout << "-1" << std::endl;
            return -1;
        }
        return data[head];
    }

    int rear() {
        if(isEmpty()){
            //std::cout << "-1" << std::endl;
            return -1;
        }
        return data[tail];
    }
    
};

int main() {
    std::string word;
    int size = 0;
    std::cin >> size;
    CircularArray arr(size);

    while(std::cin >> word){
        if(word == "enqueue"){
            int value = 0;
            std::cin >> value;
            arr.enqueue(value);
        }
        else if(word == "dequeue"){
            arr.dequeue();
        }
        else if(word == "front"){
            std::cout << arr.front() << std::endl;
        }
        else if(word == "rear"){
            std::cout << arr.rear() << std::endl;
        }
        else if(word == "isEmpty"){
            if(arr.isEmpty()){
                std::cout << "True" << std::endl;
            }
            else{
                std::cout << "False" << std::endl;  
            }
        }
        else if(word == "isFull"){
            if(arr.isFull()){
                std::cout << "True" << std::endl;
            }
            else{
                std::cout << "False" << std::endl;  
            }
        }
    }
    return 0;
}