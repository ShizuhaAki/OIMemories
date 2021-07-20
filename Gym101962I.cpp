
// Problem : I. Colonial Mansions
// Contest : Codeforces - UFBA Practice Session for Brazilian ICPC Regionals - 2018
// URL : https://codeforces.com/gym/101962/problem/I
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
typedef pair <int, int> PII;
//#define int long long
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


const int N = 500050;


struct segNode {
	int l, r, v;
	segNode(int l = 0, int r = 0, int v = 0): l(l), r(r), v(v) {}
}t[N]; int a[N];


#define ls (p << 1)
#define rs (p << 1 | 1)
void pushup(int p) {
	t[p].l = t[ls].l; t[p].r = t[rs].r;
	t[p].v = max(t[ls].v, max(t[rs].v, abs(t[ls].r - t[rs].l)));
}


void build(int p, int l, int r) {
	if (l == r) {
		t[p].l = t[p].r = a[l];
		t[p].v = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
} 


void modify(int p, int l, int r, int pos, int v) {
	if (pos == l && l == r) {
		t[p].l = t[p].r = v;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) modify(ls, l, mid, pos, v);
	else modify(rs, mid + 1, r, pos, v);
	pushup(p);
}


int query(int p, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return t[p].v;
	int mid = (l + r) >> 1;
	if (mid >= qr) return query(ls, l, mid, ql, qr); 
	else if (mid < ql) return query(rs, mid + 1, r, ql, qr);
	else return max(query(ls, l, mid, ql, qr), max(query(rs, mid + 1, r, ql, qr), abs(t[ls].r - t[rs].l))); 
}
#undef ls
#undef rs


int n, m;
int solve(int p, int v) {
	int res = 0, l, r;
	l = p; r = n;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (query(1, 1, n, l, mid) > v) r = mid;
		else l = mid;
	}    //after this, r = l + 1
	//we then check if we can include r
	//cerr << l << ' ' << r << endl;
	if (abs(a[r] - a[l]) <= v) res += r - p + 1; else res += l - p + 1;
	r = p; l = 1;
	//everything is done reversed after this
	while (l + 1 < r) {
	    int mid = (l + r) >> 1;
		if (query(1, 1, n, mid, r) > v) l = mid;
		else r = mid;
	}
	if (abs(a[r] - a[l]) <= v) res += p - l; else res += p - l - 1;
	return res;
}


int main() {
	n = qread(); m = qread();
	repn(i, n) a[i] = qread();
	build(1, 1, n);
	while (m--) {
		int op = qread(), qa = qread(), qb = qread();
		if (op == 1) {
			modify(1, 1, n, qa, qb);
			a[qa] = qb;
		} else {
			cout << solve(qa, qb) << endl;
		}
	}
	return 0;
}
