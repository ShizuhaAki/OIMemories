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
		int n, d;
		cin >> n >> d;
		int ans = INF;
		int sq = sqrt(d);
		for (int i = max(sq - 5, 0); i <= min(sq + 5, d); i++) ans = min(ans, i + (int)ceil(d / (double)(i + 1)));
		cout << ((ans <= n) ? "YES" : "NO") << endl;
	} 
	return 0;
}

