// Perform DFS from vertex 0
// Assume undirected graph
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>> &G, vector<int> &visited) {
  visited[u] = 1;
  for (int v : G[u])
    if (!visited[v])
      dfs(v, G, visited);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  vector<int> visited(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, G, visited);
}