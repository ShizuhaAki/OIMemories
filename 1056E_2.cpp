/*
ID: yzshang1
LANG: C++11
TASK: CF1056E
*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const int N = 1000010, BASE = 131, MOD = 19260817;
LL p[N];
struct hasher {
	LL hashval[N];
	void init(string s, int m) {
		hashval[0] = s[0] - '0';
		for (int i = 1; i < m; i++) {
			hashval[i] = (hashval[i - 1] * BASE % MOD + s[i] - '0') % MOD;
		}
	} 
	int getIntervalHash(int l, int r) {
		r--;
		return (hashval[r] - hashval[l - 1] * p[r - l + 1] + 100000000LL * MOD) % MOD; 
	}
};
string a, b; hasher h;
int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b;
	int zero = count(a.begin(), a.end(), '0');
	int one =  a.length() - zero;
	int j = 0, i, ans = 0;
	p[0] = 1;
	for (int i = 1; i <= b.length(); i++) p[i] = p[i - 1] * BASE % MOD;
	h.init(b, b.length());
	int n = a.length(), m = b.length();
	for (i = 1; i <= m; i++) {
		j = m - i * zero;
		if (j % one == 0) {
			int r0 = i, r1 = j / one;
			if (r1 < 0) goto OUTPUT;
			bool bad = false;
			int ptr = 0;
			int HR0 = 0, HR1 = 0;
			string x, y;
			rep(p, n) {
				int inc = 0;
				if (a[p] == '0') inc = r0;
				else inc = r1;
	//			cerr << ptr << ' ' << ptr + inc << endl;
	//			cerr << b.substr(ptr, inc) << endl; 
				LL hsh = h.getIntervalHash(ptr, ptr + inc);
				if (a[p] == '0') {
					if (HR0 == 0) HR0 = hsh;
					else if (HR0 != hsh) {
						bad = true;
						break;
					}
				}
				if (a[p] == '1') {
					if (HR1 == 0) HR1 = hsh;
					else if (HR1 != hsh) {
						bad = true;
						break;
					}
				}
				ptr += inc; 
			}
	//		cerr << HR0 << ' ' << HR1 << ' ' << x << ' ' << y << endl;
			if (bad || HR0 == HR1 || HR1 == 0 || HR0 == 0) continue;
			else ans++;
		}
	}
	OUTPUT:
	cout << ans << endl;
	return 0;
}

