#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;
constexpr int MAXN = 5002;
constexpr ll INF = 1e12;
#define sz(v) (int)((v).size())

struct DinicFlow {
  int n, s, t;
  struct Edge {
    ll to, cap, rev;
  };
  vector<Edge> edg[MAXN];
  void init(int _n, int _s, int _t) {
    for (int i = 0; _n > i; i++) {
      edg[i].clear();
    }
    n = _n;
    s = _s;
    t = _t;
  }
  void add_edge(int from, int to, ll cap) {
    edg[from].push_back({to, cap, sz(edg[to])});
    edg[to].push_back({from, 0, sz(edg[from]) - 1});
  }
  int level[MAXN], iter[MAXN];
  void bfs(int s) {
    queue<int> que;
    que.push(s);
    for (int i = 0; i < n; i++)
      level[i] = -1;
    level[s] = 0;
    while (!que.empty()) {
      int t = que.front();
      que.pop();
      for (Edge e : edg[t]) {
        if (e.cap > 0 && level[e.to] == -1) {
          level[e.to] = level[t] + 1;
          que.push(e.to);
        }
      }
    }
  }
  ll dfs(int id, ll flow) {
    if (id == t)
      return flow;
    for (int &i = iter[id]; sz(edg[id]) > i; i++) {
      Edge &e = edg[id][i];
      if (e.cap > 0 && level[e.to] == level[id] + 1) {
        ll ret = dfs(e.to, min(flow, e.cap));
        if (ret > 0) {
          e.cap -= ret;
          edg[e.to][e.rev].cap += ret;
          return ret;
        }
      }
    }
    return 0;
  }
  ll flow() {
    ll ret = 0;
    while (true) {
      bfs(s);
      if (level[t] == -1)
        return ret;
      ll tmp = 0;
      for (int i = 0; i < n; i++)
        iter[i] = 0;
      while ((tmp = dfs(s, INF)) > 0) {
        ret += tmp;
      }
    }
    return ret;
  }
} f;

int main() {
  int n, m;
  cin >> n >> m;
  f.init(m + n + 2, 0, m + n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    f.add_edge(m + i, m + n + 1, x);
  }
  for (int i = 1; i <= m; i++) {
    int x, y, d;
    cin >> x >> y >> d;
    f.add_edge(0, i, d);
    ans += d;
    f.add_edge(i, m + x, INF);
    f.add_edge(i, m + y, INF);
  }
  cout << ans - f.flow() << endl;
}