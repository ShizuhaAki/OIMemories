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
int n, k;
const int N = 2019;
char s[N];
vector < pair <int, int> > ans;
int main() {
	int T; cin >> T;
	while (T--) {
		memset(s, 0, sizeof(s)); cin >> n >> k; ans.clear();
		scanf("%s", s + 1);
		repn(i, n) {
			if (s[i] == ')') {
				for (int j = i + 1; j <= n; j++) {
					if (s[j] == '(') {
						reverse(s + i, s + j + 1);//printf("%s\n", s + 1);
						ans.pb(mp(i, j));
						break;
					}
				}
			}
		}
		k--;int cnt = 1;
		for (int i = 1; i <= n; i++) {
			if (!k) break;
			if (s[i] == '(') {
				if (cnt) {
					cnt--;
					continue;
				}
				for (int j = i + 1; j <= n; j++) {
					if (s[j] == ')') {
						reverse(s + i, s + j + 1);
					    ans.pb(mp(i, j)), k--;
					    cnt = 1;
					    break;
					}
				}
			}
		}
		
		cout << ans.size() << endl;
		for(auto i:ans) cout << i.first << ' ' << i.second << endl;
//		printf("%s\n", s + 1); 
	}
	return 0;
}

