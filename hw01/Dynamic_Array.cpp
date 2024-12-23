#include <iostream>
#include <vector>
//using namespace std;

class DynamicArray {
private:
    std::vector<int> data;  
    int capacity;        

public:
    DynamicArray() : capacity(10) {
        data.reserve(capacity);  
    }

    void append(int value) {
        if (data.size() == capacity) {
            resize();  
        }
        data.push_back(value);
    }

    void set(int index, int value) {
        if (index < data.size()) {
            data[index] = value;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    void erase(int index) {
        if (index < data.size()) {
            data.erase(data.begin() + index);
            if (data.size() < capacity / 2) {
                shrink(); 
            }
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    int get(int index) const {
        if (index < data.size()) {
            return data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    int size() const {
        return data.size();
    }

    int print_capacity() const {
        return capacity;
    }

    void print() const {
        for (const auto& val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

private:
    void resize() {
        capacity *= 2;
        data.reserve(capacity);
    }

    void shrink() {
        capacity /= 2;
        data.shrink_to_fit();  
    }
};

int main() {
    DynamicArray arr;
    std::string word;
    while(std::cin >> word){
        int index = 0;
        int x = 0;
        if(word == "append"){
            std::cin >> x;
            arr.append(x);
        }
        else if(word == "set"){
            std::cin >> index >> x;
            arr.set(index, x);
        }
        else if(word == "erase"){
            std::cin >> index;
            arr.erase(index);
        }
        else if(word == "get"){
            std::cin >> index;
            std::cout << arr.get(index) << std::endl;
        }
        else if(word == "size"){
            std::cout << arr.size() << std::endl;
        }
        else if(word == "capacity"){
            std::cout << arr.print_capacity() << std::endl;
        }
        else if(word == "print"){
            arr.print();
        }
        else{
            std::cout << "Invalid command" << std::endl;
    }
    
    }
    return 0;
}