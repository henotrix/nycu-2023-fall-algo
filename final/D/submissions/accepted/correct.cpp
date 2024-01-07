#include <iostream>
#include <vector>
using namespace std;

void solve(int u, int p, vector<vector<long long>> &dp, vector<int> &a,
           vector<vector<int>> &G) {
  long long sum0 = 0, sum1 = 0;
  for (int v : G[u])
    if (v != p) {
      solve(v, u, dp, a, G);
      sum0 += max(dp[v][0], dp[v][1]);
      sum1 += dp[v][0];
    }
  dp[u][0] = sum0;
  dp[u][1] = sum1 + a[u];
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<long long>> dp(n, vector<long long>(2));
  vector<vector<int>> G(n);
  for (int &i : a)
    cin >> i;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  solve(0, -1, dp, a, G);
  cout << max(dp[0][0], dp[0][1]) << '\n';
}
