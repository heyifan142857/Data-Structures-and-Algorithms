//
// Created by user on 2024/12/23.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef LOCAL:
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int n;
    vector<int> arr;
    int sum = 0;

    // 输入数组并计算总和
    while (cin >> n) {
        arr.push_back(n);
        sum += n;
    }

    // 如果总和为奇数，无法分成两个和相等的子集
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int target = sum / 2;

    // dp[j] 表示是否存在一个子集，和为 j
    vector<bool> dp(target + 1, false);
    dp[0] = true;  // 和为 0 总是可以通过选择空子集得到

    // 动态规划求解
    for (int num : arr) {
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    // 如果 dp[target] 为 true，则可以将数组分成两个和相等的子集
    if (dp[target]) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
