#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

inline long long f(long long x, long long y) { return x * x + x * y + y * y; }

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  vector<long long> v;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      v.emplace_back(f(a[i], b[j]));
  sort(v.begin(), v.end());
  for (int i = 0; i < k; i++) {
    cout << v[i];
    if (i == k - 1)
      cout << '\n';
    else
      cout << ' ';
  }
}
