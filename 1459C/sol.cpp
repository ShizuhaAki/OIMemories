// Problem: C. Row GCD
// Contest: Codeforces - Codeforces Round #691 (Div. 2)
// URL: https://codeforces.com/contest/1459/problem/C
// Written by RavenclawOIer on 12-19-2020

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ttt template <typename T>
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
const int INF = 0x3f3f3f3f;
ttt inline void rd(T& x) {
  x = 0;
  T neg = 1;
  char c = 0;
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  x *= neg;
}
// -------- Item Get Border Line! -----------
// Don't forget to use long long if needed!
LL a[200020], b[200200], n, m, c[200020];
void solve() {
  rd(n);
  rd(m);
  repn(i, n) rd(a[i]);
  repn(i, m) rd(b[i]), c[i] = b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);

  n = unique(a + 1, a + n + 1) - (a + 1);
  if (n == 1) {
    for (int i = 1; i <= m; i++) printf("%lld ", __gcd(a[1], b[i]));
    return;
  }
  int qwq = m;
  m = unique(b + 1, b + m + 1) - (b + 1);
  LL gcd = a[2] - a[1];
  for (int i = 3; i <= n; i++)
    if (a[i] - a[i - 1]) gcd = __gcd(gcd, a[i] - a[i - 1]);
  if (gcd == 1) {
    repn(j, qwq) printf("%d ", 1);
    return;
  }
  // cerr << gcd << endl;
  map<LL, LL> sol;
  repn(i, m) b[i] %= gcd;
  a[1] %= gcd;
  for (int i = 1; i <= m; i++) {
    if (b[i] < gcd && ((a[1] + b[i]) && (gcd % (a[1] + b[i]) == 0)) ||
        ((a[1] + b[i]) % gcd == 0)) {
      if (a[1] + b[i] == 0)
        sol[b[i]] = gcd;
      else
        sol[b[i]] = a[1] + b[i];
    } else if (sol.find(b[i] % gcd) != sol.end()) {
      sol[b[i]] = sol[b[i] % gcd];
    } else
      sol[b[i]] = 1;
  }
  // for (auto p : sol) cerr << p.first << ' ' << p.second << endl;
  repn(i, qwq) cout << sol[c[i] % gcd] << ' ';
}
signed main() {
  int T = 1;
  //  rd(T);
  solve();

  return 0;
}
