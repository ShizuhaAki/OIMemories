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
int n, a[N], cnt;

int main() {
	int T; cin >> T;
	while (T--) {
		memset(a, 0, sizeof(a));
	//	memset(pre, 0, sizeof(pre));
	//	memset(minr, INF, sizeof(minr));
		cnt = 0;
		cin >> n;
		repn(i, 2 * n) {
			int x;
			cin >> x;
			if (x == 2) x = -1;
			a[i] = x;
			cnt += a[i];
		}	
		if (cnt == 0)  {
			cout << 0  << endl;
			continue;
		}
//		cerr << "CNT = " << cnt << endl;
		int change = 0;
		map <int, int> r; 
		int ans = INF;
		for (int i = n + 1; i <= 2 * n; i++)  {
			change += a[i];
			if (r[change] == 0)r[change] = i;
//			cerr << "ASSIGNED " << i << " TO r[" << change << "]" << endl; 
		}
		if (r.count(cnt)) ans = r[cnt] - n;
		change = 0;
		for (int i = n; i >= 1; i--) {
			change += a[i];
//			cerr << change << endl;
			if (change == cnt) ans = min(ans, n - i + 1);
			if (r.count(cnt - change) && (r[cnt - change] - i + 1) % 2 == 0)
				ans = min(ans, r[cnt - change] - i + 1);
		}
		cout << ans << endl;
	}
	return 0;
}
/*
INPUT:
1
3
1 1 1 1 2 1
EXPECTED OUTPUT:
4
*/

