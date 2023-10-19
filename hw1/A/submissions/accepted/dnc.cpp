#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

constexpr long long INF = 1'000'000'000'000'000'000LL;

tuple<long long, int, int> solve(int l, int r, vector<int> &a) {
  if (l == r) {
    return {a[l], l, r};
  } else {
    int m = (l + r) >> 1;
    auto lmax = solve(l, m, a);
    auto rmax = solve(m + 1, r, a);

    long long lmaxsum = -INF, rmaxsum = -INF, lsum = 0, rsum = 0;
    int lborder, rborder;
    for (int i = m; i >= l; i--) {
      lsum += a[i];
      if (lsum > lmaxsum) {
        lmaxsum = lsum;
        lborder = i;
      }
    }
    for (int i = m + 1; i <= r; i++) {
      rsum += a[i];
      if (rsum > rmaxsum) {
        rmaxsum = rsum;
        rborder = i;
      }
    }
    auto midmax = make_tuple(lmaxsum + rmaxsum, lborder, rborder);
    return max({lmax, rmax, midmax});
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;
  auto ret = solve(0, n - 1, a);
  cout << get<0>(ret) << '\n';
  cout << get<1>(ret) + 1 << ' ' << get<2>(ret) + 1 << '\n';
}
