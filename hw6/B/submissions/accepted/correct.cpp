#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;
constexpr ll INF = 1e18;

struct edge {
  int u, v, w;
};

struct dist {
  ll d;
  int v;
  bool operator>(const dist &rhs) const { return d > rhs.d; }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<edge>> G(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    G[u].push_back({u, v, w});
  }
  for (int i = 0; i < n; i++)
    G[n].push_back({n, i, 0});
  // Bellman ford
  vector<ll> height(n + 1, INF);
  height[n] = 0;
  bool have_negative_cycle = 0;
  for (int i = 0; i <= n; i++) {
    vector<ll> new_height = height;
    bool updated = 0;
    for (int u = 0; u <= n; u++) {
      for (auto [u, v, w] : G[u])
        if (height[v] > height[u] + w) {
          updated = true;
          new_height[v] = height[u] + w;
        }
    }
    height = new_height;
    if (i == n && updated) {
      have_negative_cycle = true;
    }
  }
  if (have_negative_cycle) {
    cout << "Negative-weight cycle found\n";
    return 0;
  }
  // Dijkstra
  for (int i = 0; i < n; i++)
    for (auto &[u, v, w] : G[i])
      w += (height[u] - height[v]);
  ll ans = 0;
  for (int u = 0; u < n; u++) {
    vector<ll> d(n, INF);
    d[u] = 0;
    priority_queue<dist, vector<dist>, greater<>> pq;
    pq.push({d[u], u});
    while (!pq.empty()) {
      auto [du, u] = pq.top();
      pq.pop();
      if (du != d[u])
        continue;
      for (auto [u, v, w] : G[u]) {
        if (d[v] > d[u] + w) {
          d[v] = d[u] + w;
          pq.push({d[v], v});
        }
      }
    }
    for (int v = 0; v < n; v++)
      if (d[v] != INF)
        ans += (d[v] + height[v] - height[u]);
  }
  cout << ans << '\n';
}
