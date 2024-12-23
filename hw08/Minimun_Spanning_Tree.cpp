#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class UnionFind {
private:
    std::vector<int> parent;  
    std::vector<int> rank; 

public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }


    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX] += 1; 
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

struct edge
{
    int u;
    int v;
    int weight;

    edge(int u, int v, int weight): u(u), v(v), weight(weight){}
};

bool compare_edge(edge e1, edge e2){
    return e1.weight < e2.weight;
}


int main(){
    int N, M;
    cin >> N >> M;

    vector<edge> edges;
    UnionFind uf(N);

    for (int i = 0; i < M; i++)
    {
        int u,v,weight;
        cin >> u >> v >> weight;
        edges.push_back(edge(u, v, weight));
        uf.connected(u,v);
    }

    sort(edges.begin(),edges.end(),compare_edge);

    int totalweight = 0; 
    
    for (auto &e:edges){
        if(!uf.connected(e.u,e.v)){
            uf.unite(e.u,e.v);
            totalweight += e.weight;
        }
    }

    cout << totalweight << endl;

    return 0;
}