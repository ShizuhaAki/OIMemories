
// Problem : A. Display The Number
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/A
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
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;

int main() {
	int T; cin >> T;
	while (T--) {
		int x; cin >> x;
		if (x % 2 == 0) {
			repn(i, x / 2) cout << 1;
			cout << endl;
		}
		else {
			cout << 7;
			repn(i, x / 2 - 1) cout << 1;
			cout << endl;
		}
	}
	return 0;
}
