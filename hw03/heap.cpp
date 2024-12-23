#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class MinHeap {
private:
    struct element
    {
        int value;
        int index;
    };
    
    std::vector<element> heap;
    std::vector<int> indexmap;  
    int index_count = 0;

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void swap_element(element &a, element &b) {
        element temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(size_t index) {
        while (index > 0 && heap[parent(index)].value > heap[index].value) {
            swap_element(heap[parent(index)], heap[index]);
            swap(indexmap[heap[parent(index)].index], indexmap[heap[index].index]);
            index = parent(index);
        }
    }

    void heapifyDown(size_t index) {
        size_t least = index;
        size_t leftChildIdx = leftChild(index);
        size_t rightChildIdx = rightChild(index);

        if (leftChildIdx < heap.size() && heap[leftChildIdx].value < heap[least].value) {
            least = leftChildIdx;
        }

        if (rightChildIdx < heap.size() && heap[rightChildIdx].value < heap[least].value) {
            least = rightChildIdx;
        }

        if (least != index) {
            swap_element(heap[index], heap[least]);
            swap(indexmap[heap[index].index], indexmap[heap[least].index]);
            heapifyDown(least);
        }
    }

    size_t parent(size_t index) { return (index - 1) / 2; }
    size_t leftChild(size_t index) { return 2 * index + 1; }
    size_t rightChild(size_t index) { return 2 * index + 2; }

public:
    MinHeap() {
    }

    void push(int value) {
        heap.push_back({value,index_count});
        indexmap.push_back( heap.size() - 1);
        heapifyUp(heap.size() - 1);
        ++index_count;
    }

    int pop() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        int top = heap[0].value;
        if (heap.size() > 1) {
            heap[0] = heap.back(); 
            indexmap[heap[0].index] = 0;
            heap.pop_back();
            heapifyDown(0);
        } else {
            heap.pop_back();
        }
        return top;
    }

    int top() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0].value;
    }

    size_t size() const { return heap.size(); }

    bool empty() const { return heap.empty(); }

    void decrease(int i, int k) {

        int heapIndex = indexmap[i];

        heap[heapIndex].value = k;

        heapifyUp(heapIndex);  
}

};

int main() {
    MinHeap heap;
    std::string order;

    while (std::cin >> order) {
        if (order == "push") {
            int value;
            std::cin >> value;
            heap.push(value);
        } else if (order == "pop") {
            try {
                heap.pop();
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } else if (order == "top") {
            try {
                std::cout << heap.top() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } else if (order == "size") {
            std::cout << heap.size() << std::endl;
        } else if (order == "decrease") {
            int i, k;
            std::cin >> i >> k;
            try {
                heap.decrease(i - 1, k);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }

    return 0;
}


