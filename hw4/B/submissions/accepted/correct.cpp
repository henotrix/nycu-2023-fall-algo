#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 2'000'000'000;

int main() {
  int n, m;
  cin >> n >> m;
  vector a(n, vector(m, -INF));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  vector dp(n, vector(m, -INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (j > 0)
        dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);
      if (i > 0)
        dp[i][j] = max(dp[i][j], dp[i - 1][j] + 2 * a[i][j]);
      if (i > 0 && j > 0)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 4 * a[i][j]);
    }
  cout << dp[n - 1][m - 1] << '\n';
}
