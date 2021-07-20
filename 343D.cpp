#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define y2 y1919810
typedef pair<int, int> PII;
//#define int long long
#define all(x) x.begin(), x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t) for (int i = s; i <= (int)t; i++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
  char c = getchar();
  int neg = 1;
  long long val = 0;
  while (c != '-' && !isdigit(c)) c = getchar();
  if (c == '-') c = getchar(), neg = -1;
  while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
  return neg * val;
}
const int N = 3000020;
vector<int> G[N];
int n, m, in[N], out[N];
namespace sgt {
int t[N], lazy[N], lc[N], rc[N];
#define ls (p << 1)
#define rs (p << 1 | 1)
void build(int p, int l, int r) {
  lc[p] = l;
  rc[p] = r;
  lazy[p] = -1;
  if (l == r) {
    t[p] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
}
void pushdown(int p) {
  if (lazy[p] != -1) {
    t[ls] = (rc[ls] - lc[ls] + 1) * lazy[p];
    lazy[ls] = lazy[p];
    t[rs] = (rc[rs] - lc[rs] + 1) * lazy[p];
    lazy[rs] = lazy[p];
    lazy[p] = -1;
  }
}
int query(int p, int l, int r) {
  pushdown(p);
  if (l <= lc[p] && rc[p] <= r) return t[p];
  elif (l > rc[p] || r < lc[p]) return 0;
  return query(ls, l, r) + query(rs, l, r);
}
void modify(int p, int l, int r, int d) {
  pushdown(p);
  if (l <= lc[p] && rc[p] <= r) {
    t[p] = d * (rc[p] - lc[p] + 1);
    lazy[p] = d;
    return;
  }
  elif (l > rc[p] || r < lc[p]) return;
  modify(ls, l, r, d);
  modify(rs, l, r, d);
}
}  // namespace sgt
namespace hld {
int top[N], dfn[N], fa[N], sz[N], hson[N], dep[N], rnk[N], tot;
void dfs1(int u) {
  sz[u] = 1;
  rep(i, G[u].size()) if (G[u][i] != fa[u]) {
    int v = G[u][i];
    dep[v] = dep[u] + 1;
    fa[v] = u;
    dfs1(v);
    sz[u] += sz[v];
    if (!hson[u] || sz[hson[u]] < sz[v]) hson[u] = v;
  }
}
void dfs2(int u, int t) {
  top[u] = t;
  tot++;
  in[u] = tot;
  dfn[u] = tot;
  rnk[tot] = u;
  if (hson[u]) dfs2(hson[u], t);
  rep(i, G[u].size()) {
    int v = G[u][i];
    if (v != hson[u] && v != fa[u]) dfs2(v, v);
  }
  out[u] = tot;
}
}  // namespace hld
namespace CF343D {
void fill(int x) { sgt::modify(1, in[x], out[x], 1); }
void empty(int x) {
  using namespace hld;
  int u = x, v = 1;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    sgt::modify(1, dfn[top[u]], dfn[u], 0);
    u = fa[top[u]];
  }
  if (dep[u] > dep[v]) swap(u, v);
  sgt::modify(1, dfn[u], dfn[v], 0);
}
bool query(int x) {
  using hld::dfn;
  return sgt::query(1, dfn[x], dfn[x]);
}
}  // namespace CF343D
void solve() {
  n = qread();
  rep(i, n - 1) {
    int u = qread(), v = qread();
    G[u].pb(v);
    G[v].pb(u);
  }
  hld::dep[1] = 1;
  hld::fa[1] = 1;
  hld::dfs1(1);
  hld::dfs2(1, 1);
  sgt::build(1, 1, n);
  m = qread();
  rep(i, m) {
    int op = qread(), x = qread();
    if (op == 1) {
      CF343D::fill(x);
    }
    elif (op == 2) { CF343D::empty(x); }
    elif (op == 3) { printf("%d\n", CF343D::query(x)); }
  }
}
int main() {
  int T = 1;
  // T = qread();
  while (T--) solve();
  return 0;
}
