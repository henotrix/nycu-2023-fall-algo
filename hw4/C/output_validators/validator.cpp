#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll INF = 1e18;

ll readAns(InStream &stream, int n, vector<int> &a) {
  ll output = stream.readLong(-INF, INF, "output");
  vector<int> used(n);
  ll sum = 0;
  used[n - 1] = 1;
  for (int i = 1; i <= n - 1; i++) {
    int x = stream.readInteger(1, n - 1, "x_" + to_string(i));
    x--;
    if (used[x]) {
      stream.quitf(_wa, "same point use twice");
    }
    int l = x, r = x;
    while (l >= 0 && !used[l])
      l--;
    while (r < n && !used[r])
      r++;
    int lb = (l == -1 ? 0 : a[l]);
    int rb = a[r];
    int m = a[x];
    int cost = abs((m - lb) - (rb - m));
    sum += cost;
    used[x] = 1;
  }
  stream.ensuref(sum == output, "sum != claimed output");
  return output;
}

int main(int argc, char *argv[]) {
  registerTestlibCmd(argc, argv);
  int n = inf.readInt();
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    a[i] = inf.readInt();

  auto jans = readAns(ans, n, a);
  auto pans = readAns(ouf, n, a);
  if (jans == pans) {
    quitf(_ok, "AC");
  } else if (pans > jans) {
    quitf(_fail, "failed!");
  } else {
    quitf(_wa, "WA");
  }
}
