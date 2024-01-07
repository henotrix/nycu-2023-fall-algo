#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
constexpr ll MOD = 1'000'000'007;
constexpr ll MAXD = 1e18;

int main() {
  int n, m, type;
  cin >> n >> m >> type;
  vector<vector<pii>> G(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }

  vector<ll> dist(n, MAXD), dp(n, 0);
  priority_queue<pli, vector<pli>, greater<>> pq;
  dist[0] = 0, dp[0] = 1;
  pq.emplace(dist[0], 0);
  while (!pq.empty()) {
    auto [distu, u] = pq.top();
    pq.pop();
    if (dist[u] != distu) {
      continue;
    }
    cerr << u << endl;
    for (auto [v, w] : G[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        dp[v] = dp[u];
        pq.emplace(dist[v], v);
      } else if (dist[v] == dist[u] + w) {
        dp[v] = (dp[v] + dp[u]) % MOD;
      }
    }
  }
  if (type == 1)
    cout << (dist[1] == MAXD ? -1 : dist[1]) << '\n';
  else
    cout << (dist[1] == MAXD ? -1 : dp[1]) << '\n';
}