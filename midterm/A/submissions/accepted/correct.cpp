#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int &i : a)
    cin >> i;
  for (int &i : b)
    cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += a[i] * b[i];
  cout << ans << '\n';
}
