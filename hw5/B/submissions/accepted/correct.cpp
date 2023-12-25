#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct DSU {
  int n;
  vector<int> p, size, count;
  void init(int n_, vector<int> &color_) {
    n = n_;
    p.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      size[i] = 1;
    }
    count = color_;
  }
  int find(int u) { return p[u] == u ? u : p[u] = find(p[u]); }
  void add_edge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return;
    if (size[u] > size[v])
      swap(u, v);
    size[v] += size[u];
    count[v] += count[u];
    p[u] = v;
  }
  int get_count(int u) {
    u = find(u);
    return count[u];
  }
} dsu;

struct Graph {
  int n;
  vector<vector<int>> G;
  vector<int> color;
  void init(int n_, vector<int> &color_) {
    n = n_;
    G.resize(n);
    color = color_;
  }
  void add_edge(int u, int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  int bfs(int u) {
    const int INF = n + 1;
    vector<int> dist(n, INF);
    queue<int> qu;
    dist[u] = 0;
    qu.push(u);
    while (!qu.empty()) {
      int u_ = qu.front();
      qu.pop();
      for (int v : G[u_])
        if (dist[v] == INF) {
          dist[v] = dist[u_] + 1;
          qu.push(v);
        }
    }
    int ret = INF;
    for (int i = 0; i < n; i++)
      if (color[i])
        ret = min(ret, dist[i]);
    if (ret == INF)
      return -1;
    else
      return ret;
  }
} g;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> color(n);
  for (int i = 0; i < n; i++)
    cin >> color[i];
  dsu.init(n, color);
  g.init(n, color);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) { // add edge
      int u, v;
      cin >> u >> v;
      u--, v--;
      dsu.add_edge(u, v);
      g.add_edge(u, v);
    } else if (type == 2) { // get count
      int u;
      cin >> u;
      u--;
      cout << dsu.get_count(u) << '\n';
    } else { // get nearest
      int u;
      cin >> u;
      u--;
      cout << g.bfs(u) << '\n';
    }
  }
}
