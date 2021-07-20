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
	int T;
	cin >> T;
	while (T--) {
		string s, t;
		cin >> s >> t;
		int n = t.length();
		sort(s.begin(), s.end());
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++) {
				string r;
				for (int k = i; k <= j; k++) r.pb(t[k]);
				//cerr << r << endl;
				sort(r.begin(), r.end());
				if (r == s) goto YES;
			}
		goto NO;
		YES: 
			cout << "YES" << endl;
			continue;
		NO:
			cout << "NO" << endl;
	} 

	return 0;
}

