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
vector <string> s;
int main() {
	int T; cin >> T;
	while (T--) {
		s.clear();
		int n;
		cin >> n;
		rep(i, n) {
			string x;
			cin >> x;
			s.pb(x);
		}
		int bad = 0, odd = 0;
		rep(i, n) {
			if (s[i].length() % 2 == 1) {
				odd = 1;
				continue;
			}
			int one = count(s[i].begin(), s[i].end(), '1'), zero = count(s[i].begin(), s[i].end(), '0');
			if (one % 2 || zero % 2) bad++;
		}
		if (!odd && bad % 2) n--;
		cout << n  << endl;
	}
	return 0;
}

