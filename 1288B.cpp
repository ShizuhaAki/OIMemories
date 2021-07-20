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
#define int long long
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;

void solve() {
	int a, b;
	cin >> a >> b;
	b++;
	int lenb = 0;
	while (b) {
		b /= 10;
		lenb++;
	}
	cout << a * (lenb - 1) << endl;
}
main() {
	int T; cin >> T;
	while (T--) solve();
}

