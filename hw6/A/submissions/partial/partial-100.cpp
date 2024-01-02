#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll INF = 1'000'000'000'000'000'000LL;

struct edge {
  int u, v, w, c;
  edge(int _u, int _v, int _w, int _c) : u(_u), v(_v), w(_w), c(_c) {}
  bool operator<(const edge &rhs) const { return w < rhs.w; }
};

struct DSU {
  vector<int> p, sz;

  void reset(int n) {
    p.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++)
      p[i] = i, sz[i] = 1;
  }

  int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }

  bool Same(int x, int y) { return Find(x) == Find(y); }

  void Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y)
      return;
    if (sz[x] > sz[y])
      swap(x, y);
    sz[y] += sz[x], p[x] = y;
  }
} dsu;

ll run_kruskal(int n, vector<edge> &edges) {
  dsu.reset(n);
  ll ret = 0;
  vector<edge> new_edges;
  for (auto [u, v, w, c] : edges) {
    if (!dsu.Same(u, v)) {
      ret += w;
      new_edges.emplace_back(u, v, w, c);
      dsu.Union(u, v);
    }
  }
  edges.swap(new_edges);
  return ((int)edges.size() == n - 1 ? ret : INF);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> p(k);
  vector<int> u(m), v(m), w(m), c(m);
  vector<edge> edges;
  vector<ll> sum1(1 << k), sum2(1 << k);
  for (int &i : p)
    cin >> i;
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> w[i] >> c[i];
    u[i]--, v[i]--, c[i]--;
    edges.push_back(edge(u[i], v[i], w[i], c[i]));
  }
  sort(edges.begin(), edges.end());
  for (int i = 0; i < (1 << k); i++) {
    vector<edge> cur_edges;
    for (auto [u, v, w, c] : edges) {
      if ((i >> c) & 1)
        cur_edges.emplace_back(u, v, w, c);
    }
    sum1[i] = run_kruskal(n, cur_edges);
  }
  for (int i = 1; i < (1 << k); i++) {
    for (int j = 0; j < k; j++)
      if ((i >> j) & 1)
        sum2[i] += p[j];
  }
  ll ans = INF;
  for (int i = 1; i < (1 << k); i++)
    ans = min(ans, sum1[i] + sum2[i]);
  cout << ans << '\n';
}
// 4 6 3
// 1 1 100000
// 1 2 1 1
// 2 3 1 1
// 1 3 1 2
// 2 4 1 2
// 1 4 1 3
// 3 4 1 3