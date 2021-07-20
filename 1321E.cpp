
// Problem: E. World of Darkraft: Battle for Azathoth
// Contest: Codeforces - Codeforces Round #625 (Div. 2, based on Technocup 2020
// Final Round) URL: https://codeforces.com/contest/1321/problem/E Memory Limit:
// 512 MB Time Limit: 2000 ms Powered by CP Editor
// (https://github.com/cpeditor/cpeditor)

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
#define RESET(x) memset((x), 0, sizeof(x))

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
int n, m, p;
const int N = 200020;
struct W {
  int a, c;
  W(int a = 0, int c = 0) : a(a), c(c) {}
} X[N], x[N];
struct D {
  int d, c;
  D(int d = 0, int c = 0) : d(d), c(c) {}
} Y[N], y[N];
struct M {
  int a, d, p;
  M(int a = 0, int d = 0, int p = 0) : a(a), d(d), p(p) {}
} Z[N], z[N];
class SegmentTree {
 private:
  int t[N], lc[N], rc[N], lazy[N];
#define ls p << 1
#define rs p << 1 | 1
  void pushup(int p) { t[p] = max(t[ls], t[rs]); }
  void pushdown(int p) {
    if (lazy[p]) {
      lazy[ls] += lazy[p];
      lazy[rs] += lazy[p];
      t[ls] += lazy[p];
      t[rs] += lazy[p];
      lazy[p] = 0;
    }
  }

 public:
  void build(int l, int r, int p = 1) {
    lc[p] = l;
    rc[p] = r;
    if (l == r) {
      t[p] = -x[l].c;
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    pushup(p);
  }
  int query() { return t[1]; }
  void modify(int l, int r, int v, int p = 1) {
    if (l <= lc[p] && rc[p] <= r) {
      t[p] += v;
      lazy[p] += v;
      return;
    } else if (l > rc[p] || r < lc[p])
      return;
    pushdown(p);
    modify(l, r, v, ls);
    modify(l, r, v, rs);
    pushup(p);
  }
} seg;
int a[N];
void solve() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> p;
  repn(i, n) cin >> X[i].a >> X[i].c;
  repn(i, m) cin >> Y[i].d >> Y[i].c;
  repn(i, p) cin >> Z[i].d >> Z[i].a >> Z[i].p;
  sort(X + 1, X + n + 1,
       [](W a, W b) { return a.c != b.c ? a.c < b.c : a.a < b.a; });
  sort(Y + 1, Y + n + 1,
       [](D a, D b) { return a.c != b.c ? a.c < b.c : a.d < b.d; });
  sort(Z + 1, Z + n + 1, [](M a, M b) { return a.d < b.d; });
  int cnt = 0;
  repn(i, n) if (X[i].a != x[cnt].a) x[++cnt] = X[i];
  n = cnt;
  cnt = 0;
  repn(i, n) if (Y[i].d != y[cnt].d) y[++cnt] = Y[i];
  m = cnt;
  cnt = 1;
  seg.build(1, n);
  cerr << n << ' ' << m << endl;
  repn(i, n) a[i] = x[i].a;
  int ans = 0;
  repn(i, m) {
    for (; cnt <= p && z[cnt].a < y[cnt].d; ++cnt) {
      // find which weapons can kill this monster
      int w = upper_bound(a + 1, a + 1 + n, z[cnt].d) - a;
      if (a[w] > z[cnt].d) seg.modify(w, n, z[cnt].p);
    }
    cerr << seg.query() << endl;
    ans = max(ans, seg.query() - x[i].c);
  }
  cout << ans << endl;
}
signed main() {
  int T = 1;
  // T = qread();
  while (T--) solve();
  return 0;
}
