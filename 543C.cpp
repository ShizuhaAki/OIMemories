
// Problem: C. Remembering Strings
// Contest: Codeforces - Codeforces Round #302 (Div. 1)
// URL: https://codeforces.com/contest/543/problem/C
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
const int N = 21;
string s[N];
int a[N][N];
int require[N][N];
int b[N][N];  // minimum a required to change all others expect s[i][j]
int dp[lsh(N)];
int n, m;
void solve() {
  cin >> n >> m;
  rep(i, n) cin >> s[i];
  rep(i, n) rep(j, m) cin >> a[i][j];
  rep(i, n) rep(j, m) {
    int maxCost = -INF, sumCost = 0;
    rep(k, n) {
      if (s[k][j] == s[i][j]) {
        maxCost = max(maxCost, a[k][j]);
        require[i][j] |= lsh(k);
        sumCost += a[k][j];
      }
    }
    b[i][j] = sumCost - maxCost;
  }
  memset(dp, INF, sizeof(dp));
  dp[0] = 0;
  rep(s, lsh(n)) {
    rep(i, n) {
      if (!(s & lsh(i))) {
        rep(j, m) {
          dp[s | lsh(i)] = min(dp[s | lsh(i)], dp[s] + a[i][j]);
          dp[s | require[i][j]] = min(dp[s | require[i][j]], dp[s] + b[i][j]);
        }
      }
    }
  }
  cout << dp[lsh(n) - 1] << endl;
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
