//
// Created by user on 2024/12/15.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int Dijkstra(int start,int end, int N, vector<vector<int> > matrix){
    if(start==end){
        return 0;
    }
    vector<int> dist(N, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(dist[u] < d){
            continue;
        }
        for(int v = 0; v < N; v++){
            if(u == v){continue;}
            if(matrix[u][v] == -1){
              continue;
            }
            if(dist[v] > dist[u] + matrix[u][v]){
                dist[v] = dist[u] + matrix[u][v];
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    return dist[end];
}

int main(){
    int n, m, s, t;
    cin>>n>>m>>s>>t;
    vector<vector<int>> matrix(n, vector<int>(n,-1));
    for(int i = 0; i < m; i++){
      int u, v, w;
      cin>>u>>v>>w;
      matrix[u][v] = w;
      matrix[v][u] = w;
    }

    cout<<Dijkstra(s,t,n,matrix)<<endl;

    return 0;
}