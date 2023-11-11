#include <iostream>
#include <queue>
using namespace std;

int main() {
  int q, k;
  cin >> q >> k;
  priority_queue<int> small;
  priority_queue<int, vector<int>, greater<>> large;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      if (small.size() < k || x <= small.top())
        small.push(x);
      else
        large.push(x);
      if (small.size() > k) {
        large.push(small.top());
        small.pop();
      }
    } else {
      if (small.size() < k) {
        cout << -1 << '\n';
        continue;
      }
      cout << small.top() << '\n';
      small.pop();
      if (!large.empty()) {
        small.push(large.top());
        large.pop();
      }
    }
  }
}
