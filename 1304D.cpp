
// Problem : D. Shortest and Longest LIS
// Contest : Codeforces Round #620 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1304/D
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
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
	char c = getchar();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
vector <int> solve(int n, string s, int x, int init, char sgn) {
	vector <int> ans;
	ans.resize(n);
	int last = 0, cur = init;
	rep(i, n) {
		if (i == n - 1 || s[i] == sgn) {
			for (int j = i; j >= last; j--) {
				ans[j] = cur;
				cur += x;
			}
			last = i + 1;
		}
	}
	return ans;
}
 int main() {
	int T = qread();
	while (T--) {
		int n = qread();
		string s;
		cin >> s;
		vector <int> ans;
		ans.resize(n);
		int last = 0, cur = n;
		rep(i, n) {
			if (i == n - 1 || s[i] == '>') {
				for (int j = i; j >= last; j--) {
					ans[j] = cur--;
				}
				last = i + 1;
			}
		}
		for (auto i:ans) cout << i << ' '; cout << endl;
		ans.resize(n);
		last = 0, cur = 1;
		rep(i, n) {
			if (i == n - 1 || s[i] == '<') {
				for (int j = i; j >= last; j--) {
					ans[j] = cur++;
				}
				last = i + 1;
			}
		}
		for (auto i:ans) cout << i <<  ' ';cout << endl;
	}
	return 0;
}
