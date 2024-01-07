#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct DSU {
  int n;
  vector<int> p, size;
  void init(int n_) {
    n = n_;
    p.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
      size[i] = 1;
    }
  }
  int find(int u) { return p[u] == u ? u : p[u] = find(p[u]); }
  void add_edge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return;
    if (size[u] > size[v])
      swap(u, v);
    size[v] += size[u];
    p[u] = v;
  }
  int get_size(int u) { return size[find(u)]; }
} dsu;

int main() {
  int n, q;
  cin >> n >> q;
  dsu.init(n);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) { // add edge
      int u, v;
      cin >> u >> v;
      u--, v--;
      dsu.add_edge(u, v);
    } else if (type == 2) { // get count
      int u;
      cin >> u;
      u--;
      cout << dsu.get_size(u) << '\n';
    }
  }
}
