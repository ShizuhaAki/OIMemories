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
const int N = 100010;
struct Event {
  int a, b, ord, org;  // respectively, hair loss and dissatisfaction
};
Event e[N], f[N];
bool chosen[N];
int n, p, k;
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cin >> n >> p >> k;
  repn(i, n) cin >> e[i].a >> e[i].b;
  repn(i, n) e[i].org = i;
  sort(e + 1, e + 1 + n, [](Event x, Event y) {
    if (x.b != y.b)
      return x.b > y.b;  // those with larger dissatisfaction values come first
    return x.a < y.a;    // after that, those with less hair loss come first
  });
  // make a backup of the results of the first sort first
  repn(i, n) f[i] = e[i];
  // we'll then throw away the last (p - k) events
  // because they will not be done whatsoever
  // then, we will take k events from the (n - (p - k))
  // events that remain, sorted by decreasing order of hair loss.
  //
  // Note:
  //   When sorting, we must use the order got by last sorting
  //   so that the president is guaranteed to choose the tasks we
  //   impose on her, rather than other ones according to her
  //   preferences that might not be optimal for us.
  repn(i, n) e[i].ord = i;
  sort(e + 1, e + 1 + (n - (p - k)), [](Event x, Event y) {
    if (x.a != y.a) return x.a > y.a;  // based on hair loss first
    return x.ord <
           y.ord;  // after that, sorting is based on order of the last sorting
  });
  int besti = 0;
  repn(i, k) {
    chosen[e[i].org] = true;
    besti = max(besti, e[i].ord);
  }
  range(i, besti + 1, besti + (p - k)) chosen[f[i].org] = true;
  repn(i, n) if (chosen[i]) cout << i << ' ';
  cout << endl;
  
}
signed main() {
  int T = 1;
  // cin >> T;
  while (T--) solve();
  return 0;
}
