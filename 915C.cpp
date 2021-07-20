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
string a, b;
bool lead = true, flag = false;
int cnt[12], cnt1[12];
int main() {
	cin >> a >> b;
	string ans;
	rep(i, (int)a.length()) cnt[a[i] - '0']++;
	rep(i, (int)a.length()) {
		for (int j = (!flag) ? b[i] - '0' : 9; j >= (lead) ? 1 : 0; j--) {
			if (cnt[j]) {
				bool bad = false;
				if (j + '0' < b[i]) goto QWQ;
				for (int k = 0; k <= 9; k++) cnt1[k] = cnt[k];
				for (int k = i + 1; k < (int)a.length(); k++) {
					for (int l = 0; l <= 9; l++) {
						if (cnt1[l]) {
							cerr << l << endl;
							if (l + '0' < b[k]) {
								flag = true;
								goto QWQ;
							}
							if (l + '0' > b[k]) {
								cerr << k << endl;
								bad = true;
								goto QWQ;
							}
							else {
								cnt1[l]--;
								break;
							} 
						}
					}
				}
				QWQ:
					if (bad) continue;
					else {
						ans.pb(j + '0');
						if (j != '0') lead = false;
						cnt[j]--;
						break;
					}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

