
// Problem: D. Mr. Kitayuta's Colorful Graph
// Contest: Codeforces - Codeforces Round #286 (Div. 1)
// URL: https://codeforc.es/contest/506/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
    while (c != '-' && !isdigit(c)) c = getchar();
    if (c == '-') c = getchar(), neg = -1;
    while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
    return neg * val;
}
const int N = 200020;
class DSU {
private:
    int fa[N + 10], sz[10 + N];
public:
    DSU() {
        rep(i, N) fa[i] = i;
        fill(sz, sz + N, 1);
    }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
}dsu;
int n, m, Q;
struct Query {
    int u, v;
    Query(){}
    Query(int qu, int qv) {
        u = min(qu, qv);
        v = max(qu, qv);
    }
};
vector <Query> q;
struct Edge {
    int u, v, c;
    Edge(){}
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};
vector <Edge> e;
vector <int> small;
void solve() {
    n = qread(); m = qread();
    rep(i, m) {
        int u = qread(), v = qread(), c = qread();
        e.pb(Edge(--u, --v, c));
    }
    Q = qread();
    rep(i, Q) {
        int u = qread(), v = qread();
        q.pb(Query(u, v));
    }
    
}
int main() {
    int T = 1;
    //T = qread();
    while (T--) solve();
    return 0;
}
