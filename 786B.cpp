
// Problem: B. Legacy
// Contest: Codeforces - Codeforces Round #406 (Div. 1)
// URL: https://codeforces.com/problemset/problem/786/B
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
#define RESET(x) memset((x), 0, sizeof(x))
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 1000020;
#define UP true
#define DOWN false
struct Edge {
  int v, w;
  Edge(int v = 0, int w = 0) : v(v), w(w) {}
};
vector<Edge> g[N];
int n, q, s, ind;
int tin[N], tout[N], lc[N], rc[N];
void build(int t, int l, int r) {
  lc[t] = l;
  rc[t] = r;
  if (l == r) {
    // leaf nodes retain their original indices
    tin[t] = l;
    tout[t] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(t << 1, l, mid);
  build(t << 1 | 1, mid + 1, r);
  // nodes representing ranges (non-leaf nodes) use
  // indices starting from n in order to distinguish
  // them from leaf nodes.
  tin[t] = ++ind;
  tout[t] = ++ind;
  g[tin[t]].pb(Edge(tin[t << 1], 0));
  g[tin[t]].pb(Edge(tin[t << 1 | 1], 0));
  g[tout[t << 1]].pb(Edge(tout[t], 0));
  g[tout[t << 1 | 1]].pb(Edge(tout[t], 0));
}
void addEdgeFromRangeToNode(int t, int l, int r, int u, int w) {
//  cerr << "call rtn " << t << ' ' << l << ' ' << r << ' ' << u <<' ' << w << endl;
  if (l <= lc[t] && rc[t] <= r) {
    g[tout[t]].pb(Edge(u, w));
 //   cerr << "rtn " << tout[t] << ' ' << u << ' ' << w << endl;
    return;
  }
  if (l > rc[t] || r < lc[t]) return;
  addEdgeFromRangeToNode(t << 1, l, r, u, w);
  addEdgeFromRangeToNode(t << 1 | 1, l, r, u, w);
}
void addEdgeFromNodeToNode(int u, int v, int w) { g[u].pb(Edge(v, w)); }
void addEdgeFromNodeToRange(int t, int l, int r, int u, int w) {
  if (l <= lc[t] && rc[t] <= r) {
    g[u].pb(Edge(tin[t], w));
 //   cerr << "ntr " <<  u << ' ' << tin[t] << ' ' << w << endl;
    return;
  }
  if (l > rc[t] || r < lc[t]) return;
  addEdgeFromNodeToRange(t << 1, l, r, u, w);
  addEdgeFromNodeToRange(t << 1 | 1, l, r, u, w);
}
int dist[N];
struct DijNode {
  int u, d;
  bool operator<(const DijNode& that) const { return d > that.d; }
  DijNode(int u = 0, int d = 0) : u(u), d(d) {}
};
bool vis[N];
void dijkstra() {
  fill(dist + 1, dist + 999999, 1e18);
  dist[s] = 0;
  priority_queue<DijNode> pq;
  pq.push(DijNode(s, 0));
  while (!pq.empty()) {
    auto t = pq.top();
    pq.pop();
    int u = t.u;
    if (vis[u]) continue;
    vis[u] = true;
    for (auto e : g[u]) {
      int v = e.v, w = e.w;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        if (!vis[v]) pq.push(DijNode(v, dist[v]));
      }
    }
  }
}
void solve() {
  cin >> n >> q >> s;
  ind = n;
  build(1, 1, n);
  repn(i, q) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, v, w;
      cin >> u >> v >> w;
      addEdgeFromNodeToNode(u, v, w);
    } else if (type == 2) {
      int l, r, v, w;
      cin >> v >> l >> r >> w;
      addEdgeFromNodeToRange(1, l, r, v, w);
    } else if (type == 3) {
      int l, r, v, w;
      cin >> v >> l >> r >> w;
      addEdgeFromRangeToNode(1, l, r, v, w);
    }
  }
  dijkstra();
  repn(i, n) {
    if (dist[i] == 1e18)
      cout << -1 << ' ';
    else
      cout << dist[i] << ' ';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  // cin >> T;
  while (T--) solve();
  return 0;
}
