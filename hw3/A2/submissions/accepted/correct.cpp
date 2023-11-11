#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct entry {
  long long value;
  int row, column;
  entry(long long _v, int _r, int _c) : value(_v), row(_r), column(_c) {}
  bool operator>(const entry &rhs) const { return value > rhs.value; }
};

inline long long f(long long x, long long y) { return x * x + x * y + y * y; }

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  priority_queue<entry, vector<entry>, greater<>> pq;
  for (int i = 0; i < n; i++)
    pq.emplace(f(a[i], b[0]), i, 0);
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    auto [cur_value, cur_row, cur_column] = pq.top();
    pq.pop();
    if (cur_column + 1 < m)
      pq.emplace(f(a[cur_row], b[cur_column + 1]), cur_row, cur_column + 1);
    ans ^= cur_value;
  }
  cout << ans << '\n';
}
