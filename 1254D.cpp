
// Problem: D. Tree Queries
// Contest: Codeforces - Codeforces Round #601 (Div. 1)
// URL: https://codeforces.com/contest/1254/problem/D
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
#define RESET(x) memset((x), 0, sizeof(x))

const int mod = 998244353;
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
const int N = 200020;
int n, m;
struct Fenwick {
  int arr[N + 15];
  void modify(int x, int d) {
    for (; x <= N; x += x & (-x)) {
      arr[x] = (arr[x] + d) % mod;
    }
  }
  int query(int x) {
    LL res = 0;
    for (; x; x -= x & (-x)) {
      res = (res + arr[x]) % mod;
    }
    return res;
  }
} fenwick;
int top[N], dfn[N], dep[N], fa[N], hson[N], sz[N];
VI g[N];
void dfs1(int u) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    dep[v] = dep[u] + 1;
    fa[v] = u;
    dfs1(v);
    sz[u] += sz[v];
    if (sz[v] > sz[hson[u]]) hson[u] = v;
  }
}
int in[N], out[N];
int tot;
void dfs2(int u, int t) {
  top[u] = t;
  in[u] = dfn[u] = ++tot;
  if (hson[u]) dfs2(hson[u], t);
  for (auto v : g[u])
    if (v != hson[u] && v != fa[u]) dfs2(v, v);
  out[u] = tot;
}
LL qpow(LL a, LL b = mod - 2) {
  LL ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans % mod;
}
int lazy[N];
void solve() {
  n = qread();
  m = qread();
  rep(i, n - 1) {
    int u = qread(), v = qread();
    g[u].pb(v);
    g[v].pb(u);
  }
  fa[1] = 1;
  dep[1] = 1;
  dfs1(1);
  dfs2(1, 1);
  int invn = qpow(n);
  while (m--) {
    int op = qread();
    if (op == 1) {
      int u = qread(), d = qread();
      if (u != 1) fenwick.modify(dfn[u], d * (n - sz[u]) % mod);
      fenwick.modify(1, d * sz[u] % mod);
      if (hson[u])
        fenwick.modify(dfn[u] + 1, d * (mod - sz[hson[u]]) % mod);
      lazy[u] = (lazy[u] + d) % mod;
    } else {
      int u = qread();
      LL ans = 0;
      while (top[u] != 1) {
        ans = (
                (
                  (ans + fenwick.query(dfn[u])) % mod 
                  + mod * 2 - fenwick.query(dfn[top[u]] - 1)
                ) % mod
                  + lazy[fa[top[u]]] * (mod * 2 - sz[top[u]]) % mod
              ) % mod;
        u = fa[top[u]];
      }
      ans = (ans + fenwick.query(dfn[u])) % mod;
      // fprintf(stderr, "%lld/%lld\n", ans, n);  
      // this is the raw answer
      printf("%lld\n", (int)(ans * invn % mod));
    }
  }

}
signed main() {
  int T = 1;
  // T = qread();
  while (T--) solve();
  return 0;
}
