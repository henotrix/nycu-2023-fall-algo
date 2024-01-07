#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, int p, vector<int> &dist, vector<vector<int>> &G) {
  for (int v : G[u])
    if (v != p) {
      dist[v] = dist[u] + 1;
      dfs(v, u, dist, G);
    }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> G(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  vector<int> dist(n, -1);
  dist[0] = 0;
  dfs(0, -1, dist, G);
  int v = max_element(dist.begin(), dist.end()) - dist.begin();
  dist = vector<int>(n, -1);
  dist[v] = 0;
  dfs(v, -1, dist, G);
  cout << *max_element(dist.begin(), dist.end()) << '\n';
}
