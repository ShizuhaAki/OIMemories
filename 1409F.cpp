
// Problem: F. Subsequences of Length Two
// Contest: Codeforces - Codeforces Round #667 (Div. 3)
// URL: https://codeforces.com/contest/1409/problem/F
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
void chmax(int &a, int b) { a = max(a, b); }
const int N = 227;
int dp[N][N][N];
void solve() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  char t1, t2;
  cin >> t1 >> t2;
  memset(dp, -INF, sizeof(dp));
  dp[0][0][0] = 0;
  rep(i, n)                      // currently considering $i...
      rep(j, min(k + 1, i + 1))  // ... with $j operations done ...
      rep(occ, i + 1) {          // ... and $occ occurences of t1.
    chmax(dp[i + 1][j][occ + (s[i] == t1)],
          dp[i][j][occ] + occ * (s[i] == t2));  // not changing
    if (j < k) {                                // chances remain
      chmax(dp[i + 1][j + 1][occ + 1],
            dp[i][j][occ] +
                ((t1 == t2) ? occ
                            : 0));  // addition is only performed if $t1 = $t2;
      chmax(dp[i + 1][j + 1][occ + (t1 == t2 ? 1 : 0)], dp[i][j][occ] + occ);
    }
  }
  int ans = -INF;
  rep(i, n + 1) ans = max(ans, dp[n][k][i]);
  cout << ans << endl;
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
