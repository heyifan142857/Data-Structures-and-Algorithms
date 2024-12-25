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

    int size = nums.size();
    vector<int> candies(size, 1);

    for (int i = 1; i < size; i++) {
        if (nums[i] > nums[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = size - 2; i >= 0; i--) {
        if (nums[i] > nums[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int total_candies = 0;
    for (int i = 0; i < size; i++) {
        total_candies += candies[i];
    }

    cout << total_candies << endl;

    return 0;
}
