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
const int N = 10010;
int c[N], sum[N], sol[N];
int main() {
	int n; cin >> n;
	repn(i, n) cin >> c[i] >> sum[i];
	repn(i, n) {
		LL ans = 0;
		if (sum[i] <= c[i]) ans = sum[i];
		else {
			if (c[i] == 1) ans = sum[i] * sum[i];
			else if (sum[i] % c[i] == 0) ans = c[i] * (sum[i] / c[i]) * (sum[i] / c[i]);
			else {
				memset(sol, 0, sizeof(sol));
				repn(j, c[i]) sol[j] += sum[i] / c[i];
				int rem = sum[i] % c[i];
				for (int j = 1; rem; j++, rem--) sol[j]++;
			//	repn(j, n) cout << sol[j] << ' '; cout << endl;
				repn(j, c[i]) ans += sol[j] * sol[j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}

