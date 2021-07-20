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
const int N = 200020;
int a[N];
vector <int> occ[N]; 
int main() {
	int T; cin >> T;
	while (T--) {
		int n;
		cin >> n;
		repn(i, n) {
			a[i] = 0;
			occ[i].clear();
		}
		repn(i, n) cin >> a[i], occ[a[i]].pb(i);
		if (n == 1) {
			cout << -1 << endl;
			continue;
		}
		int ans = INF;
		repn(i, n) {
			if (occ[i].size() <= 1) continue;
			rep(j, (int)occ[i].size() - 1) ans = min(ans, abs(occ[i][j + 1] - occ[i][j])); 
		}
		if (ans == INF) cout << -1 << endl;
		else cout << ans + 1 << endl;
	}
	return 0;
}

