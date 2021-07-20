
// Problem : D. Fight with Monsters
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = 1; (i) <= (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
int n, a, b, k;
const int N = 200020;
struct Monster {
	int h, c, need;
}m[N];
int calc(int x) {
	return (x + a - 1) / a;
}
int main() {
	cin >> n >> a >> b >> k;
	repn(i, n) cin >> m[i].h;
	repn(i, n) {
		int h = m[i].h;
		h %= (a + b);
		if (h == 0) h = a + b;
		m[i].need = calc(h) - 1;
	//	cerr << i << ' ' << m[i].need << endl;
	}
	sort(m + 1, m + n + 1, [](Monster a, Monster b) {
		return a.need < b.need;
	});
	int sum = 0, ans = 0;
	repn(i, n) {
		if (sum + m[i].need <= k) {
			sum += m[i].need;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
