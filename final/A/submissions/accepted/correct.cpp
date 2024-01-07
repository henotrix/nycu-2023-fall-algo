#include <iostream>
#include <vector>
using namespace std;

constexpr long long INF = 1'000'000'000'000'000'000LL;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;
  long long ans = -INF, sum = 0;
  int ansl, ansr, curl = 0;
  for (int i = 0; i < n; i++) {
    if (sum + a[i] > ans) {
      ans = sum + a[i];
      ansl = curl + 1;
      ansr = i + 1;
    }
    sum += a[i];
    if (sum <= 0) {
      sum = 0;
      curl = i + 1;
    }
  }
  cout << ans << '\n';
}
