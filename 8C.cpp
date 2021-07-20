#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
struct Point {
	int x; int y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};
vector <Point> target; Point handbag;
int n;
const int N = 25;
int dp[lsh(N)], route[lsh(N)];
int dis(Point x, Point y) {
	return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y);
}
int main() {
	cin >> handbag.x >> handbag.y;
	cin >> n;
	rep(i, n) {
		Point now;
		cin >> now.x >> now.y;
		target.pb(now);
	}
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	rep(s, lsh(n)) {
		if (dp[s] == INF) continue;
		rep(i, n) {
			if ((lsh(i) & s)) continue;
			if (dp[s | (lsh(i))] > dp[s] + dis(handbag, target[i]) * 2) {
				dp[s | lsh(i)] = dp[s] + dis(handbag, target[i]) * 2;
				route[s | lsh(i)] = s; 
			}
			rep(j, n) {
				if (lsh(j) & s) continue;
				if (dp[s | lsh(i) | lsh(j)] > dp[s] + dis(handbag, target[i]) + dis(target[i], target[j]) + dis(target[j], handbag)) {
					dp[s | lsh(i) | lsh(j)] = dp[s] + dis(handbag, target[i]) + dis(target[i], target[j]) + dis(target[j], handbag);
					route[s | lsh(i) | lsh(j)] = s;
				}
			}
			break;
		}
	}
	cout << dp[lsh(n) - 1] << endl;
	vector <int> ans;
	int now = lsh(n) - 1;
	while (now) {
		int nxt = route[now];
		int dif = nxt ^ now;
		cout << 0 << ' ';
		rep(i, n) if (lsh(i) & dif) cout << i + 1 << ' ';
		if (!nxt) cout << 0;
		now = nxt;
	}
	cout << endl;
	return 0;
}

