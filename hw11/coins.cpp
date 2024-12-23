//
// Created by user on 2024/12/23.
//
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


// int _ways(vector<int> &coins, int a, vector<int> &counts) {
//     if (a<0) {
//         return 0;
//     }
//
//     if (a==0) {
//         return 1;
//     }
//
//     if (counts[a] > 0) {
//         return counts[a];
//     }
//
//     int res = 0;
//     for (int i = 0; i < coins.size(); i++) {
//         res += _ways(coins, a - coins[i], counts);
//     }
//     counts[a] = res;
//     return res;
// }
//
// int ways(vector<int> &coins, int a) {
//     vector<int> counts(a + 1, INT_MIN);
//     return _ways(coins,a,counts);
// }
//
//
// int main() {
// #ifdef LOCAL:
//     freopen("data.in", "r", stdin);
//     freopen("data.out", "w", stdout);
// #endif
//     int a;
//     cin >> a;
//     vector<int> coins;
//
//     int n;
//     while (cin >> n) {
//         coins.push_back(n);
//     }
//
//     cout << ways(coins, a) << endl;
//
//     return 0;
//
// }

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int ways(vector<int> &coins, int a) {
    // dp[i] 表示凑成金额 i 的组合数
    vector<int> dp(a + 1, 0);
    dp[0] = 1; // 凑成金额 0 的方式只有一种，即不使用任何硬币

    // 遍历每种硬币
    for (int coin : coins) {
        // 遍历从 coin 到 a 的每一个金额，更新 dp 数组
        for (int amount = coin; amount <= a; amount++) {
            dp[amount] += dp[amount - coin];  // 递推公式
        }
    }

    return dp[a];  // 返回凑成金额 a 的组合数
}

int main() {
    #ifdef LOCAL:
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    int a;
    cin >> a;
    vector<int> coins;

    int n;
    while (cin >> n) {
        coins.push_back(n);
    }

    // 输出结果
    cout << ways(coins, a) << endl;

    return 0;
}
