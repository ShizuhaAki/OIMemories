#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int MOD = 1e9 + 7;
const int N = 2019;
struct dsu {
	int fa[N];
	void makeSet(int n) {repn(i, n) fa[i] = i;}
	int find(int x) {
		return x == fa[x] ? x: fa[x] = find(fa[x]);
	}
	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx != fy) fa[fx] = fy;
	}
	int count(int n) {
		int ans = 0;
		for (int i = 1; i <= n; i++) if (fa[i] == i) ans++;
		return ans;	
	}
}s;
int n, m, k;
LL qpow(LL a, LL b, LL p) {
	LL ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	s.makeSet(n);
	for (int i = 1; i + k - 1 <= n; i++)
		for (int j = i, p = i + k - 1; j <= p; j++, p--) 
			s.merge(j, p);
	printf("%d", (int)qpow(m, s.count(n), MOD));
	return 0;
}

