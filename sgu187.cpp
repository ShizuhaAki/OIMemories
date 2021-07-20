#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
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
const int N = 130003;
int l[N], r[N], key[N], cnt[N], aux[N];
bool flip[N];
int n, m;
int tot;
void rot(int p) {
    swap(l[p], r[p]);
    flip[p] ^= 1;
}
void pushdown(int p) {
    if (flip[p]) {
        flip[p] = false;
        rot(l[p]);
        rot(r[p]);
    }
}
void pushup(int p) { cnt[p] = cnt[l[p]] + 1 + cnt[r[p]];}
void split(int p, int k, int& a, int &b) {
    cerr << "SPLIT " << p << ' ' << k << ' ' << a << ' ' << b << endl;
    if (!p) {a = b = 0; return;}
    pushdown(p);
    if (k <= cnt[l[p]]) {
        b = p;
        split(l[p], k, a, l[b]);
    } else {
        a = p;
        split(r[p], k - 1 - cnt[l[p]], r[a], b);
    }
    pushup(p);
}
void merge(int &p, int a, int b) {
    cerr << "MERGE " << p << ' ' << a << ' ' << b << endl;
    if (!a || !b) {p = max(a, b); return;}
    if (aux[a] < aux[b]) {
        pushdown(a);
        p = a; 
   //     pushup(a);
        merge(r[p], r[a], b);
    } else {
        pushdown(b);
        p = b;
    //    pushup(b);
        merge(l[p], a, l[b]);
    }
    pushup(p);
}
void ins(int &p, int x) {
    cerr << "INS " << p << ' ' << x << endl;
    ++tot;
    key[tot] = x;
    aux[tot] = rand();
    l[tot] = r[tot] = 0;
    pushup(tot);
    merge(p, p, tot);
}
int root;
void rev(int L, int R) {
 //   cerr << "REV " << L << ' ' << R << endl;
    int a, b;
    L--;
    split(root, L, root, a);
    split(a, R - L, a, b);
//    assert(cnt[a] == R - L);
    flip[a] ^= 1; swap(l[a], r[a]);
    merge(a, a, b);
    merge(root, root, a);
}
void print(int p) {
  //  cerr << "PRINT " << p << endl;
    if (!p) return;
    pushdown(p);
    print(l[p]);
    printf("%d ", key[p]);
    print(r[p]);
}
void solve() {
    freopen("/home/shushang/log1", "w", stderr);
    cerr << "==========================" << endl;
    srand(19260817);
    n = qread(); m = qread();
    repn(i, n) ins(root, i);
    rep(i, m) {
        int x = qread(), y = qread();
        rev(x, y);
    }
    print(root);
}
int main() {
	int T = 1;
    //int T = qread();
    while (T--) solve();
	return 0;
}
