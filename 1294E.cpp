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
const int N = 200020;
vector < vector <int> > a;
map <int, int> qwq;
#define mov first
#define freq second
int n, m;
int main() {
	cin >> n >> m;
	a.resize(n + 1);
	repn(i, n) a[i].resize(m + 1);
	repn(i, n) repn(j, m) cin >> a[i][j];
	int ans = 0;
	repn(j, m) {
		qwq.clear();
		repn(i, n) {
			if (a[i][j] % m == j % m  && a[i][j] <= n * m) {
				int t = a[i][j] / m + (int)(bool)(a[i][j] % m);
				int d = i - t;
				if (d < 0) d = n + d;
				qwq[d]++;
			}
		}
		int res = 0;
		for (auto it = qwq.begin(); it != qwq.end(); it++) {
			res = max(res, it -> freq - it -> mov);
		}
		ans += n - res;
	}
	cout << ans << endl;
	return 0;
}

