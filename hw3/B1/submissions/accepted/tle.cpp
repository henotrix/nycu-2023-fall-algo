#include <bits/stdc++.h>
using namespace std;

int main() {
  int q, k;
  cin >> q >> k;
  multiset<int> m;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      m.insert(x);
    } else {
      if (m.size() < k) {
        cout << -1 << '\n';
      } else {
        auto now = m.begin();
        for (int j = 0; j < k - 1; j++)
          now = next(now);
        cout << (*now) << '\n';
        m.erase(now);
      }
    }
  }
}
