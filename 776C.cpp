#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define int long long
#define ttt template <typename T>
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
const int INF = 0x3f3f3f3f;
ttt inline void rd(T& x) {
  x = 0;
  T neg = 1;
  char c = 0;
  while (c < '0' || c > '9') {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  x *= neg;
}
int n, k;
const int N = 100010;
int a[N], sum[N];
void solve() {
  rd(n);
  rd(k);
  repn(i, n) {
    rd(a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  if (k == 1) {
    map<LL, int> cnt;
    int ans = 0;
    for (int i = n; i >= 0; i--) {
      if (cnt.find(sum[i] + 1) != cnt.end()) ans += cnt[sum[i] + 1];
      cnt[sum[i]]++;
    }
    printf("%lld\n", ans);
  } else if (k == -1) {
    map<LL, int> cnt;
    int ans = 0;
    for (int i = n; i >= 0; i--) {
      if (cnt.find(sum[i] + 1) != cnt.end()) ans += cnt[sum[i] + 1];
      if (cnt.find(sum[i] - 1) != cnt.end()) ans += cnt[sum[i] - 1];
      cnt[sum[i]]++;
    }
    printf("%lld\n", ans);
  } else {
    map<LL, int> cnt;
    int ans = 0;
    for (int i = n; i >= 0; i--) {
      LL cur = 1;
      while (true) {
        if (abs(cur) >= 1e15) break;
        if (cnt.find(sum[i] + cur) != cnt.end()) ans += cnt[sum[i] + cur];
        cur *= k;
      }
      cnt[sum[i]]++;
    }
    printf("%lld\n", ans);
  }
}

signed main() {
  int T = 1;
  //  rd(T);
  while (T--) solve();
  return 0;
}
