#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void _dfs(int start,int cur, const vector<vector<int>> &adj, vector<vector<int>> &dists, vector<bool> &visited,int dist) {
    visited[cur] = true;
    dists[start][cur] = dist;
    dists[cur][start] = dist;

    for (int v : adj[cur]) {
        if (!visited[v]) {
            _dfs(start,v,adj,dists,visited,dist+1);
        }
    }
}

void dfs(int start, const vector<vector<int>> &adj, vector<vector<int>> &dists) {
    vector<bool> visited(adj.size(),false);
    _dfs(start,start,adj,dists,visited,0);
}

int main() {
#ifdef LOCAL:
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n);
    int u, v;
    while (cin >> u >> v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dists(n,vector<int>(n,-1));
    for(int i=0;i<n;i++) {
        dists[i][i] = 0;
    }

    vector<int> sum_dist(n,0);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (dists[i][j] == -1) {
                dfs(i,adj,dists);
            }
            sum_dist[i] = sum_dist[i] + dists[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        cout << sum_dist[i] << " ";
    }
    cout << endl;

    return 0;
}
