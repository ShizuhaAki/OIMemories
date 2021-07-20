
// Problem: C - Tourist Reform
// Contest: Virtual Judge - RavenclawOIer's Timed Training 1
// URL: https://vjudge.net/contest/387932#problem/C
// Memory Limit: 262 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define VPII vector <PII>
#define V vector
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
#define il inline
#define vo void
#define I int
#define RESET(x) memset((x), 0, sizeof(x))
#define au auto

const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
LL qread() {
    char c = getchar();
    int neg = 1;
    LL val = 0;
    while (c != '-' && !isdigit(c)) c = getchar();
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
const I N = 500020;
VPII G[N]; VI T[N]; V <VI> bcc; I bccID[N], bcccnt; I n, m, sz[N];
namespace tarjan {
    I dfn[N], low[N], tot; stack <I> s;
    vo tarjan(I u, I eid = 0) {
        dfn[u] = low[u] = ++tot; s.push(u);
        for (auto e: G[u]) {
            int v = e.first, id = e.second;
            if (!dfn[v]) {
                tarjan(v, id);
                low[u] = min(low[u], low[v]);
            } else if (id != eid) low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            bcccnt++;
            VI mirai;
            while (!s.empty()) {
                int t = s.top(); s.pop();
                mirai.pb(t); bccID[t] = bcccnt; sz[bcccnt]++;
                if (t == u) break;
            }
            bcc.pb(mirai);
        }        
    }
}
map <PII, int> yuki;
vector <PII> nagato;
PII norm(I x, I y) {
    return mp(min(x, y), max(x, y));
}
I vis[N];
vo dfs(I u) {
    vis[u] = true;
    for (auto e: G[u])  {
        I v = e.first;
        if (bccID[u] == bccID[v]) nagato[yuki[norm(u, v)]] = mp(u, v); 
        else nagato[yuki[norm(u, v)]] = mp(v, u);
        if (!vis[v]) dfs(v);
    }
}
vo solve() {
    n = qread(); m = qread();
    rep(i, m) {I u = qread(), v = qread(); G[u].pb(mp(v, i)); G[v].pb(mp(u, i)); yuki[norm(u, v)] = i;}
    repn(i, n) if (!tarjan::dfn[i]) tarjan::tarjan(i);
    repn(u, n) for (au e:G[u]) {I v = e.first; if (bccID[u] != bccID[v]) T[bccID[u]].pb(bccID[v]);} n = bcccnt;
    int* mx = max_element(sz + 1, sz + n + 1);
    printf("%d\n", *mx);
    int mxid = mx - (sz + 1);
    nagato.resize(m);
    dfs(bcc[mxid][0]);
    rep(i, m) printf("%d %d\n", nagato[i].second, nagato[i].first);
}
signed main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
