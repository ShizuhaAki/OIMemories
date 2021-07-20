
// Problem: E. Lomsat gelral
// Contest: Codeforces - Educational Codeforces Round 2
// URL: https://codeforces.com/problemset/problem/600/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int c[N];
VI g[N];
int sz[N], dep[N], fa[N], hson[N];
void dfs1(int u) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == fa[u]) continue;
    dep[v] = dep[u] + 1;
    fa[v] = u;
    dfs1(v);
    sz[u] += sz[v];
    if (sz[hson[u]] < sz[v]) hson[u] = v;
  }
}
int cnt[N];
int sum, mx;
void dfs2(int u, int h) {
  cnt[c[u]]++;
  if (cnt[c[u]] > mx) {
    mx = cnt[c[u]];
    sum = c[u];
  } else if (cnt[c[u]] == mx)
    sum += c[u];
  for (auto v : g[u]) {
    if (v == fa[u] || v == h) continue;
    dfs2(v, h);
  }
}
int ans[N], n, m;
void dfs3(int u) {
  cnt[c[u]]--;
  for (auto v : g[u]) {
    if (v != fa[u]) dfs3(v);
  }
}
void dfs(int u) {
  int hs = -1;
  for (auto v: g[u]) {
    if (v == fa[u]) continue;
    if (v == hson[u]) hs = v;
    else {
      dfs(v);
      dfs3(v);
      sum = mx = 0;
    }
  }
  if (hs != -1) dfs(hs);
  dfs2(u, hs);
  ans[u] = sum;
}
void solve() {
  n = qread();
  repn(i, n) c[i] = qread();
  rep(i, n - 1) {
    int u = qread(), v = qread();
    g[u].pb(v);
    g[v].pb(u);
  }
  dep[1] = 1;
  fa[1] = 1;
  dfs1(1);
  dfs(1);
  repn(i, n) cout << ans[i] << ' ';
}
signed main() {
  int T = 1;
  // T = qread();
  while (T--) solve();
  return 0;
}
