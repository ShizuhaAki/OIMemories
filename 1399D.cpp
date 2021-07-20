
// Problem: D. Binary String To Subsequences
// Contest: Codeforces - Codeforces Round #661 (Div. 3)
// URL: https://codeforces.com/contest/1399/problem/D
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
const int N = 200020;
int n, ans[N];
string a;
void solve() {
  cin >> n >> a;
  RESET(ans);
  stack<int> s0, s1;
  rep(i, n) {
    int belong = s0.size() + s1.size();
    if (a[i] == '0') {
      // we first try to append it to an existing subsequence
      if (!s1.empty()) {
        belong = s1.top();
        // move the "belong" subseq. to the other camp
        s1.pop();
        s0.push(belong);
      } else {
        // we have to create a new subseq. then
        s0.push(belong);
      }
    } else {
      if (!s0.empty()) {
        belong = s0.top();
        s0.pop();
        s1.push(belong);
      } else {
        s1.push(belong);
      }
    }
    ans[i] = belong;
  }
  cout << s0.size() + s1.size() << endl;
  rep(i, n) cout << ans[i] + 1 << ' ';
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
