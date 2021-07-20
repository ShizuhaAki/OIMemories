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

int main() {
	int T; cin >> T;
	while (T--) {
		string s;
		cin >> s;
		deque <char> num[2];
		for (auto i:s) num[(i - '0') % 2].pb(i);
		string ans;
		rep(i, s.length()) {
			if (num[0].empty()) {
				ans.pb(num[1].front());
				num[1].pop_front();
				continue;
			}
			else if (num[1].empty()) {
				ans.pb(num[0].front());
				num[0].pop_front();
				continue;
			}
			if (num[0].front() < num[1].front()) {
				ans.pb(num[0].front());
				num[0].pop_front();
			}
			else {
				ans.pb(num[1].front());
				num[1].pop_front();
			}
		}
		cout << ans << endl;
	}
	return 0;
}

