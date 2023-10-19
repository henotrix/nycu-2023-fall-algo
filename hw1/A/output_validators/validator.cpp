#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll INF = 1e18;

ll readAns(InStream &stream, int n, vector<int> &a) {
  ll output = stream.readLong(-INF, INF, "output");
  int l = stream.readInt(1, n, "l");
  int r = stream.readInt(l, n, "r");
  ll sum = 0;
  for (int i = l - 1; i < r; i++) {
    sum += a[i];
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
