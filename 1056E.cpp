#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
string a, b; int n, m;
const int BASE = 107, P = 19260817;
struct Hash {
	vector <ULL> hashval, pow;
	Hash(string t) {
		hashval.resize(t.size() + 1); pow.resize(t.size());
		pow[0] = 1;
		for (int i = 0; i < t.size(); i++) {
			hashval[i + 1] = (hashval[i] * BASE + t[i]);
			pow[i + 1] = pow[i] * BASE;
		}
	}
	ULL getHashCode(int l, int r) {
		return (hashval[r] - hashval[l] * pow[r - l]);
	}
};
int main() {
	cin >> a >> b;
	int ans = 0;
	n = a.length(), m = b.length();
	int zero = count(a.begin(), a.end(), '0');
	int one = count(a.begin(), a.end(), '1');
	int tmp = 0, i;
	Hash hsh(b);
//	bool f = 0;
	for (i = 1; i <= m; i++) {
		tmp = m - i * zero;
		if (tmp % one == 0)  {
			int r0 = i, r1 = tmp / one;			
			if (r1 < 0) break;
			bool ok = false;
			vector <ULL> hl;
			int ptr = 0;
			rep(i, n) {
				int inc = 0;
				if (a[i] == '0') inc = r0;
				else inc = r1;
				hl.pb(hsh.getHashCode(ptr, ptr + inc));
				ptr += inc;
			} 
			if (hl == hsh.hashval) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

