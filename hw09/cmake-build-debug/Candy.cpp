//
// Created by user on 2024/12/9.
//
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    vector<int> nums;
    int n;
    while (cin >> n) {
        nums.push_back(n);
    }
    if (nums.empty()) {
        cout << 0 << endl;
        return 0;
    }
    vector<bool> nums_status(nums.size(), false);
    int sum = 0;

    int candy = 0;

    while(sum < nums.size()) {
        int min_index = -1;
        int min = numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); i++) {
            if (!nums_status[i] && nums[i] < min) {
                min = nums[i];
                min_index = i;
            }
        }
        nums_status[min_index] = true;
        sum++;
        candy++;
        int _candy = 2;
        for (int i = min_index-1; i >= 0; i--) {
          if(nums_status[i]) {
            break;
          }
          if(nums[i] > nums[i+1]) {
            nums_status[i] = true;
            sum++;
            candy += _candy;
            _candy++;
          }else {
              break;
          }
        }

        _candy = 2;
        for (int i = min_index+1; i < nums.size(); i++) {
          if(nums_status[i]) {
            break;
          }
          if(nums[i] > nums[i-1]) {
            nums_status[i] = true;
            sum++;
            candy += _candy;
            _candy++;
          }else {
              break;
          }
        }
    }


    cout << candy << endl;


    return 0;
}