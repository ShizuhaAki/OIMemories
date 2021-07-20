#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
int n, m;
const int N = 100010;
const int INF = 0x3f3f3f3f;
int a[N], b[N], best[N], l[N], r[N], dp[N][2], bestv[N];
int d(int x, int y) { return abs(a[x] - b[y]); }
int main() {
  scanf("%d%d%*d%*d", &n, &m);
  repn(i, n) scanf("%d", a + i);
  repn(i, m) scanf("%d", b + i);
  // prework [l, r] range for each red dot
  memset(bestv, INF, sizeof(bestv));
  repn(i, n) {
    // select the best red node for each black node
    int id = lower_bound(b + 1, b + m + 1, a[i]) - b;
    best[i] = d(i, id) < d(i, id - 1) ? id : id - 1;
    repn(j, m) if (d(a[i], b[j]) < bestv[i]) {}
    if (!l[best[i]]) l[best[i]] = i;
    r[best[i]] = i;
    cerr << best[i] << ' ' << l[best[i]] << ' ' << r[best[i]] << endl;
  }
  // start DP
  // let dp[i][j] denote the best solution when
  // ... we are considering red dot i, and
  // ... black dot l[i] chose to go with us (1) or
  // ... it has not chosen to go with us (0)
  repn(i, m) rep(j, 2) {
    // we will consider whether dot r[i] have chosen to go with us
    // if r[i] < l[i + 1], then it must go with us
    if (r[i] < l[i + 1]) {
      // if r[i] is closer to us then l[i],
      // then l[i] will be unhappy
      if (j && d(r[i], b[i]) < d(l[i], b[i])) {
        dp[i + 1][1] = dp[i + 1][0] = dp[i][j] + 1;
      }
    }
    // if r[i] = l[i + 1], however, there will be two cases
    // if r[i] choose to go with us, then we need to consider whether
    // this makes l[i] unhappy
    // otherwise, we can gleefully skip it and let the next i take
    // the decision
    else {
      if (j && d(r[i], b[i]) < d(l[i], b[i])) {
        dp[i + 1][1] = dp[i][j];
        dp[i + 1][0] = dp[i][j] + 1;
      } else {
        dp[i + 1][1] = dp[i + 1][0] = 0;
      }
    }
  }
  printf("%d\n", max(dp[m][0], dp[m][1]));
}