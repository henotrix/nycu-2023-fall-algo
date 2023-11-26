#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 2'000'000'000;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  vector<vector<vector<int>>> dp(k + 1, vector(n, vector(m, -INF)));
  dp[0][0][0] = 0;
  for (int skip = 0; skip <= k; skip++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (i + 1 < n) {
          dp[skip][i + 1][j] =
              max(dp[skip][i + 1][j], dp[skip][i][j] + a[i + 1][j]);
          if (skip + 1 <= k)
            dp[skip + 1][i + 1][j] =
                max(dp[skip + 1][i + 1][j], dp[skip][i][j]);
        }
        if (j + 1 < m) {
          dp[skip][i][j + 1] =
              max(dp[skip][i][j + 1], dp[skip][i][j] + a[i][j + 1]);
          if (skip + 1 <= k)
            dp[skip + 1][i][j + 1] =
                max(dp[skip + 1][i][j + 1], dp[skip][i][j]);
        }
      }
  int ans = -INF;
  for (int i = 0; i <= k; i++)
    ans = max(ans, dp[i][n - 1][m - 1]);
  cout << ans << '\n';
}
