
// Problem : C. DZY Loves Colors
// Contest : Codeforces - Codeforces Round #254 (Div. 1)
// URL : https://codeforces.com/problemset/problem/444/C
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
struct node {
	int l, r;
	mutable int v;
	node(int l = 0, int r = 0, int v = 0):
		l(l), r(r), v(v) {}
	bool operator < (const node& b) const {return b.l > l;}
};
const int N = 114514;
int n, m;  
int a[N]; 
set <node> seniorious;
int lazy[N * 4], sum[N * 4];
#define ls (p << 1)
#define rs (p << 1 | 1)
inline void pushup(int p) {sum[p] = sum[ls] + sum[rs];}
inline void pushdown(int p, int l, int r) {
	sum[p] += lazy[p] * (r - l + 1); 
	if (l != r) {
		lazy[ls] += lazy[p];
		lazy[rs] += lazy[p];
	}
	lazy[p] = 0;
}
void build(int p, int l, int r) {
	if (l == r) {
		sum[p] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}
void modify(int p, int l, int r, int ql, int qr, int v) {
	pushdown(p, l, r);
	if (r < ql || qr < l) return;
	if (ql <= l && r <= qr) {
		lazy[p] = v;
		pushdown(p, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	modify(ls, l, mid, ql, qr, v);
	modify(rs, mid + 1, r, ql, qr, v);
	pushup(p);
}
int ask(int p, int l, int r, int ql, int qr) {
	pushdown(p, l, r);
	if (r < ql || qr < l) return 0;
	if (ql <= l && r <= qr) return sum[p];
	int ans = 0;
	int mid = (l + r) >> 1;
	ans += ask(ls, l, mid, ql, qr);
	ans += ask(rs, mid + 1, r, ql, qr);
	return ans;
}
auto split(int x) {
	auto it = seniorious.lower_bound(node(x));
	if (it != seniorious.end() && it -> l == x) return it;
	it--;
	int l = it -> l, r = it -> r, v = it -> v;
	seniorious.erase(it);
	seniorious.insert(node(l, x - 1, v));
	return seniorious.insert(node(x, r, v)).first;
}
void assign(int L, int R, int V) {
	auto itr = split(R + 1), itl = split(L);
	for (auto it = itl; it != itr; it++) {
		int l = it -> l, r = it -> r, v = it -> v;
		modify(1, 1, n, l, r, abs(v - V));
	}
	seniorious.erase(itl, itr); seniorious.insert(node(L, R, V));
}
signed main() {
	n = qread(); m = qread();
	repn(i, n) seniorious.insert(node(i, i, i));
	while (m--) {
		int op = qread();
		if (op == 1) {
			int l = qread(), r = qread(), v = qread();
			assign(l, r, v);
		} else {
			int l = qread(), r = qread();
			cout << ask(1, 1, n, l, r) << endl;
		}
	}
	return 0;
}
