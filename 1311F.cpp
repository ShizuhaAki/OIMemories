#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define y2 y1919810
typedef pair <int, int> PII;
#define int long long
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
const int N = 200000;
struct Node {
    int x, v;
    Node(int x = 0, int v = 0): x(x), v(v) {}
    bool operator < (const Node& b) const {
        if (x != b.x) return x < b.x;
        else return v < b.v;
    }  
}p[N];
struct BIT {
    int tree[N + 20];
    void add(int x,int v){
        for (; x <= N; x += x & -x) 
            tree[x] += v;    
    }
    int query(int x) {
        int ret = 0;
        for (; x; x -= x & -x)
            ret += tree[x];
        return ret;
    }  
}a, b; int n, cnt[N], dv[N];
vector <int> discrete;
void solve() {
    n = qread();
    rep(i, n) p[i].x = qread(); rep(i, n) p[i].v = qread();
    sort(p, p + n);
    rep(i, n) discrete.pb(p[i].v);
    sort(all(discrete));
  //  unique(all(discrete));
    discrete.resize(unique(all(discrete)) - discrete.begin());
    rep(i, n) dv[i] = lower_bound(all(discrete), p[i].v) - discrete.begin() + 1;
  //  rep(i, n) cerr << dv[i] << ' '; cerr << endl;
    int sum = 0;
    rep(i, n) {
        a.add(dv[i], p[i].x);
        b.add(dv[i], 1);
        sum += b.query(dv[i]) * p[i].x - a.query(dv[i]);
    }
    cout << sum << endl;
}
signed main() {
    int T = 1;
    //int T = qread();
    while (T--) solve();
	return 0;
}
