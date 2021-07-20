
// Problem : D. Fill The Bag
// Contest : Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define int long long
#define y1 y114514
#define y2 y1919810
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
#define range(i, s, t)  for (int (i) = s; (i) <= (int)t; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c = cin.get();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = cin.get();
	if (c == '-') c = cin.get(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = cin.get();
	return neg * val;
}
int  cnt[110], n, m, checks;
void my_assert(bool x, string extra_information) {
//	checks++;
//	if (x)cerr << "PASSED CHECK " << checks << ':'<< extra_information << endl;
	//else {
		//cerr << "FAILED ON CHECK " <<checks << ':'<< extra_information << endl;
		//exit(114514);
	//}
}
map <int, int> l2;
signed main() { 
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = qread();
	for (int i = 0, j = 1; j < 1e9; i++, j *= 2) {
		l2[j] = i;
	}
	while (T--) {
		cin >> n >> m;
		memset(cnt, 0, sizeof(cnt));
		rep(i, m) {
			int x = qread();
			cnt[l2[x]]++;
		}
		int ans = 0;
		bool done = false;
		rep(i, 61) {
			done = false;
			//cerr << "PROCESSING BIT " << i << " STATE = " << bitRequired.test(i) << endl;
			if (lshll(i) & n) {
				int bestj = -1;
				range(j, i, 60) {
					if (cnt[j] >= 1) {
						bestj = j;
						break;
					}
				}
				if (bestj == -1) {
					ans = -1;
					goto JUMP;
				}
				for (int j = bestj; j > i; j--) {
					ans++;
					cnt[j]--;
					cnt[j - 1] += 2;
				}
				cnt[i]--;
			}
			cnt[i + 1] += cnt[i] / 2;
		}
		JUMP:
		cout << ans << endl;
	}
//	cerr << "PASSED ALL CHECKS: TOTAL " << checks << endl;
	return 0;
}
