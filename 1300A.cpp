
// Problem : A. Non-zero
// Contest : Codeforces Round #618 (Div. 2)
// URL : https://codeforces.com/contest/1300/problem/A
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
int main() {
	int T = qread();
	while (T--) {
		vector <int> a;
		int n = qread(), sum = 0, prod = 1, zero = 0;
		rep(i, n) {int x = qread(); a.pb(x); sum += x; prod *= x; if (!x)zero++;}
		int ans = zero;
		if (zero + sum == 0) ans++;		
		cout << ans << endl;
	}
	return 0;
}
