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
		int a, b, c, n;
		cin >> a >> b >> c >> n;
		int sum = a + b + c + n, each = sum / 3;
		if (sum % 3 == 0 && each >= a && each >= b && each >= c) puts("YES"); else puts("NO");
	}
	return 0;
}

