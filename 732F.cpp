#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define VPII vector <PII>
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
const int N = 411451;
VPII G[N]; int n, m; VI T[N];
int bcccnt, bccID[N], sz[N];
vector < VI > bcc;
namespace tarjan {
    int dfn[N], low[N], tot;
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
            VI yuki;
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                bccID[cur] = bcccnt;
                yuki.pb(cur);
                sz[bcccnt]++;
                if (cur == u) 
                    break;
            }
            bcc.pb(yuki);
        }
    }
}
VPII ans;
map <PII, int> e;
int vis[N];
PII minmax(int u, int v) {
    return mp(min(u, v), max(u, v));
}
void dfs(int u) {
    vis[u] = true;
    for (auto edge:G[u]) {
        int v = edge.first;
        if (bccID[v] == bccID[u])
            ans[e[minmax(u, v)]] = mp(v, u);
        else
            ans[e[minmax(u, v)]] = mp(u, v);
        if (!vis[v])
            dfs(v);
    }
}
void solve() {
    n = qread();
    m = qread();
    rep(i, m) {
        int u = qread(), v = qread();
        G[u].pb(mp(v, i));
        G[v].pb(mp(u, i));
        e.insert(mp(minmax(u, v), i));
    }
    repn(i, n)
        if (!tarjan::dfn[i]) 
            tarjan::tarjan(i);
    repn(u, n)
        for (auto e:G[u]) {
            int v = e.first;
            if (bccID[u] != bccID[v]) {
                T[bccID[u]].pb(bccID[v]);
            }
        }
    int* mx = max_element(sz + 1, sz + bcccnt + 1);
    printf("%d\n", *mx);
    int mxid = mx - (sz + 1);
    ans.resize(m);
    dfs(bcc[mxid][0]);
    rep(i, m) printf("%d %d\n", ans[i].first, ans[i].second);
}
int main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
