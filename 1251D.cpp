#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int long long
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 200020;
int n, s;
struct Chtholly {
	int l, r;
}a[N];
bool check(int x) {
	int res = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if ()
	}
	return res <= s;
}
main() {
	int T; cin >> T;
	while (T--) {
		cin >> n >> s;
		int L = 0, R = INF;
		repn(i, n) {
			cin >> a[i].l >> a[i].r;
			L = max(L, a[i].l); R = min(R, a[i].r);
		}
		sort(a + 1, a + n + 1, [](Chtholly a, Chtholly b) {
			return a.l > b.l;
		});
		while (L < R) {
			int mid = (L + R) >> 1;
			if (check(mid)) 
				L = mid + 1;
			else 
				R = mid - 1;
		}
		cout << L << endl;
	} 
	return 0;
}

