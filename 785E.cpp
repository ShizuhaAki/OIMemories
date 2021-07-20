
// Problem: E. Anton and Permutation
// Contest: Codeforces - Codeforces Round #404 (Div. 2)
// URL: https://codeforces.com/contest/785/problem/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define VPII vector<PII>
#define y2 y1919810
typedef pair<int, int> PII;
typedef vector<int> VI;
#define int long long
#define all(x) x.begin(), x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t) for (int i = s; i <= (int)t; i++)
#define il inline
#define vo void
#define I int
#define RESET(x) memset((x), 0, sizeof(x))
#define au auto

const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
LL qread() {
  char c = getchar();
  int neg = 1;
  LL val = 0;
  while (c != '-' && !isdigit(c)) c = getchar();
  if (c == '-') {
    c = getchar();
    neg = -1;
  }
  while (isdigit(c)) {
    val = (val << 3) + (val << 1) + c - '0';
    c = getchar();
  }
  return neg * val;
}
const I N = 200021;
I n, which[N], val[N];
I ans;
VI block[N];
I BL;
vo modify(I l, I r) {
  I wl = which[l], wr = which[r];
  if (wl != wr) {
    block[wl].erase(lower_bound(block[wl].begin(), block[wl].end(), val[l]));
    block[wl].insert(lower_bound(block[wl].begin(), block[wl].end(), val[r]),
                     val[r]);
    block[wr].erase(lower_bound(block[wr].begin(), block[wr].end(), val[r]));
    block[wr].insert(lower_bound(block[wr].begin(), block[wr].end(), val[l]),
                     val[l]);
  }
  swap(val[l], val[r]);
}
I query(I l, I r, I v) {
  //   cerr << "Query " << l << ' ' << r  << ' ' << v << endl;
  if (l > r) return 0;
  I res = 0;
  I wl = which[l], wr = which[r];
  range(i, l, min(BL * wl, r)) res += (val[i] < v);
  if (wl == wr) return res;
  range(i, min(BL * (wr - 1) + 1, r), r) res += (val[i] < v);
  range(i, wl + 1, wr - 1) res +=
      lower_bound(block[i].begin(), block[i].end(), v) - block[i].begin();
  return res;
}
vo init() {
  repn(i, n) {
    val[i] = i;
    which[i] = (i - 1) / BL + 1;
    block[which[i]].pb(val[i]);
  }
}
vo solve() {
  n = qread();
  I m = qread();
  BL = max(1LL, (int)floor(sqrt(n * log2(n))));
  init();
  while (m--) {
    I l = qread(), r = qread();
    if (l > r) swap(l, r);
    if (l == r) {
      printf("%lld\n", ans);
      continue;
    }
    I res = query(l + 1, r - 1, val[r]) - query(l + 1, r - 1, val[l]);
    res *= 2;
    ans += res;
    //    cerr << ans << endl;
    if (val[l] < val[r])
      ans++;
    else
      ans--;
    modify(l, r);
    printf("%lld\n", ans);
  }
}
signed main() {
  int T = 1;
  // T = qread();
  while (T--) solve();
  return 0;
}
