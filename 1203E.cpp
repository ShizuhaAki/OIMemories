#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define pb push_back
#define mp make_pair
#ifdef GRAPH
typedef pair <int, int> Edge;
#define v first
#define w second
#endif
using LL = long long;
using ULL = unsigned long long;
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int MAXN = 150010;
int a[MAXN], n, sz[MAXN], cnt, vis[MAXN];
set <int> val; 
vector <int> b;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)cout << a[i] << ' ';
	cout << endl;
	b.clear();
	for (int i = 1; i <= n; i++) {
		if (!val.count(a[i])) {
			cerr << a[i] << endl; 
			val.insert(a[i]);
			b.pb(a[i]);
		}
		sz[a[i]]++;
	}
	for (int i:b)cout << i << ' ';
	int ans = 0;
	cout << endl;
	for (int i : b) {
		if (sz[i] == 1) {
			if (!vis[i]) {
				vis[i] = 1;
				ans++;
			}
			else if (i - 1 > 0 && !vis[i - 1]) {
				vis[i - 1] = 1;
				ans++;
			}
			else if (!vis[i + 1]) {
				vis[i + 1] = 1;
				ans++;
			}
		}
		else if (sz[i] == 2) {
			int cho = 0;
			if (!vis[i]) {
				cho++;
				ans++;
				vis[i] = 1;
			}
			if (i - 1 > 0 && !vis[i - 1]) {
				cho++;
				ans++;
				vis[i - 1] = 1;
			}
			if (cho <= 1 && !vis[i + 1]) {
				cho++;
				ans++;
				vis[i + 1] = 1;
			} 
		}
		else {
			if (i - 1 > 0 && !vis[i - 1]) {
				ans++;
				vis[i - 1] = 1;
			}
			if (!vis[i]) {
				ans++;
				vis[i] = 1;
			}
			if (!vis[i + 1]) {
				ans++;
				vis[i + 1] = 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

