//
// Created by user on 2024/12/9.
//
#include <iostream>
#include <vector>
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
  if (nums.empty()&&nums.size()==1) {
    cout << 1 << endl;
    return 0;
  }
  int p = 1;
  int times = 0;
  while (p < nums.size()) {
    if(p+nums[p-1] >= nums.size()) {
      break;
    }else{
      times++;
      int largest = -1;
      int index = -1;
      for(int i = p+1; i <= p+nums[p-1]; i++) {
        if (i+nums[i-1] >= nums.size()) {
          index = i;
          break;
        }
        if (i+nums[i-1] >= largest) {
          largest = i+nums[i-1];
          index = i;
        }
      }
      p = index;
    }
  }
  cout << times+1 << endl;
  return 0;
}