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
const int N = 1020;
char s[N];
int sz[N], vis[N];
char ans[N];
char chr[N];
int n, cnt = 0;
vector <int> pos;
int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	sort(s + 1, s + n + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] != s[i - 1]) cnt++;
		chr[cnt] = s[i];
		sz[cnt]++;
	}
	for (int i = 2; i <= n; i++) 
		if (!vis[i]) {
			vis[i] = true;
			if (n / i <= 1) continue;
			pos.pb(i);
			for (int j = i; j <= n; j += i)
				if (!vis[j]) {
					vis[j] = true;
					pos.pb(j);
				}
		}
	int maxi = -1, maxv = 0;
	repn(i, cnt)
		if (sz[i] > maxv) {
			maxv = sz[i];
			maxi = i;
		}
	if (maxv < (int)pos.size()) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for (auto i:pos) ans[i] = chr[maxi], sz[maxi]--;
	repn(i, n) {
		if (!ans[i]) {
			repn(j, cnt) {
				if (sz[j]) {
					sz[j]--;
					ans[i] = chr[j];
					break; 
				}
			}
		}
	}
	repn(i, n) putchar(ans[i]);
	return 0;
}

