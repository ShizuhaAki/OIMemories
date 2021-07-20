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

int main() {
	int T; cin >> T;
	while (T--) {
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		if (a > b) swap(a, b);
		int ans = b - a;
		while (x && a > 1) {
			a--;
			x--;
			ans++;
		}
		while (x && b < n) {
			b++;
			x--;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

