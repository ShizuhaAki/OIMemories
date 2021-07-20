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
const int N = 200010;
int a[N], n, pre1[N], pre2[N], cnt1, cnt2, ans = 0;
bool check(int mid) {
//	cerr << "CHECK " << mid << endl;
	for (int i = n + 1; i >= 1 && i + (n * 2 - 2 * mid) - 1 >= n /*&& i + (n * 2 - 2 * mid) - 1 <= 2 * n*/ ; i--) {
		if (i + (n * 2 - 2 * mid) - 1 > 2 * n) continue;
		int c1 = pre1[i + (2 * n - 2 * mid) - 1] - pre1[i - 1];
		int c2 = pre2[i + (2 * n - 2 * mid) - 1] - pre2[i - 1];
//		cerr << c1 << ' ' << c2 << endl; 
		if (cnt1 - c1 == mid && cnt2 - c2 == mid) return true;
	}
//	cerr << "FAILED" << endl;
	return false;
}
int main() {
	int T; cin >> T;
	while (T--) {
		memset(a, 0, sizeof(a));
		memset(pre1, 0, sizeof(pre1));
		memset(pre2, 0, sizeof(pre2));
		cnt1 = 0;
		cnt2 = 0;
		cin >> n; repn(i, 2 * n) cin >> a[i];
		repn(i, 2 * n) {
			pre1[i] = pre1[i - 1] + (a[i] == 1);
			pre2[i] = pre2[i - 1] + (a[i] == 2);
			cnt1 += (a[i] == 1);
			cnt2 += (a[i] == 2);
		}
//		cerr << cnt1 << ' ' << cnt2 << endl;
		if (cnt1 == cnt2) {
			cout << 0 << endl;
			continue;
		}
		int L = 0, R = 2 * n;
		while (L + 1 < R) {
			int mid = (L + R) >> 1;
//			cerr << L << ' ' << R << ' ' << mid << endl;
			if (check(mid)) L = mid; else R = mid;
		}
//		cerr << "ANSWER:";
		cout << 2 * n - 2 * L << endl;
	}
	return 0;
}

