
// Problem: F. Moving Points
// Contest: Codeforces - Codeforces Round #624 (Div. 3)
// URL: https://codeforces.com/contest/1311/problem/F
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
#define int long long
#define all(x) x.begin(),  x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
#define il inline
#define RESET(x) memset((x), 0, sizeof(x))


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
const int N = 200000;
struct node {
    int x, v;
    node(int x = 0, int v = 0): x(x), v(v) {}
    bool operator < (const node& b) const {
        if (x != b.x) return x < b.x;
        return v < b.v;
    }
};
struct BIT {
    int tr[N + 15];
    void add(int x, int v = 1) {
        for (; x <= N; x += x & -x) {
            tr[x] += v;
        }
    }
    int que(int x) {
        int ret = 0;
        for (; x; x -= x & -x) {
            ret += tr[x];
        }
        return ret;
    }
}cnt, dist;
vector <node> p;
vector <int> D;
int n;
void solve() {
    n = qread();
    p.resize(n);
    rep(i, n) p[i].x = qread(); rep(i, n) p[i].v = qread();
    sort(all(p));
    vector <int> d;
    rep(i, n) d.pb(p[i].v);
    sort(all(d)); d.erase(unique(all(d)), d.end());
    D.resize(n);
    rep(i, n) D[i] = lower_bound(all(d), p[i].v) - d.begin() + 1;
    int ans = 0;
    rep(i, n) {
        dist.add(D[i], p[i].x);
        cnt.add(D[i]);
        int c = cnt.que(D[i]), L = dist.que(D[i]);
        ans += c * p[i].x - L;
    }
    printf("%lld\n", ans);
}
signed main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
