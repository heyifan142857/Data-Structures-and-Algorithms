#include <iostream>
#include <vector>

using namespace std;

struct element
{
    bool discovered;
    int part;

    element(bool discovered): discovered(discovered), part(0) {}
};

vector<int> adj[1000001];
vector<element> visited;

bool dfs(int u, int part) {
    visited[u].discovered = true;  

    if (visited[u].part == 0) {
        visited[u].part = part;
    } else if (visited[u].part != part) {
        return false;  
    }

    for (int v : adj[u]) {
        if (!visited[v].discovered && !dfs(v, (part == 1 ? 2 : 1))) {
            return false; 
        }
        if(visited[v].part != (part == 1 ? 2 : 1)){
            return false; 
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(N + 1, element(false)); 
    bool isBipartite = dfs(1, 1);  

    if (isBipartite) {
        cout << "YES" << endl;

        for (int i = 1; i <= N; i++) {
            if (visited[i].part == 1) {
                cout << i << " ";
            }
        }
        cout << endl;

        for (int i = 1; i <= N; i++) {
            if (visited[i].part == 2) {
                cout << i << " ";
            }
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

