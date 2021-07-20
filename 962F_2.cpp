
// Problem: F. Simple Cycles Edges
// Contest: Codeforces - Educational Codeforces Round 42 (Rated for Div. 2)
// URL: https://codeforces.com/contest/962/problem/F
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
const int N = 100010;
int bcccnt, bccID[N], bccSize[N];
int n, m;
VPII G[N]; VI T[N];
vector <VPII> bcc;
map <PII, int> me;
VI E[N];
namespace tarjan {
    int dfn[N], tot, low[N];
    stack <PII> s;
    void tarjan(int u, int f = -1) {
        dfn[u] = low[u] = ++tot;
        int sz = 0;
        for (auto e: G[u]) {
            int v = e.first;
            ++sz;
            if (v == f) continue;
            if (!dfn[v]) {
                s.push(mp(u, v));
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if ((dfn[u] == 1 && sz > 1) || (dfn[u] > 1 && dfn[u] <= low[v])) {
                    VPII mirai;
                    PII t;
                    while ((t = s.top()) != mp(u, v)) {
                        mirai.pb(t);
                        s.pop();
                    }
                    mirai.pb(s.top());
                    s.pop();
                    bcc.pb(mirai);
                }
            } else if (dfn[u] > dfn[v]) {
                low[u] = min(low[u], dfn[v]);
                s.push(mp(u, v));
            }
        }
    }
}
void solve() {
    n = qread();
    m = qread();
    repn(i, m) {
        int u = qread(), v = qread();
        G[u].pb(mp(v, i));
        G[v].pb(mp(u, i));
        me[mp(u, v)] = me[mp(v, u)] = i;
    }
    repn(i, n)
        if (!tarjan::dfn[i]) {
            tarjan::tarjan(i);
            VPII eleanor;
            while (!tarjan::s.empty()) {
                eleanor.pb(tarjan::s.top());
                tarjan::s.pop();
            }
            bcc.pb(eleanor);
        }
    repn(u, n)
        for (auto e: G[u]) {
            int v = e.first;
            if (bccID[u] != bccID[v]) {
                T[bccID[u]].pb(bccID[v]);
            }
        }
    n = bcccnt;
    set <int> ans;
    for (auto component: bcc) {
        set <int> distinct;
        for (auto i:component) {
            distinct.insert(i.first);
            distinct.insert(i.second);
        }
        if (distinct.size() == component.size()) {
            for (auto i: component)
                ans.insert(me[i]);
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto e: ans)
        printf("%d ", e);
    puts("");
}
int main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
