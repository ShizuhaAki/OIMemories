// Problem: D. Distance in Tree
// Contest: Codeforces - VK Cup 2012 Round 1
// URL: https://codeforces.com/contest/161/problem/D
// Written by RavenclawOIer on 11-14-2020

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
template <typename T>
inline T chmin(T& a, T b) {
  return a = min(a, b);
}
template <typename T>
inline T chmax(T& a, T b) {
  return a = max(a, b);
}
const int INF = 0x3f3f3f3f;
int n, k;
const int N = 50010;
vector<int> g[N];

namespace CentroidDecomp {
int sz[N];
bool centroid[N];

void dfs(int u, int f) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == f || centroid[v]) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}

pii getCentroid(int u, int f, int s) {
  pii res = make_pair(INF, -1);
  int curs = 1, maxs = 0;
  for (auto v : g[u]) {
    if (v == f || centroid[v]) continue;
    chmin(res, getCentroid(v, u, s));
    chmax(maxs, sz[v]);
    curs += sz[v];
  }
  chmax(maxs, s - curs);
  chmin(res, make_pair(maxs, u));
  return res;
}

void getDist(int u, int f, int d, vector<int>& res) {
  res.push_back(d);
  for (auto v : g[u]) {
    if (v == f || centroid[v]) continue;
    getDist(v, u, d + 1, res);
  }
}

LL calc(vector<int>& d) {
  LL res = 0;
  sort(d.begin(), d.end());
  int j = d.size();
  // solve for k
  rep(i, d.size()) {
    while (j > 0 && d[i] + d[j - 1] > k) --j;
    res += j - (j > i);
  }
  j = d.size();
  rep(i, d.size()) {
    while (j > 0 && d[i] + d[j - 1] > k - 1) --j;
    res -= j - (j > i);
  }
  // cerr << res / 2 << endl;
  return res / 2;
}
LL ans = 0;
void solve(int u) {
  dfs(u, 0);
  int s = getCentroid(u, -1, sz[u]).second;
  centroid[s] = true;

  for (auto v : g[s]) {
    if (centroid[v]) continue;
    solve(v);
  }

  vector<int> d;
  d.push_back(0);
  for (auto v : g[s]) {
    if (centroid[v]) continue;
    vector<int> td;
    getDist(v, s, 1, td);
    ans -= calc(td);
    d.insert(d.end(), td.begin(), td.end());
  }

  ans += calc(d);
  centroid[s] = false;
}

void main() {
  scanf("%d%d", &n, &k);
  rep(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  solve(getCentroid(1, 0, n).second);
  printf("%lld", ans);
}
}  // namespace CentroidDecomp

namespace DP {
void main() {
  
}
}

int main(){
  DP::main();
}