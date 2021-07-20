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
const int N = 303030;

int bcccnt, tot; int bccID[N];
vector <PII> G[N];
int n, m, Q;
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
            } else if (e.second != ed)
                low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            bcccnt++;
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                bccID[cur] = bcccnt;
                if (cur == u) 
                    break;
            }
        }
    }
}
VI T[N];

namespace hld {
    int dfn[N], dep[N], top[N], sz[N], hson[N], fa[N], tot; 
    void dfs1(int u) {
        sz[u] = 1;
        for (auto v:T[u]) 
            if (v != fa[u]) {
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
        tot++;
        dfn[u] = tot;
        if (hson[u]) dfs2(hson[u], t);
        for (auto v:T[u]) 
            if (v != hson[u] && v != fa[u]) 
                dfs2(v, v);
    }
    void init(int t) {
        dep[t] = 1;
        fa[t] = 1;
        dfs1(t);
        dfs2(t, t);
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
}
int comp[N];
void dfs(int u, int f, int cid) {
  //  fprintf(stderr, "DFS(%d, %d, %d)\n", u, f, cid);
    comp[u] = cid;
    for (auto v:T[u])
        if (v != f) 
            dfs(v, u, cid);
}
struct Query {
    int u, v;
    Query(){}
    Query(int qu, int qv) {
        u = qu;
        v = qv;
    }
};
vector <Query> q;
int up[N], down[N]; 
bool vis[N];
void dfs(int u, int f) {
    vis[u] = true;
    for (auto v:T[u]) {
        if (v == f)
            continue;
        dfs(v, u);
        up[u] += up[v];
        down[u] += down[v];
    }
    if (up[u] && down[u]) {
        puts("No");
        exit(0);
    }
}
void solve() {
    n = qread(); 
    m = qread(); 
    Q = qread();
    rep(i, m) {
        int u = qread(), v = qread();
        G[u].pb(mp(v, i));
        G[v].pb(mp(u, i));
    }
    m = 0;    // reset m for building new graph
    repn(i, n)
        if (!tarjan::dfn[i])
            tarjan::tarjan(i);
//    repn(i, n) fprintf(stderr, "%d\n", bccID[i]);
    repn(u, n)
        for (auto ve:G[u]) {
            int v = ve.first;
            if (bccID[u] != bccID[v]) {
//                fprintf(stderr, "Connected %d, %d\n", bccID[u], bccID[v]);
                T[bccID[u]].pb(bccID[v]);
            }
        }
    n = bcccnt;
    int cid = 0;
    repn(i, n)
        if (!comp[i]) {
            dfs(i, 0, ++cid);
            hld::init(i);
        }
//    repn(i, n) fprintf(stderr, "%d ", comp[i]);
    fprintf(stderr, "\n");
    rep(i, Q) {
        int u = qread(), v = qread();
        u = bccID[u];
        v = bccID[v];
        if (comp[u] != comp[v]) {
  //          fprintf(stderr, "Failed on connectivity test\n");
            puts("No");
            return;
        } 
        q.pb(Query(u, v));
    }
    rep(i, Q) {
        int u = q[i].u, v = q[i].v;
        int lca = hld::lca(u, v);
 //       fprintf(stderr, "u = %d, lca = %d, v = %d\n", u, lca, v);
        if (u == v)
            continue;
        up[u]++;
        up[lca]--;
        down[v]++;
        down[lca]--;
    }
    repn(i, n) 
        if (!vis[i]) 
            dfs(i, -1);
    puts("Yes");
}
int main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
