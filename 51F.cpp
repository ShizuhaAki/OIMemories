
// Problem: F. Caterpillar
// Contest: Codeforces - Codeforces Beta Round #48
// URL: https://codeforces.com/contest/51/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
const int N = 3030;
VPII G[N]; VI T[N];
int bcccnt, bccID[N], bccSize[N];
int n, m;
namespace tarjan {
    int dfn[N], tot, low[N];
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
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                bccID[cur] = bcccnt;
                bccSize[bcccnt]++;
                if (cur == u) 
                    break;
            }
        }
    }
}
int vis[N], dep[N];

// set $t to the furthest point
// set $d to the maximum depth
void dfs(int u, int f, int &t, int& d) {
   // fprintf(stderr, "%d %d %d %d\n", u, f, t, d);
    vis[u] = true;
//    cerr << "Marked " << u << endl;
    t = u;
    d = 0;
    for (auto v: T[u]) {
        if (v != f) {
            int t2 = -1, d2 = -1;
            dfs(v, u, t2, d2);
            if (d2 + 1 > d) {
                assert(t2 != -1);
                assert(d2 != -1);
                d = d2 + 1;
                t = t2;
            }
        }
    }
}

void solve() {
    n = qread(); 
    m = qread();
    rep(i, m) {
        int u = qread(), v = qread();
        G[u].pb(mp(v, i));
        G[v].pb(mp(u, i));
    }
    repn(u, n)
        if (!tarjan::dfn[u])
            tarjan::tarjan(u);
    repn(u, n)
        for (auto e:G[u]) {
            int v = e.first;
            if (bccID[v] != bccID[u]) {
                T[bccID[u]].pb(bccID[v]);
            }
        }
    int nn = n;
    n = bcccnt;
    int ans = nn - 1;
    repn(i, n) {
        int deg = T[i].size();
        if (deg == 1)
            ans--;
        else if (deg == 0)
            ans -= 2;
    }
   // cerr << ans << endl;
    repn(i, n) 
        if (!vis[i]) {
            int u = 0, v = 0, d = 0;
            dfs(i, 0, u, d);
            dfs(u, 0, v, d);
         //   fprintf(stderr, "%d\n", d);//
            ans -= d - 2;
        }
    printf("%d\n", ans);
            
}
int main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
