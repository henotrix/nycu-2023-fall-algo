#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 把線段依照右界由小到大排序以後，對於每條線段，去找那條線段包含的點中座標最小的那個。
// 可以證明說如果答案是 Yes，則這種配對方法一定會配對成功。
// 證明：我們假設存在一種配對方式。
// 考慮左界最小的線段 [l, r]。假設這條線段不是配對區間內第一個點
// x1，而是去配對其他點 x2。 我們去找出配對到 x1 的區間 [l', r']，則可以發現
// l' <= x1 且 r' >= r，所以拿 [l, r] 去配 x1，[l', r'] 去配 x2
// 也是一種合法的配對方法。所以我們證明了，若存在一種配對方式，則一定存在一種配對方式使得右界最小的線段配區間內最左邊的點。
// 因此我們就得到了一個 greedy 的作法。

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    multiset<int> s;
    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s.insert(x);
    }
    for (auto &[l, r] : t)
      cin >> l >> r;
    sort(t.begin(), t.end(), [](pair<int, int> x, pair<int, int> y) {
      if (x.second != y.second)
        return x.second < y.second;
      else
        return x.first < y.first;
    });
    bool ok = true;
    for (int i = 0; i < n; i++) {
      auto point = s.lower_bound(t[i].first);
      if (point == s.end() || (*point) > t[i].second)
        ok = false;
      if (point != s.end())
        s.erase(point);
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}
