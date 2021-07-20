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

int main() {
	int T; cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		if (x == 0 && y != 0) cout << "no" << endl;
		else if (x < y / 2) cout << "no" << endl;
		else if ((x + y) % 3 == 0) cout << "yes" << endl; else cout << "no" << endl;
	}
	return 0;
}

