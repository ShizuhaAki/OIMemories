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
long long qread() {
	char c;
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
char s[1200], ans[1200];
int mark[1200];
int cnt, sz[1200], chr[1200];
vector <int> pos;
int main() {
	scanf("%s", s + 1); int n = strlen(s + 1);
	for (int i = 2; i <= n; i++){
		if (i == 1) continue;
		if (!mark[i]) {
			mark[i] = true;
			if (n / i <= 1) continue;			
 			pos.pb(i);
			for (int j = i; j <= n; j += i) {
				if (!mark[j]) {
					mark[j] = true;
					pos.pb(j);
				}
			}
		}
	}
	sort(s + 1, s + n + 1);
	repn(i, n) {
		if (s[i] != s[i - 1]) cnt++;
		chr[cnt] = s[i];
		sz[cnt]++;
	}
	int maxv, maxi = 0;
	maxv = -INF;
	repn(i, cnt) {
		if (sz[i] > maxv) {
			maxv = sz[i];
			maxi = i;
		}
	}
	if (maxv < (int)pos.size()) {
		cout << "NO" << endl;
		return 0;
	}
	else {
		puts("YES");
		for (auto i:pos) ans[i] = chr[maxi], sz[maxi]--;
		for (int i = 1; i <= n; i++) {
			if (ans[i]) continue;
			for (int j = 1; j <= cnt; j++) {
				if (sz[j]) {
					ans[i] = chr[j];
					sz[j]--;
					break;
				} 
			}
		}
		printf("%s\n", ans + 1);
	}
	return 0;
}

