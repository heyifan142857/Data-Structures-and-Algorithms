#include <iostream>
#include <queue>
#include <vector>
#include <limits>

struct Node
{
    int value;
    std::vector<int> neighbors;
    int dist;
    bool discovered;

    Node(int value):value(value), dist(std::numeric_limits<int>::max()), discovered(false){};
};

int main(){
    int N, M;
    std::cin>> N >> M;
    std::vector<Node*> v;
    for (int i = 1; i < N+1; i++)
    {
        Node* newNode = new Node(i);
        v.push_back(newNode);
    }
    int x, y;
    for (int i = 0; i < M; i++)
    {
        std::cin >> x >> y;
        v[x-1]->neighbors.push_back(y);
        v[y-1]->neighbors.push_back(x);
    }
    
    v[0]->dist = 0;
    v[0]->discovered = true;
    std::queue<Node*> Q;
    Q.push(v[0]);

    while (!Q.empty())
    {
        Node* u = Q.front();
        Q.pop();
        for (int i = 0; i < u->neighbors.size(); i++)
        {
            if(!v[u->neighbors[i]-1]->discovered){
                v[u->neighbors[i]-1]->dist = u->dist + 1;
                v[u->neighbors[i]-1]->discovered = true;
                Q.push(v[u->neighbors[i]-1]);
            }
        }
    }

    for (int i = 1; i < v.size(); i++)
    {   
        if(v[i]->discovered == false){
            std::cout << -1 << " ";
        }else{
            std::cout << v[i]->dist << " ";
        }
    }
    std::cout << std::endl; 
        

    return 0;
}
