#include <iostream>
#include <vector>
#include <cstdlib>

int partition(std::vector<int>& arr, int left, int right) {
    int pivot_index = left + std::abs(rand()) % (right - left + 1);
    int pivot_value = arr[pivot_index];
    std::swap(arr[pivot_index], arr[right]);
    int store_index = left;
    for(int i = left; i < right; i++) {
        if(arr[i] < pivot_value) {
            std::swap(arr[i], arr[store_index]);
            store_index++;
        }
    }
    std::swap(arr[store_index], arr[right]);
    return store_index;
}

int randomized_select(std::vector<int>& arr, int left, int right, int k) {
    if(left >= right) {
        return arr[left];
    }
    int pivot_index = partition(arr, left, right);
    if(k == pivot_index-left+1) {
        return arr[pivot_index];
    }
    else if(k < pivot_index-left+1) {
        return randomized_select(arr, left, pivot_index - 1, k);
    }
    else {
        return randomized_select(arr, pivot_index + 1, right, k-pivot_index+left-1);
}
}


int main() {
    std::vector<int> arr;
    int K;
    std::cin >> K;
    int n;
    while (std::cin >> n)
    {
        arr.push_back(n);
    }

    K = arr.size() - K + 1;
    std::cout << randomized_select(arr, 0, arr.size() - 1, K) << std::endl;

    return 0;
}