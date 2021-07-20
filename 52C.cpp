
// Problem : C. Circular RMQ
// Contest : Codeforces Testing Round #1
// URL : https://codeforces.com/contest/52/problem/C
// Memory Limit : 256 MB
// Time Limit : 1500 ms
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
const int N = 1000010;
struct SegTreeNode {
	LL v, tag;
}t[N];
LL a[N];
inline void pushup(int p) {
	t[p].v = min(t[p << 1].v, t[p << 1 | 1].v);
}
inline void pushdown(int p) {
	if (t[p].tag) {
		t[p << 1].v += t[p].tag;
		t[p << 1 | 1].v += t[p].tag;
		t[p << 1].tag += t[p].tag;
		t[p << 1 | 1].tag += t[p].tag;
		t[p].tag = 0;
	}
}
void build(int p, int l, int r) {
	if (l == r) {
		t[p].v = a[l];
		t[p].tag = 0; 
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
void modify(int p, int l, int r, int ql, int qr, int v) {
	if (ql <= l && r <= qr) {
		t[p].v += v;
		t[p].tag += v;
		return;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if (ql <= mid) modify(p << 1, l, mid, ql, qr, v);
	if (qr > mid) modify(p << 1 | 1, mid + 1, r, ql, qr, v);
	pushup(p);
} 
LL query(int p, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return t[p].v;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	LL ans = INF;
	if (ql <= mid) ans = query(p << 1, l, mid, ql, qr);
	if (qr > mid) ans = min(ans, query(p << 1 | 1, mid + 1, r, ql, qr));
	return ans;
}
int n;
signed main() {
	n = qread(); repn(i, n) a[i] = qread(); build(1, 1, n);
	int m = qread();
	while (m--) {
		string s;
		getline(cin, s);
		stringstream ss; ss << s;
		int tmp = 0;
		for (char c:s) if (c == ' ') tmp++;
		if (tmp >= 2) {
			int l, r, v;
			ss >> l >> r >> v; ++l; ++r;
			if (l <= r) modify(1, 1, n, l, r, v);
			else {modify(1, 1, n, l, n, v); modify(1, 1, n, 1, r, v);}
		}
		else {
			int l, r;
			ss >> l >> r;  ++l; ++r;
			LL ans = INF;
			if (l <= r) ans = query(1, 1, n, l, r);
			else ans = min(query(1, 1, n, l, n), query(1, 1, n, 1, r));
			cout << ans << endl;
		}
	}
	return 0;
}
