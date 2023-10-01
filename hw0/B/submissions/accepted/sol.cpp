#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i == n - 1)
      cout << '\n';
    else
      cout << ' ';
  }
}