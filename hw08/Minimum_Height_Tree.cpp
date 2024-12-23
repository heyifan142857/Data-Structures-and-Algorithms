#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int MAXN = 1000001;
vector<int> adj[MAXN];

int dfs(int u, vector<int>& visited, int height) {
    visited[u] = 1;
    int maxHeight = height;

    for (int v : adj[u]) {
        if (visited[v] == 0) {
            int newHeight = dfs(v, visited, height + 1);
            maxHeight = max(maxHeight, newHeight);
        }
    }

    return maxHeight;
}

int main() {
    int N;
    cin >> N;

    int u, v;
    while (cin >> u) {
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int minMaxHeight = numeric_limits<int>::max();
    vector<int> visited(N + 1, 0);

    for (int i = 0; i < N; i++) {
        fill(visited.begin(), visited.end(), 0);
        int maxHeight = dfs(i, visited, 0);
        minMaxHeight = min(minMaxHeight, maxHeight);
    }

    cout << minMaxHeight << endl;

    return 0;
}