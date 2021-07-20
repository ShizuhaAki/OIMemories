
// Problem : Limited Swaps
// Contest : CSAcademy
// URL : https://csacademy.com/contest/round-22/task/limited-swaps/
// Memory Limit : 128 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
typedef pair <int, int> PII;
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
const int N = 100010;
int a[N], n, k;
struct SegTreeNode {
	int mx;
	int skip;
	int pos;
	int cnt;
	SegTreeNode():mx(-1), skip(0), pos(-1), cnt(false) {}
}t[N * 4];
#define ls (p << 1)
#define rs (p << 1 | 1)
inline SegTreeNode makeNode(SegTreeNode a, SegTreeNode b) {
	SegTreeNode ret;
	ret.cnt = a.cnt + b.cnt;
	if (a.mx >= b.mx) {
		ret.mx = a.mx;
		ret.skip = a.skip;
		ret.pos = a.pos;
	}
	else {
		ret.mx = b.mx;
		ret.skip = b.skip + a.cnt;
		ret.pos = b.pos;
	}
	return ret;
}
void build(int p, int l, int r) {
	if (l == r) {
		t[p].mx = a[l];
		t[p].cnt = true;
		t[p].skip = 0;
		t[p].pos = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	t[p] = makeNode(t[ls], t[rs]);
}
SegTreeNode getMax(int p, int l, int r, int k) {
	if (k < 0) return SegTreeNode();
	if (t[p].skip <= k) return t[p];
	int mid = (l + r) >> 1;
	return makeNode(getMax(ls, l, mid, k), getMax(rs, mid + 1, r, k - t[ls].cnt));
}
void move(int p, int l, int r, int v) {
	if (v < l || r < v) return;
	if (l == r) {t[p] = SegTreeNode(); return;}
	int mid = (l + r) >> 1;
	move(ls, l, mid, v); move(rs, mid + 1, r, v);
	t[p] = makeNode(t[ls], t[rs]);	
}
int solve(int& k) {
	auto node = getMax(1, 0, n - 1, k);
	move(1, 0, n - 1, node.pos);
	k -= node.skip;
	return node.mx;
}
int main() {
	n = qread(); k = qread(); rep(i, n) a[i] = qread();
	build(1, 0, n - 1);
	repn(i, n) {
		cout << solve(k) << ' ';
	}
	return 0;
}
