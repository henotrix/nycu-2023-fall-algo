#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long calculate(int l, int r, vector<int> &a) {
  if (l + 1 == r) {
    return 0;
  }
  int m = (l + r) >> 1;
  long long ret = calculate(l, m, a) + calculate(m, r, a);
  int ptl = l;
  for (int i = m; i < r; i++) {
    while (ptl < m && a[ptl] < a[i])
      ptl++;
    ret += (m - ptl);
  }
  inplace_merge(a.begin() + l, a.begin() + m, a.begin() + r);
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  cout << calculate(0, n, a) << '\n';
}
