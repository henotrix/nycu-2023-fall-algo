#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
constexpr ll INFF = 1e18;

void dfs(int u, vector<vector<int>> &G, vector<int> &topo,
         vector<int> &visited) {
  visited[u] = 1;
  for (int v : G[u]) {
    if (!visited[v])
      dfs(v, G, topo, visited);
  }
  topo.emplace_back(u);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  vector<int> a(n);
  for (int &i : a)
    cin >> i;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].emplace_back(v);
  }
  // get (reverse) topological sort order
  vector<int> topo, visited(n);
  for (int u = 0; u < n; u++)
    if (!visited[u])
      dfs(u, G, topo, visited);
  // DP
  ll ans = -INFF;
  vector<ll> dp(n, -INFF);
  for (int u : topo) {
    dp[u] = a[u];
    for (int v : G[u]) {
      assert(dp[v] != -INFF);
      dp[u] = max(dp[u], dp[v] + a[u]);
    }
    ans = max(ans, dp[u]);
  }
  cout << ans << '\n';
}
