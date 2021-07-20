
// Problem : C. Anu Has a Function
// Contest : Codeforces Round #618 (Div. 2)
// URL : https://codeforces.com/contest/1300/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
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
int countbit(int x) {
	int res = 0;
	while (x) {
		x >>= 1;
		res++;
	}
	return res;
}
int main() {
	int n = qread(); vector <int> a;
	rep(i, n) {int x = qread(); a.pb(x);}
	vector <int> p; p.pb(~a[0]);
	repn(i, n - 1) p.pb(p[i - 1] & (~a[i]));
	vector <int> s; s.resize(n); s[n - 1] = ~a[n - 1];
	for (int i = n - 2; i >= 0; i--) s[i] =  s[i + 1] & (~a[i]);
	assert(s.size() == n); 
	assert(p.size() == n);
	int bestv = -1, besti = -1;
	rep(i, n) {
		int v = 2147483647;
		if (i - 1 >= 0) v &= p[i - 1];
		if (i + 1 < n) v &= s[i + 1];
		if (bestv < (v & a[i])) {
			bestv = v & a[i];
			besti = i;
		}
	}
	cout << a[besti] << ' ';
	rep(i, n) if (i != besti)cout << a[i] << ' '; cout << endl;
	return 0;
}
