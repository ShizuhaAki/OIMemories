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
LL a[200020], b[200200], n, m;
void solve() {
  rd(n);
  rd(m);
  repn(i, n) rd(a[i]);
  repn(i, m) rd(b[i]);
  repn(i, m) {
    LL ans = (a[1] + b[i]);
    repn(j, n) ans = __gcd(a[j] + b[i], ans);
    cout << ans <<' ';
  }
}
signed main() {
  int T = 1;
//  rd(T);
  while (T--) 
    solve();
  return 0;
}
