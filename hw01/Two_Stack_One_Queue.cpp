#include <iostream>
#include <queue>

class Stack {
private:
    std::queue<int> A, B;

public:
    void enqueue() {
        A.push(1);
        std::cout << "push A" << std::endl;
    }

    void dequeue() {
        if(!B.empty()){
            B.pop();
            std::cout << "pop B" << std::endl;
        }else
        {
            while (A.size() > 1) {
            std::cout << "move A B" << std::endl;
            B.push(1);
            A.pop();
            }
            A.pop();
            std::cout << "pop A" << std::endl;
        }
        
        
        
    }


};


int main() {
    Stack stack;

    std::string word;
    while(std::cin >> word){
        if(word == "enqueue"){
            stack.enqueue();
        }
        else if(word == "dequeue"){
            stack.dequeue();
        }
    }

    return 0;
}