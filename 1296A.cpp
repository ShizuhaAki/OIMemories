
// Problem : A. Array with Odd Sum
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/0
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
#define range(i, s, t)  for (int (i) = 1; (i) <= (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n; cin >> n;
		int odd = 0, even = 0;
		repn(i, n) {
			int x;
			cin >> x;
			if (x % 2 == 0) even++;
			else odd++;
		}
		if (odd % 2 == 1 || (odd > 0 && even > 0)) puts("YES");
		else puts("NO");
	}
	return 0;
}
