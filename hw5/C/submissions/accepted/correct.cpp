#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs1(int u, vector<vector<int>> &G, vector<int> &visit,
          vector<int> &finish_time) {
  visit[u] = 1;
  for (int v : G[u])
    if (!visit[v])
      dfs1(v, G, visit, finish_time);
  finish_time.emplace_back(u);
}

void dfs2(int u, vector<vector<int>> &G, vector<int> &visit, int &count) {
  visit[u] = 1;
  count++;
  for (int v : G[u])
    if (!visit[v])
      dfs2(v, G, visit, count);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n), rG(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].emplace_back(v);
    rG[v].emplace_back(u);
  }
  // first dfs
  vector<int> finish_time, visit(n);
  for (int u = 0; u < n; u++)
    if (!visit[u])
      dfs1(u, rG, visit, finish_time);
  // second dfs
  visit = vector<int>(n, 0);
  reverse(finish_time.begin(), finish_time.end());
  int ans = 0;
  for (int u : finish_time)
    if (!visit[u]) {
      int count = 0;
      dfs2(u, G, visit, count);
      if (count == 1)
        ans++;
    }
  cout << ans << '\n';
}
