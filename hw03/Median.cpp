#include <iostream>
#include <vector>
#include <algorithm> 

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify_max(std::vector<int> &arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify_max(arr, n, largest);
    }
}

void heapify_min(std::vector<int> &arr, int n, int i) {
    int smallest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify_min(arr, n, smallest);
    }
}

int main() {
    std::vector<int> max_heap; 
    std::vector<int> min_heap; 
    int num, median = 0;

    while (std::cin >> num) {
        if (max_heap.empty() || num <= max_heap.front()) {
            max_heap.push_back(num);
            std::push_heap(max_heap.begin(), max_heap.end());
        } else {
            min_heap.push_back(num);
            std::push_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
        }

        if (max_heap.size() > min_heap.size() + 1) {
            std::pop_heap(max_heap.begin(), max_heap.end());
            min_heap.push_back(max_heap.back());
            std::push_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
            max_heap.pop_back();
        } else if (min_heap.size() > max_heap.size()) {
            std::pop_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
            max_heap.push_back(min_heap.back());
            std::push_heap(max_heap.begin(), max_heap.end());
            min_heap.pop_back();
        }


    
        median = max_heap.front();
        

        std::cout << median << std::endl;
    }

    return 0;
}