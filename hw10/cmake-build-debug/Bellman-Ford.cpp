//
// Created by user on 2024/12/15.
//
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

bool Bellman(int N, const vector<vector<int>> &matrix){
  vector<int> dist(N, INT_MAX);
  dist[0] = 0;
  for(int i = 0; i < N-1; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < N; k++){
        if(matrix[j][k] != INT_MAX && dist[j] != INT_MAX && dist[k]>matrix[j][k]+dist[j]){
          dist[k] = matrix[j][k]+dist[j];
        }
      }
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(matrix[i][j] != INT_MAX && dist[i] != INT_MAX && dist[j] > dist[i] + matrix[i][j]){
        return true;
      }
    }
  }
  return false;
}

int main() {
  int F;
  cin >> F;
  for (int i = 0; i < F; i++) {
    int N, M, W;
    cin >> N >> M >> W;
    vector<vector<int> > matrix(N, vector<int>(N, INT_MAX));
    for (int j = 0; j < N; j++) {
      matrix[j][j] = 0;
    }
    for (int j = 0; j < M; j++) {
      int S, E, T;
      cin >> S >> E >> T;
      matrix[S-1][E-1] = min(matrix[S-1][E-1], T);
      matrix[E-1][S-1] = min(matrix[E-1][S-1], T);
    }
    for (int j = 0; j < W; j++) {
      int S, E, T;
      cin >> S >> E >> T;
      matrix[S-1][E-1] = min(matrix[S-1][E-1], -T);
    }
    if (Bellman(N, matrix)) {
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }

  return 0;
}