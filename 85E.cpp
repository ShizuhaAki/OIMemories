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
struct Point {
  int x, y;
  Point(int x = 0, int y = 0) : x(x), y(y) {}
};
int dist(Point a, Point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
int n;
vector<Point> a;
vector<int> color;
bool flg = true;
int ans, cc;
void dfs(int u, int col, int threshold) {
  color[u] = col;
  rep(v, n) {
    if (!flg) return;
    if (dist(a[u], a[v]) <= threshold) continue;
    if (color[v] == -1)
      dfs(v, col ^ 1, threshold);
    else if (color[v] == color[u]) {
      flg = false;
      return;
    }
  }
}
bool check(int x) {
  color.clear();
  color.resize(n);
  fill(all(color), -1);
  int compcnt = 0;
  rep(i, n) {
    if (color[i] == -1) {
      flg = true;
      compcnt++;
      dfs(i, 0, x);
      if (!flg) return false;  // we are no longer a bipartite!
    }
  }
  ans = x;
  cc = compcnt;
  return true;  // we can still get lower!
}
const int mod = 1e9 + 7;
LL qpow(LL a, LL b) {
  LL ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans % mod;
}
void solve() {
  n = qread();
  a.resize(n);
  rep(i, n) {
    a[i].x = qread();
    a[i].y = qread();
  }
  int L = -1, R = 10000;
  while (L + 1 < R) {
    int mid = (L + R) >> 1;
    if (check(mid))
      R = mid;
    else
      L = mid;
  }
  cout << ans << endl << qpow(2, cc) << endl;
}
signed main() {
  int T = 1;
  // T = qread();
  while (T--) solve();
  return 0;
}
