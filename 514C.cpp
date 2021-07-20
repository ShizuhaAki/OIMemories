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
set <int> table1, table2; 
int n, m;
const int BASE1 = 19260817, BASE2 = 107, SIZE = 1e9 + 7, MOD = 1e9 + 7;
LL qpow(LL a, LL b, LL p) {
	LL ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}
int getHashCode(string str, int base) {
	LL res = 0;
	rep(i, (int)str.length()) {
		res = res + (qpow(base, i, SIZE) * (str[i] - 'a' + 1) % SIZE) % SIZE;
	}
	return (res) % SIZE;
}
int main() {
	cin >> n >> m;
	repn(i, n) {
		string s;
		cin >> s;
		table1.insert(getHashCode(s, BASE1));
		table2.insert(getHashCode(s, BASE2));
		//cerr << getHashCode(s, BASE1)<< endl;
	}
	repn(i, m) {
		string q;
		cin >> q;
		LL hash1 = getHashCode(q, BASE1), hash2 = getHashCode(q, BASE2);
		bool ok = false;
		rep(i, (int)q.length()) {
			repn(j, 3) {
				if (q[i] - 'a' + 1 == j) continue;
				LL newhash1 = (hash1 - (q[i] - 'a' + 1) * qpow(BASE1, i, SIZE) % MOD + MOD) % MOD ;
				newhash1 = (newhash1 + j * qpow(BASE1, i, SIZE) % MOD) % MOD;
				LL newhash2 = (hash2 - (q[i] - 'a' + 1) * qpow(BASE2, i, SIZE) % MOD + MOD) % MOD ;
				newhash2 = (newhash2 + j * qpow(BASE2, i, SIZE) % MOD) % MOD;//cerr << newhash1 << endl; 
				if (table1.count(newhash1) && table2.count(newhash2)) {
					cout << "YES" << endl;
					ok = true;
					break;
				}
			} 
			if (ok) break;
		} 
		if (!ok) cout << "NO" << endl;
	}
	return 0;
}

