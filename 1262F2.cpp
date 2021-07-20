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
const int N = 200020, MOD = 998244353;
int n, k;
LL a[N], fact[N], inv[N];
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
	for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
}
LL getInv(LL x) {
	return qpow(x, MOD - 2);
}
LL C(int m, int n) {
	return fact[n] * (getInv(fact[m]) * getInv(fact[n - m]) % MOD) % MOD;
}
int getNextIndex(int x) {
	int nxt = x + 1;
	if (nxt == n + 1) return 1;
	else return nxt;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	prework();
	if (n == 1 || k == 1) {
		cout << 0 << endl;
		return 0;
	}
	LL ans = 0, fix = 0;
	for (int i = 1; i <= n; i++) if (a[i] != a[getNextIndex(i)]) fix++;
	for (int i = 0; i * 2 <= fix; i++) {
		ans += C(i, fix) * C(i, fix - i) % MOD * qpow(k - 2, fix - 2 * i) % MOD;
		ans %= MOD;
	}
	cout << (qpow(k, n) - (qpow(k, n - fix) * ans % MOD) + MOD) % MOD / 2;
	return 0;
}

