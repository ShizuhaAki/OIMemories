#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define y2 y1919810
typedef pair <int, int> PII;
typedef vector <int> VI;
//#define int long long
#define all(x) x.begin(),  x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int MOD = 1e9 + 7;
long long qread() {
    char c = getchar();
    int neg = 1;
    long long val = 0;
    while (c != '-' && !isdigit(c)) 
        c = getchar();
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
long long qpow(long long a, long long b, long long p = MOD) {  
    long long ans = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}
const int N = 200020;
vector <PII> G[N]; int tot, bcccnt, bccID[N];
int n, m, Q;
bool fromCycle[N];
namespace tarjan {
    int dfn[N], low[N];
    stack <int> s;
    void tarjan(int u, int ed = 0) {
        dfn[u] = low[u] = ++tot;
        s.push(u);
        for (auto e:G[u]) {
            int v = e.first, id = e.second;
            if (!dfn[v]) {
                tarjan(v, id);
                low[u] = min(low[u], low[v]);
            } else if (id != ed)
                low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            bcccnt++;
            int yuki = 0;
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                yuki++;
                bccID[cur] = bcccnt;
                if (cur == u) 
                    break;
            }
            if (yuki > 1)
                fromCycle[bcccnt] = true;
        }
    }
}
int cnt[N];
VI T[N];
namespace lca {
    int dfn[N], hson[N], sz[N], fa[N], dep[N], top[N], tot;
    void dfs1(int u) {
        sz[u] = 1;
        cnt[u] = cnt[fa[u]];
        if (fromCycle[u]) cnt[u]++;
        for (auto v:T[u]) {
            if (v == fa[u]) continue;
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            sz[u] += sz[v];
            if (!hson[u] || sz[hson[u]] < sz[v])
                hson[u] = v;
        }
    }
    void dfs2(int u, int t) {
        top[u] = t;
        dfn[u] = ++tot;
        if (hson[u]) 
            dfs2(hson[u], t);
        for (auto v:T[u])
            if (v != hson[u] && v != fa[u])
                dfs2(v, v);
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) 
                u = fa[top[u]];
            else 
                v = fa[top[v]];
        }
        return dep[u] > dep[v] ? v : u;
    }
    void init() {
        fa[1] = 1;
        dep[1] = 1;
        dfs1(1);
        dfs2(1, 1);
    }
}
VI qu, qv;

void solve() {
    n = qread();
    m = qread();
    rep(i, m) {
        int u = qread(), v = qread();
        G[u].pb(mp(v, i));
        G[v].pb(mp(u, i));
    }
    repn(i, n) 
        if (!tarjan::dfn[i])
            tarjan::tarjan(i);
    repn(u, n)
        for (auto e:G[u]) {
            int v = e.first;
            if (bccID[u] != bccID[v]) {
                m++;
                T[bccID[u]].pb(bccID[v]);
                fprintf(stderr, "%d %d\n", bccID[u], bccID[v]);
            }
        }    
    n = bcccnt;
    Q = qread();
    rep(i, Q) {
        int u = qread(), v = qread();
        u = bccID[u];
        v = bccID[v];
        qu.pb(u);
        qv.pb(v);
    }
    lca::init();
    rep(i, Q) {
        int u = qu[i], v = qv[i];
        int lca = lca::lca(u, v);
        int ans = cnt[u] + cnt[v] - 2 * cnt[lca] + ((fromCycle[lca]) ? 1 : 0);
        printf("%lld\n", qpow(2, ans));
    }
}
int main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
