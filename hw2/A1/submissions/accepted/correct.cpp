#include <iostream>
#include <numeric>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, k;
    cin >> a >> b >> k;
    auto count = [&](long long x) { return x / a + x / b - x / lcm(a, b) * 2; };

    long long l = 0, r = 1'000'000'000'000'000'001LL;
    while (r - l > 1) {
      auto m = (l + r) / 2;
      if (count(m) < k)
        l = m;
      else
        r = m;
    }
    cout << r << '\n';
  }
}
