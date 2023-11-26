#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

struct segtree {
  int n;
  vector<int> mx;

  void init(int _n) {
    n = _n;
    mx.resize(4 * _n);
  }
  void modify_(int now, int l, int r, int x, int v) {
    if (l == r) {
      mx[now] = v;
      return;
    }
    int m = (l + r) >> 1;
    if (x <= m)
      modify_(now << 1, l, m, x, v);
    else
      modify_(now << 1 | 1, m + 1, r, x, v);
    mx[now] = max(mx[now << 1], mx[now << 1 | 1]);
  }
  int query_(int now, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr)
      return mx[now];
    int m = (l + r) >> 1;
    if (qr <= m)
      return query_(now << 1, l, m, ql, qr);
    if (ql > m)
      return query_(now << 1 | 1, m + 1, r, ql, qr);
    return max(query_(now << 1, l, m, ql, qr),
               query_(now << 1 | 1, m + 1, r, ql, qr));
  }
  void modify(int x, int v) { modify_(1, 1, n, x, v); }
  int query(int l, int r) { return query_(1, 1, n, l, r); }
} segtree;

int main() {
  int n, q;
  cin >> n >> q;
  segtree.init(n);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    segtree.modify(i, x);
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, v;
      cin >> x >> v;
      segtree.modify(x, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << segtree.query(l, r) << '\n';
    }
  }
}