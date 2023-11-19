#include <iostream>
#include <vector>
using namespace std;

constexpr long long INF = 1'000'000'000'000'000'000LL;

void get_solution_recursive(int l, int r, vector<vector<int>> &from,
                            vector<int> &ans) {
  if (l + 1 == r)
    return;
  int m = from[l][r];
  ans.emplace_back(m);
  get_solution_recursive(l, m, from, ans);
  get_solution_recursive(m, r, from, ans);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  vector dp(n + 1, vector(n + 1, INF));
  vector from(n + 1, vector(n + 1, 0));
  for (int i = 0; i + 1 <= n; i++)
    dp[i][i + 1] = 0;
  for (int len = 2; len <= n + 1; len++) {
    for (int l = 0; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      for (int m = l + 1; m <= r - 1; m++) {
        auto current_cut_cost = abs((a[m] - a[l]) - (a[r] - a[m]));
        auto current_cost = dp[l][m] + dp[m][r] + current_cut_cost;
        if (current_cost < dp[l][r]) {
          dp[l][r] = current_cost;
          from[l][r] = m;
        }
      }
    }
  }
  cout << dp[0][n] << '\n';
  vector<int> ans;
  get_solution_recursive(0, n, from, ans);
  for (int i = 0; i < n - 1; i++) {
    cout << ans[i];
    if (i + 1 == n - 1)
      cout << '\n';
    else
      cout << ' ';
  }
}
