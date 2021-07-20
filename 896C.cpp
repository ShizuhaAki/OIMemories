/*
ID: yzshang1
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int long long
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
#define IT set <chtholly> :: iterator
struct chtholly {
	int l, r; mutable LL v;
	chtholly(int l, int r = -1, LL v = 0): l(l), r(r), v(v) {}
	bool operator < (const chtholly b) const {
		return l < b.l; 
	} 
};
set <chtholly> s;
IT split(int pos) {
	IT it = s.lower_bound(pos);
	if (it != s.end() && it -> l == pos) return it;
	--it;
	int L = it -> l, R = it -> r;
	LL V = it -> v;
	s.erase(it);
	s.insert(chtholly(L, pos - 1, V));
	return s.insert(chtholly(pos, R, V)).first;
}
void assign(int l, int r, int v) {
	IT itr = split(r + 1), itl = split(l);
	s.erase(itl, itr);
	s.insert(chtholly(l, r, v));
}
void add(int l, int r, int val) {
	IT itr = split(r + 1), itl = split(l);
	for (; itl != itr; ++itl) {
		itl -> v += val;
	}
}
LL qpow(LL a, LL b, LL p) {
	LL ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}
LL powsum(int l, int r, int e, int p) {
	IT itr = split(r + 1), itl = split(l);
	LL res = 0;
	for (; itl != itr; ++itl) res += 1LL * ((itl -> r) - (itl -> l) + 1) * qpow(itl -> v, e, p);
	return res;
}
LL getrank(int l, int r, int k) {
	vector < pair <LL, int> > vec;
	IT itr = split(r + 1), itl = split(l);
	vec.clear();
	for (; itl != itr; ++itl) vec.pb(mp(itl -> v, (itl -> r) - (itl -> l) + 1));
	sort(vec.begin(), vec.end());
	for (vector < pair <LL, int> > :: iterator it = vec.begin(); it != vec.end(); it++) {
		k = it -> second;
		if (k <= 0) return it -> first;
	}
}
const int N = 200020;
LL n, m, seed, vmax, a[N];
LL rnd() {
	LL ret = seed;
	seed = (seed * 7 + 13) % 1000000007;
	return ret;
}
signed main() {
#ifndef CHTHOLLY
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
#endif
	cin >> n >> m >> seed >> vmax;
	repn(i, n) {
		a[i] = (rnd() % vmax) + 1;
		s.insert(chtholly(i, i, a[i]));
	}
	repn(i, m) {
		LL op, l, r, x, y;
		op = (rnd() % 4) + 1;
		l = (rnd() % n) + 1;
		r = (rnd() % n) + 1;
		if (l > r) swap(l, r);
		if (op == 1) {
			x = (rnd() % vmax) + 1;
			add(l, r, x);
		}
		else if (op == 2) {
			x = (rnd() % vmax) + 1;
			assign(l, r, x);
		}
		else if (op == 3) {
			x = (rnd() % (r - l + 1)) + 1;
			cout << getrank(l, r, x) << endl;
		}
		else if (op == 4) {
			x = (rnd() % vmax) + 1;
			y = (rnd() % vmax) + 1;
			cout << powsum(l, r, x, y) << endl;
		}
	}
	return 0;
}

