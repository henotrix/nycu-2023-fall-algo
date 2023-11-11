#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

inline long long f(long long x, long long y) { return x * x + x * y + y * y; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  long long l = 1, r = 4e18;
  auto count = [&](long long x) {
    long long ret = 0;
    for (int i = 0; i < n; i++) {
      if (f(a[i], b[0]) > x) {
        continue;
      } else if (f(a[i], b[m - 1]) <= x) {
        ret += m;
        continue;
      }
      int L = 0, R = m - 1;
      while (R - L > 1) {
        int M = (L + R) >> 1;
        if (f(a[i], b[M]) <= x)
          L = M;
        else
          R = M;
      }
      ret += (L + 1);
    }
    return ret;
  };
  while (r - l > 1) {
    auto m = (l + r) >> 1;
    if (count(m) >= k)
      r = m;
    else
      l = m;
  }
  vector<long long> ans;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (f(a[i], b[j]) < r)
        ans.emplace_back(f(a[i], b[j]));
      else
        break;
    }
  while (ans.size() < k)
    ans.emplace_back(r);
  sort(ans.begin(), ans.end());
  for (int i = 0; i < k; i++)
    cout << ans[i] << " \n"[i == k - 1];
}
