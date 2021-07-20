
// Problem: D. Zigzags
// Contest: Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1400/problem/D
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
const int N = 3001;
int a[N], n;
int cnt[N * N];
int Hash(int x, int y) { return x * n + y; }
void solve() {
  RESET(cnt);
  n = qread();
  int ans = 0;
  repn(i, n) a[i] = qread();
  for (int j = n; j >= 1; j--) {
    int k = j + 1;
    for (int l = k + 1; l <= n; l++) cnt[Hash(a[k], a[l])]++;
    for (int i = 1; i < j; i++) ans += cnt[Hash(a[i], a[j])];
  }
  cout << ans << endl;
}
signed main() {
  int T = 1;
  T = qread();
  while (T--) solve();
  return 0;
}
