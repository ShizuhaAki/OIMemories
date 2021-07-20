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
#define RESET(x) memset((x), 0, sizeof(x))
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 220;
int w[N];
int n, k;
VI g[N];
int d[N][N];
int dp[N][N];
// dp[i][j] = the best solution when node j gets its signal from node i
int best[N];
// best[i] = j such that dp[j][i] is minimized among all 1 <= j <= n
void DP(int u, int f) {
  repn(i, n) dp[i][u] = w[d[i][u]] + k;
  for (auto v : g[u])
    if (v != f) {
      DP(v, u);
      repn(i, n) dp[i][u] +=
          min(dp[best[v]][v],  // let v get its signal from best[v], or
              dp[i][v] - k);   // let v use the node we've created at i for u
      // we need to subtract k here because we only need to build the
      // server once, and this cost was already calculated in dp[i][u]
    }
  // we place the calculation of best array after running dp
  // because we need to make sure that dp[i][u] is final
  best[u] =
      1;  // in case we didn't find a better one, this at least benefits more
  repn(i, n) if (dp[i][u] <= dp[best[u]][u]) best[u] = i;
}
int ans[N];
void print(int u, int f, int i) {
  for (auto v : g[u]) 
    if (v != f) {
      if (dp[best[v]][v] > dp[i][v] - k)
        ans[v] = i;
      else
        ans[v] = best[v];
      print(v, u, ans[v]);
    }
}
void solve() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  repn(i, n - 1) cin >> w[i];
  memset(d, INF, sizeof(d));
  repn(i, n) d[i][i] = 0;
  repn(i, n - 1) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
    d[u][v] = d[v][u] = 1;
  }
  repn(k, n) repn(i, n) repn(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  DP(1, 0);
  cout << dp[best[1]][1] << endl;
  ans[1] = best[1];
  print(1, 0, ans[1]);
  repn(i, n) cout << ans[i] << ' ';
  cout << endl;
}
signed main() {
  int T = 1;
  // cin >> T;
  while (T--) solve();
  return 0;
}
