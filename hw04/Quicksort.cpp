#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct middle{
    int mid1;
    int mid2;
};


void insertionSort(vector<int>& nums, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = nums[i];
        int j = i - 1;

        while (j >= left && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
}

//选定一个pivot并将left到right之间的元素通过pivot划分成两部分，然后返回pivot的下标
middle _partition(vector<int>& nums, int left, int right) {
    int randomPivotIndex = left + rand() % (right - left + 1);
    int pivot = nums[randomPivotIndex];
    swap(nums[randomPivotIndex], nums[right]); 
    int mid1 = left - 1; 
    int mid2 = right;   
    
    int i = left; 
    while (i < mid2) {
        if (nums[i] < pivot) {
            mid1++;
            swap(nums[i], nums[mid1]);
            i++;
        } else if (nums[i] > pivot) {
            mid2--;
            swap(nums[i], nums[mid2]);
        } else {
            i++;
        }
    }
    swap(nums[mid2], nums[right]);
    return {mid1 + 1, mid2}; 
}


//将nums通过_partition划分成两部分，对每个部分调用_quick_sort
void _quick_sort(vector<int>& nums, int left, int right) {
    if (left < right) {
        if (right - left < 10) { 
            insertionSort(nums, left, right);
        }else {
        middle pivotIndex;
        pivotIndex = _partition(nums, left, right); 
        _quick_sort(nums, left, pivotIndex.mid1 - 1); 
        _quick_sort(nums, pivotIndex.mid2 + 1, right); }
    }
}

void QuickSort(vector<int>& nums) {
    _quick_sort(nums, 0, nums.size()-1);
}

int main() {
    int n;
    if(std::cin >> n) {
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            std::cin >> nums[i];
        }
        QuickSort(nums);
        for(int i = 0; i < n; i++) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
    
}
