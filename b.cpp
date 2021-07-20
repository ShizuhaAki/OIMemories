/*By Ravenclaw_OIer*/
#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define ll long long
#define ull unsigned long long
#define lsh(X) (1 << (X))
#define lshll(x) (1LL << (x))
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
int a[100010], b[100010], vis[100010];
int main()
{
	int T; cin >> T;
	while (T--) {
	//	memset(a, 0, sizeof(a));memset(b, 0, sizeof(b)); memset(vis, 0, sizeof(vis));
		int n; cin >> n;
		set <int> s;
		for (int i = 1; i <= n; i++) a[i] = b[i] = vis[i] = 0;
		for (int i = 1; i <= n; i++) cin >> a[i];
		b[1] = a[1];vis[a[1]] = true;
		for (int i = 2; i <= n; i++) s.insert(-a[i]);
//		cerr << a[1] << ' ';
		bool bad = false;
		int mx = a[1];
		for (int i = 2; i <= n; i++) {
			 if (a[i] > mx) {
				 if (!vis[a[i]]) {
					 vis[a[i]] = true;
					 b[i] = a[i];
					 mx = a[i];
//					 cerr << b[i] << ' ';
//					 cerr << "set " << b[i] << endl;
				}
				 else {
					 bad = true;
					 cout << -1 << endl;
					 break;
				 }
			}
			 else if (a[i] < b[i - 1]) {
				 cout << -1 << endl;
				 bad = true;
				 break;
			 }
			 else {
				 bool x = false;
				 auto jj = (s.lower_bound(a[i]));
			     if (jj != s.end())
				 {int j = *jj;
				vis[j] = true; b[i] = j;x = true;}
				 if (!x) {
					 bad = true;
					 cout << -1 << endl;
					 break;
				}
			}
		}
		if (bad) continue;
//		cerr << endl;
		for (int i = 1; i <= n; i++) cout << b[i] << ' '; cout << endl;
	}


	return 0;
} 
