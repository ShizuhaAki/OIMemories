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
//#define int long long
#define all(x) x.begin(), x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t) for (int i = s; i <= (int)t; i++)
#define il inline
#define RESET(x) memset((x), 0, sizeof(x))

const string badResult = "There is no route, Karl!";
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
vector<VI> g, revg;
VPII e;
int n, m;
VI vis, in, out;
VI nxt;
void checkConnectivity(int u, vector<VI>& gr) {
  if (vis[u]) return;
  vis[u] = true;
  for (auto v : gr[u]) {
    checkConnectivity(v, gr);
  }
}
int s[200020];
void dfs(int u, int dep) {
  if (dep == n) {
    s[dep] = u;
    if (u == 1) {
      rep(i, dep + 1) printf("%d ", s[i]);
      puts("");
      exit(0);
    }
    return;
  }
  if (vis[u]) return;
  vis[u] = true;
  s[dep] = u;
  if (nxt[u])
    dfs(nxt[u], dep + 1);
  else
    for (auto v : g[u]) dfs(v, dep + 1);
  vis[u] = false;
  s[dep] = 0;
}
void solve() {
  n = qread();
  m = qread();
  vis.resize(n + 1);
  in.resize(n + 1);
  out.resize(n + 1);
  g.resize(n + 1);
  revg.resize(n + 1);
  set<PII> es;
  if (m < n) {
    cout << badResult << endl;
    return;
  }
  rep(i, m) {
    int u = qread(), v = qread();
    if (es.count(mp(u, v))) continue;
    es.insert(mp(u, v));
    g[u].pb(v);
    revg[v].pb(u);
    e.pb(mp(u, v));
  }
  checkConnectivity(1, g);
  repn(i, n) if (!vis[i]) {
    cout << badResult << endl;
    return;
  }
  fill(vis.begin(), vis.end(), 0);
  checkConnectivity(1, revg);
  repn(i, n) if (!vis[i]) {
    cout << badResult << endl;
    return;
  }
  rep(i, e.size()) {
    int u = e[i].first, v = e[i].second;
    if (!in[v]) in[v] = u;
    elif (in[v] != u) in[v] = -1;
    if (!out[u]) out[u] = v;
    elif (out[u] != v) out[u] = -1;
  }
  repn(i, n) if (!in[i] || !out[i]) {
    cout << badResult << endl;
    return;
  }
  nxt.resize(n + 1);
  fill(nxt.begin(), nxt.end(), 0);
  repn(i, n) if (in[i] != -1 && out[i] != -1) {
    nxt[in[i]] = i;
    nxt[i] = out[i];
  }
  fill(vis.begin(), vis.end(), 0);
  dfs(1, 0);
  cout << badResult << endl;
  return;
}
signed main() {
#ifndef CHTHOLLY
  freopen("king.in", "r", stdin);
  freopen("king.out", "w", stdout);
#endif
  int T = 1;
  // T = qread();
  while (T--) solve();
  return 0;
}