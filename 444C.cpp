
// Problem : C. DZY Loves Colors
// Contest : Codeforces Round #254 (Div. 1)
// URL : https://codeforces.com/contest/444/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
typedef pair <int, int> PII;
#define int long long
#define all(x) (x.begin(),  x.end())
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
const int N = 800010;
int n, m;
int ans;
int lazy[N], sum[N];
inline void pushdown(int p, int l, int r) {
	sum[p] += lazy[p] * (r - l + 1);
	if (l != r) {
		lazy[p << 1] += lazy[p];
		lazy[p << 1 | 1] += lazy[p];
	}
	lazy[p] = 0;
}
inline void pushup(int p) {
	sum[p] = sum[p << 1] + sum[p << 1 | 1];
}
void modify(int p, int l, int r, int ql, int qr, int v) {
	if (lazy[p]) pushdown(p, l, r);
	if (r < ql || qr < l) return;
	if (ql <= l && r <= qr) {
		lazy[p] = v;
		pushdown(p, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	modify(p << 1, l, mid, ql, qr, v);
	modify(p << 1 | 1, mid + 1, r, ql, qr, v);
	pushup(p);
}
void ask(int p, int l, int r, int ql, int qr) {
	if (lazy[p]) pushdown(p, l, r);
	if (r < ql || qr < l) return;
	if (ql <= l && r <= qr) {ans += sum[p]; return;}
	int mid = (l + r) >> 1;
	ask(p << 1, l, mid, ql, qr);
	ask(p << 1 | 1, mid + 1, r, ql, qr);
}
struct node {
	int l, r;
	mutable int v;
	node(int l, int r = -1, int v = 0) : l(l), r(r), v(v) {}
	inline bool operator < (const node& b)const {return l < b.l;}
};
set <node> chtholly;
set <node> :: iterator split(int x) {
	//if (x > n) return chtholly.end();
	auto it = chtholly.lower_bound(node(x));
	if (it != chtholly.end() && it -> l == x) return it;
	--it;
	int l = it -> l, r = it -> r, v = it -> v;
	chtholly.erase(it);
	chtholly.insert(node(l, x - 1, v));
	return chtholly.insert(node(x, r, v)).first;
}
void assign(int l, int r, int v) {
	auto itr = split(r + 1), itl = split(l);
	auto it = itl;
	for (; it != itr; ++it) {
		int lV = it -> l, rV = it -> r, vV = abs(v - it -> v);
		modify(1, 1, n, lV, rV, vV);
	}
	chtholly.erase(itl, itr);
	chtholly.insert(node(l, r, v));
}

signed main() {
	n = qread(); m = qread(); repn(i, n) chtholly.insert(node(i, i, i));
	rep(i, m) {
		int op = qread();
		if (op == 1) {
			int l = qread(), r = qread(), v = qread();
			assign(l, r, v);
		}
		else {
			ans = 0;
			int l = qread(), r = qread();
			ask(1, 1, n, l, r);
			cout << ans << endl;
		}
	}
	return 0;
}
