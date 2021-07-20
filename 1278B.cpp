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
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;

int main() {
	int T; cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y); 
		if (x == y) {
			cout << 0 << endl;
			continue;
		}
		if (y - x == 1) {
			cout << 1 << endl;
			continue;
		}
		if (y - x == 2) {
			cout << 3 << endl;
			continue;
		}
		int dif = y - x, i, mx = -1, m;
		for (i = 1;; i++) {
			LL val = 1LL * i * (i + 1) / 2;
			if (val > dif) {
				if (val % 2 == dif % 2) {
					cout << i << endl;
					goto NXT;
				}
			}
			if (val == dif) {
				cout << i << endl;
				goto NXT;
			}
		}
		NXT:;
	}
	return 0;
}

