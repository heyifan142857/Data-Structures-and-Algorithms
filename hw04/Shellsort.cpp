#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    int gap = n / 2;  


    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;  
    }
}


int main() {
    int n;
    if(std::cin >> n) {
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            std::cin >> nums[i];
        }
        shellSort(nums);
        for(int i = 0; i < n; i++) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
    
}