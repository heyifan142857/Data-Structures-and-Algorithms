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
      if(dist[v] > dist[u] + matrix[u][v]){
        dist[v] = dist[u] + matrix[u][v];
        pq.push(make_pair(dist[v],v));
      }
    }
  }
  return dist[end];
}

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> routine;
  for(int i=0;i<M;i++){
    int number;
    cin>>number;
    routine.push_back(number);
    routine[i]--;
  }
  vector<vector<int> > matrix(N,vector<int>(N,0));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>matrix[i][j];
    }
  }

  int sum=0;

  int p = 0;
  for(int i=0;i<M;i++){
    sum += Dijkstra(p,routine[i],N,matrix);
    p = routine[i];
  }

  cout<<sum<<endl;

  return 0;
}