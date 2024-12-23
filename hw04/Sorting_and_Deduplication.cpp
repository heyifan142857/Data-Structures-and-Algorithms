#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue> 
using namespace std;

void read_nums(vector<int>& nums) {
    int n;
    bool numbers[100000000];
    
    while(scanf("%d", &n) != EOF) {
        if(numbers[n] == false){
        numbers[n] = true;
        nums.push_back(n);
        }
    }
}



void radixSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int max_val = *std::max_element(arr.begin(), arr.end());
    int exp = 1; 

    std::vector<int> output(arr.size());
    std::vector<int> count(10, 0);

    while (max_val / exp > 0) {
        for (int num : arr) {
            ++count[(num / exp) % 10];
        }

        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }

        for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
            output[--count[(*it / exp) % 10]] = *it;
        }

        arr = output;
        std::fill(count.begin(), count.end(), 0);
        exp *= 10;
    }
}



int main() {
    vector<int> nums;
    //read_nums(nums);
    //radixSort(nums);
    //sort(nums.begin(), nums.end());
    //QuickSort(nums);
    int n;
    vector<bool> numbers(100000000,false);
    while(scanf("%d", &n) != EOF) {
        if(!numbers[n]){
        numbers[n] = true;
        }
    }
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");
    
    return 0;
    
}


