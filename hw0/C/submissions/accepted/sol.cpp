#include <iostream>
using namespace std;

int pow(int a, int b, int m) {
  int ret = 1 % m;
  while (b) {
    if (b & 1)
      ret = ret * 1LL * a % m;
    a = a * 1LL * a % m;
    b >>= 1;
  }
  return ret;
}

int main() {
  int a, b, m;
  cin >> a >> b >> m;
  cout << pow(a, b, m) << '\n';
}