#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1000001]; 
vector<int> visited;     

bool dfs(int u) {
    if (visited[u] == 1)  
        return true;
    if (visited[u] == 2)  
        return false;
    
    visited[u] = 1;  

    for (int v : adj[u]) {
        if (dfs(v))  
            return true;
    }

    visited[u] = 2; 
    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    visited.assign(N + 1, 0); 

    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            if (dfs(i)) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
