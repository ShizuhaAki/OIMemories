// Problem: C. Magic Formulas
// Contest: Codeforces - Codeforces Round #242 (Div. 2)
// URL: https://codeforces.com/contest/424/problem/C
// Written by RavenclawOIer on 11-21-2020

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ttt template <typename T>
#define int long long
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
int n;
const int N = 1000010;
int a[N];
int pre[N];
void solve() {
  rd(n);
  rep(i, n) rd(a[i]);
  int ans = a[0];
  rep(i, n) if (i) ans ^= a[i];
  pre[1] = 1;
  for (int i = 2; i <= n; i++) pre[i] = i ^ pre[i - 1]; 
  for (int i = 2; i <= n; i++) {
    int s = n / i, r = n % i;
    if (s % 2 == 0) ans ^= pre[r];
    else {
      ans ^= pre[i - 1];
      ans ^= pre[r];
    }
  }
  printf("%lld\n", ans);
}
signed main() {
  int T = 1;
//  rd(T);
  while (T--) 
    solve();
  return 0;
}
