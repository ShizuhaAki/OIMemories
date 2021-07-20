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
const int N = 2020;
int n, k;
int main() {
	cin >> n >> k;
	int ans = 0;
	repn(i, n) {
		int x;
		cin >> x;
		if (x + k <= 5)ans++;
	}
	cout << ans / 3 << endl;
	return 0;
}

