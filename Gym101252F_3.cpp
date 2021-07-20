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
const int N = 100010;
int c[N], n, dp[N];
vector < vector <int> > ans;
int main() {
	ios::sync_with_stdio(false);
#ifndef CHTHOLLY
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	cin >> n;
	ans.resize(n + 1);
	repn(i, n) cin >> c[i];
	c[0] = INF;
	priority_queue < pair <int, int> > pq;
	pq.push(mp(dp[0], 0));
	vector < pair <int, int> > tmp;
	tmp.clear();
	//cerr << 24 << endl;
	repn(i, n) {
	//	cerr << "i = " << i << endl;
		tmp.clear();
		while (!pq.empty()) {
			auto t = pq.top(); pq.pop();
			tmp.pb(t);
			if (abs(c[t.second] - c[i]) == 1) continue;
			int ansPos = 0;
			if (t.first + 1 >= dp[i]) {
				dp[i] = t.first + 1;
				ansPos = t.second;
				ans[i] = ans[ansPos];
				ans[i].pb(c[i]);
				pq.push(mp(dp[i], i));
			//	cerr << "i = " << i << ", 39#" << endl;
				break;
			}
		}
		rep(j, (int)tmp.size()) pq.push(tmp[j]);
		tmp.clear();
		rep(j, 10) {
			tmp.pb(pq.top());
			pq.pop();
		}
		pq = priority_queue < pair <int, int> >();
		rep(j, (int)tmp.size()) pq.push(tmp[j]);
	} 
//	cerr << 42 << endl;
	int bestv , besti; bestv = besti = -1;
	repn(i, n) {
		if (dp[i] > bestv) {
			bestv = dp[i];
			besti = i;
		}
	}
	cout << n - bestv << endl;
	rep(i, (int)ans[besti].size()) cout << ans[besti][i] << ' ';
	return 0;
}

