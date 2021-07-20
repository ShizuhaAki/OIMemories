
// Problem : D. Constant Palindrome Sum
// Contest : Codeforces - Codeforces Round #636 (Div. 3)
// URL : https://codeforces.com/contest/1343/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
typedef pair <int, int> PII;
//#define int long long
#define all(x) (x.begin(),  x.end())
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
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
int n, k;
const int N = 400020;
int main() {
	int tc = qread();
	while (tc--) {
		n = qread(); k = qread();
		vector <int> a(n);
		rep(i, n) a[i] = qread();
		vector <int> cnt(2 * k + 1);
		vector <int> pref(2 * k + 2);
		rep(i, n / 2) {
			cnt[a[i] + a[n - i - 1]]++;
		}
		rep(i, n / 2) {
			int l1 = a[i] + 1, r1 = a[i] + k, l2 = a[n - i - 1] + 1, r2 = a[n - i - 1] + k;
			pref[min(l1, l2)]++;
			pref[max(r1, r2) + 1]--;
		}
		repn(i, k * 2 + 1) pref[i] += pref[i - 1];
		int ans = 1e9;
		range(i, 2, k * 2) {ans = min(ans, pref[i] - cnt[i] + (n / 2 - pref[i]) * 2);}
		cout << ans << endl;
		
	}
	return 0;
}
