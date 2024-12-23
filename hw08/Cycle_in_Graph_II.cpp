#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// struct element
// {
//     int state;
//     int t1;
//     int t2;
//     element(): state(0), t1(-1), t2(-1) {}
// };

vector<int> adj[1000001];
vector<int> visited;
stack<int> result;
bool hascycle = false;

void dfs(int u) {
    if(visited[u] > 0){
        return;
    }

    visited[u] = 1;  

    for (int v : adj[u]) {
        if(visited[v] == 1){
            hascycle = true;
            return;
        }else if(visited[v] == 0){
            dfs(v);
        }
    }

    visited[u] = 2;

    result.push(u);
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
    
    for (int i = 0; i < N; i++)
    {   
        if(!hascycle){
            dfs(i+1);
        }
    }
    
    if(hascycle){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
        while (!result.empty())
        {
            cout << result.top() << " ";
            result.pop();
        }
        cout << endl;
    }


    return 0;
}