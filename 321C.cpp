#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
const int INF = 0x3f3f3f3f;
const int N = 100010;
vector<int> g[N];
bool ban[N];
int sz[N];
int n;
void dfs1(int u, int f) {
  sz[u] = 1;
  for (auto v: g[u]) {
    if (v == f || ban[v]) continue;
    dfs1(v, u);
    sz[u] += sz[v];
  }
}
pii dfs2(int u, int f, int s) {
  pii res(INF, -1);
  int msz = -1;
  for (auto v: g[u]) {
    if (v == f || ban[v]) continue;
    chmin(res, dfs2(v, u, s));
    chmax(msz, sz[v]);
  }
  chmax(msz, s - sz[u]);
  chmin(res, make_pair(msz, u));
  return res;
}
int get(int u) {
  dfs1(u, 0);
  return dfs2(u, 0, sz[u]).second;
}
char ans[N];
void solve(int u, int dep) {
  int s = get(u);
  ban[s] = true;
  ans[s] = 'A' + dep;
  for (auto v: g[s]) {
    if (ban[v]) continue;
    solve(v, dep + 1);
  }
  ban[s] = false;
}

int main() {
  scanf("%d", &n);
  rep(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  solve(get(1), 0);
  for (int i = 1; i <= n; i++) {
    putchar(ans[i]);
    putchar(' ');
  }
  puts("");
}