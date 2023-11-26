#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), sorted;
    for (int &i : a)
      cin >> i;
    sorted = a;
    sort(sorted.begin(), sorted.end());
    int l = -1, r = n - 1;
    while (r - l > 1) {
      // check if sorted[m] can win
      int m = (l + r) / 2;
      priority_queue<ll> pq;
      for (int i = 0; i < n; i++)
        if (i != m)
          pq.push(sorted[i]);
      while (pq.size() > 1) {
        ll e1 = pq.top();
        pq.pop();
        ll e2 = pq.top();
        pq.pop();
        pq.push(max(e1, e2) - k);
      }
      if (sorted[m] >= pq.top())
        r = m;
      else
        l = m;
    }
    for (int i = 0; i < n; i++)
      cout << (a[i] >= sorted[r] ? 1 : 0);
    cout << '\n';
  }
}
