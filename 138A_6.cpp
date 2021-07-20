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
int n, k;
set <char> vowel = {'a', 'e', 'i', 'o', 'u'};
set <string> mod = {"aabb", "abba", "abab"}; 
int main() {
	cin >> n >> k;
	vector < vector <int> > r;
	vector < int > d;
	rep(i, n) {
		map <string, int> m;
		int c = 0;
		string buf;
		vector <int> rhythm;
		rep(kk, 4){
			int cnt = 0;
			cin >> buf;
			string suffix;
			for (int j = buf.length() - 1; j >= 0; j--) {
//				cerr << j << endl;
				suffix.pb(buf[j]);
				if (vowel.count(buf[j])) cnt++;
				if (cnt == k)break;
			}
	//		cerr << cnt << endl;
			if (cnt < k) {
				cout << "NO" << endl;
				return 0;
			}
			else  {
		//		cerr << suffix << endl;
				if (!m.count(suffix)) {
					m[suffix] = ++c;
					rhythm.pb(c);
				}
				else rhythm.pb(m[suffix]);
				if (c > 2) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
		r.pb(rhythm);
		d.pb(c); 
	}
	string ans = "aaaa";
	rep(i, n) {
		if (d[i] == 1) continue;
		else {
			string res;
			rep(j, 4) {
				res.pb(r[i][j] + 'a' - 1);
			}
			if (res != "aaaa" && !mod.count(res)) {
				cout << "NO" << endl;
				return 0;
			}
		//	cerr << res << endl;
		//	cerr << ans << endl;
			if (ans == res) continue;
			else if (ans == "aaaa") ans = res;
			else {
				cout << "NO" << endl;
				return 0;
			} 
		}
	}
	cout << ans << endl;
	return 0;
}

