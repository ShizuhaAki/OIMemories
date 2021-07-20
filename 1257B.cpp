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
		int a, b;
		cin >> a >> b;
		if (a == 3 && b > 3) cout << "NO" << endl;
		else if (a == 2 && b > 3) cout << "NO" << endl;
		else if  (a == 1 && b != 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}

