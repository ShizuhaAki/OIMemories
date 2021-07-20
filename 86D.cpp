/*
ID: yzshang1
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
struct Query {
	int l, r, id;
	Query(int l, int r, int id) : l(l), r(r), id(id){}
	bool operator < (const Query& b) const {
		return mp(l, r) < mp(b.l, b.r);
	}
};
const int N = 1000020;
const int BL = 700;
LL a[N]; vector <Query> q[N];
LL c[N], n, t;
LL ans[N];
LL val;
void dec(int v) {
	val -= (LL)v * (2 * c[v] - 1);
	c[v]--;
}
void inc(int v) {
	val += (LL)v * (2 * c[v] + 1);
	c[v]++;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> t;
	repn(i, n) cin >> a[i];
	rep(i, t) {
		int l, r, d;
		cin >> l >> r;
		d = r / BL;
		q[d].pb(Query(l, r, i));
	}
	int L = 1, R = 0;
	rep(i, n / BL + 1) {
		sort(q[i].begin(), q[i].end());
		rep(j, q[i].size()) {
			Query& cur = q[i][j];
			while (L < cur.l) dec(a[L++]);
			while (L > cur.l) inc(a[--L]);
			while (R < cur.r) inc(a[++R]);
			while (R > cur.r) dec(a[R--]);
			ans[cur.id] = val;
		}
	}
	rep(i, t) cout << ans[i] << endl; 
	return 0;
}

