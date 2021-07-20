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
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
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
int n, q, r;
const int N = 150000;
struct Matrix {
	int v[2][2];
	void clear() {rep(i, 2) rep(j, 2) v[i][j] = 0;}
    Matrix operator * (Matrix b) {
        Matrix res;
        res.clear();
        rep(i, 2)
            rep(j, 2)
                rep(k, 2)
                    res.v[i][j] = (res.v[i][j] + v[i][k] * b.v[k][j]) % r;

        return res;
    }
    void assign_val(int x, int y, int va) {v[x][y] = va;}
    int get_val(int x, int y) {return v[x][y];}
};
Matrix a[N];
void read_matrix(int id) {
	int a00 = qread(), a01 = qread(), a10 = qread(), a11 = qread();
	a[id].assign_val(0, 0, a00);
	a[id].assign_val(0, 1, a01);
	a[id].assign_val(1, 0, a10);
	a[id].assign_val(1, 1, a11); 
}
void print_matrix(Matrix m) {
	rep(i, 2)
		printf("%d %d\n", m.get_val(i, 0), m.get_val(i, 1));
	puts("");
}
#define lson(p) ((p) << 1)
#define rson(p) ((p) << 1 | 1)
Matrix ask(int p, int l, int r, int ql, int qr) {
	if (ql == l && qr == r) return a[p];
	int mid = (l + r) >> 1;
	if (qr <= mid) return ask(lson(p), l, mid, ql, qr);
	else if (ql > mid) return ask(rson(p), mid + 1, r, ql, qr);
	else return ask(lson(p), l, mid, ql, mid) * ask(rson(p), mid + 1, r, mid + 1, qr);
}
int main() {
#ifndef CHTHOLLY
	freopen("crypto.in", "r", stdin);
	freopen("crypto.out", "w", stdout);
#endif
	r = qread(); n = qread(); q = qread();
	int rst = 1; while (rst < n) rst <<= 1;
	rep(i, n) read_matrix(i + rst);
	for (int i = rst - 1; i; i--) a[i] = a[lson(i)] * a[rson(i)];
	while (q--) {
		//cerr << q << endl; 
		int l = qread(), r = qread();
		//cerr << l << ' ' << r << endl;
		auto ans = ask(1, 1, rst, l, r);
		print_matrix(ans);
	}
	return 0;
}