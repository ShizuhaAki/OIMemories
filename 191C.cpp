#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define y2 y1919810
typedef pair <int, int> PII;
//#define int long long
#define all(x) x.begin(),  x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c = getchar();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
const int N = 100010;
int sum[N], dep[N], fa[N], n, m, log_2[N], aux[N][30], ans[N], vis[N];
vector <int> G[N];
vector <PII> q;
void prework(int u, int f, int d) {
//    fprintf(stderr, "%d %d\n", u, f);
    dep[u] = d;
    fa[u] = f;
    rep(i, G[u].size()) {
        int v = G[u][i];
        if (v != f) prework(v, u, d + 1);
    }
}
void init() {
    prework(0, -1, 0);
    rep(i, n) if (i) aux[i][0] = fa[i];
    range(i, 1, 19) rep(j, n) aux[j][i] = aux[aux[j][i - 1]][i - 1];
}
int LCA(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) if (dep[x] - lsh(i) >= dep[y]) x = aux[x][i];
    if (x == y) return x;
    for (int i = 19; i >= 0; i--) if (aux[x][i] != aux[y][i]) { x = aux[x][i]; y = aux[y][i]; }
    return fa[x];
}
int dfs(int u, int f) {
    int res = sum[u];
    rep(i, G[u].size()) {
        int v = G[u][i];
        if (v != f) res += dfs(v, u);
    }
    ans[u] = res;
    return res;
}
void solve() {
    n = qread(); 
    rep(i, n - 1) {
        int u = qread(), v = qread(); u--; v--;
        G[u].pb(v); G[v].pb(u);
        q.pb(mp(u, v));
    }
    init();
    m = qread(); 
    rep(i, m) {
        int x = qread(), y = qread(); x--; y--;
        sum[x]++; sum[y]++; sum[LCA(x, y)] -= 2;
    }
    dfs(0, -1);
    rep(i, n + 1) fprintf(stderr, "%d ", ans[i]);
    rep(i, n - 1) {
        int x = q[i].first, y = q[i].second;
        if (dep[x] > dep[y]) swap(x, y);
        printf("%d ", ans[y]);
    }
}

int main() {
    int T = 1;
    //int T = qread();
    while (T--) solve();
	return 0;
}