#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

constexpr int MAXK = 5;

struct segtree {
  int n;
  vector<vector<int>> node;
  vector<int> a;

  void init(int _n, vector<int> _a) {
    n = _n;
    node.resize((n << 2) + 1);
    for (int i = 0; i <= (n << 2); i++)
      node[i].clear();
    a = _a;
    build(1, 1, n);
  }

  void merge_vectors(vector<int> &a, vector<int> &b, vector<int> &out) {
    out.clear();
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(out));
    if (out.size() > MAXK)
      out.resize(MAXK);
  }

  void build(int now, int l, int r) {
    if (l == r) {
      node[now] = {a[l - 1]};
      return;
    }
    int m = (l + r) >> 1;
    build(now << 1, l, m);
    build(now << 1 | 1, m + 1, r);
    merge_vectors(node[now << 1], node[now << 1 | 1], node[now]);
  }

  void modify_(int now, int l, int r, int x, int v) {
    if (l == r) {
      node[now] = {v};
      return;
    }
    int m = (l + r) >> 1;
    if (x <= m)
      modify_(now << 1, l, m, x, v);
    else
      modify_(now << 1 | 1, m + 1, r, x, v);
    merge_vectors(node[now << 1], node[now << 1 | 1], node[now]);
  }

  vector<int> query_(int now, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr)
      return node[now];
    int m = (l + r) >> 1;
    if (qr <= m)
      return query_(now << 1, l, m, ql, qr);
    else if (ql > m)
      return query_(now << 1 | 1, m + 1, r, ql, qr);
    else {
      auto lmin = query_(now << 1, l, m, ql, qr);
      auto rmin = query_(now << 1 | 1, m + 1, r, ql, qr);
      vector<int> ret;
      merge_vectors(lmin, rmin, ret);
      return ret;
    }
  }

  void modify(int x, int v) { modify_(1, 1, n, x, v); }

  int query(int l, int r, int k) {
    auto mins = query_(1, 1, n, l, r);
    return mins[k - 1];
  }
} tree;

vector<vector<int>> node;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;

  tree.init(n, a);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, v;
      cin >> x >> v;
      tree.modify(x, v);
    } else {
      int l, r, k;
      cin >> l >> r >> k;
      cout << tree.query(l, r, k) << '\n';
    }
  }
}
