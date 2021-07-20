/*
ID: yzshang1
LANG: C++11
TASK:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 10000;
LL a[N], fact[N], inv[N], n, m;
const int MOD = 1e9 + 7;
LL qpow(LL a, LL b, LL p = MOD) {
	LL ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}
void prework() {
	fact[0] = 1;
	for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
}
LL getInv(LL x) {
	return qpow(x, MOD - 2);
}
LL C(int m, int n) {
	return fact[n] * (getInv(fact[m]) * getInv(fact[n - m]) % MOD) % MOD;
}
int main() {
	cin >> n >> m;
	prework();
	cout << C(2 * m, n + 2 * m - 1) % 	MOD << endl;
	return 0;
}

