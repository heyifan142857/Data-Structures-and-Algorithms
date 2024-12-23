#include <iostream>
#include <vector>

class UnionFind {
private:
    std::vector<int> parent;  
    std::vector<int> rank; 

public:
    UnionFind(int n) : parent(n+1), rank(n+1, 0) {
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

int main() {
    int N;
    int M;
    std::cin >> N >> M;
    UnionFind uf(M);

    for (int i = 0; i < N; i++)
    {
        int op;
        std::cin >> op;
        int n1,n2;
        std::cin >> n1 >> n2;
        if(op == 1){           
            uf.unite(n1,n2);
        }else{
            if(uf.connected(n1,n2)){
                std::cout << 1 << std::endl;
            }else{
                std::cout << 0 << std::endl;
            }
        }
    }
    return 0;

}
