// Finding the single source shortest paths from vertex 0 (0-indexed)
// Assume undirected graph
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<int> dist(n, -1);
  queue<int> q;
  dist[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : G[u])
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
  }
  // dist stores the shortest distance from vertex 0
}