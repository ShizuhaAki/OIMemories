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
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] - 1 > 0 && !vis[a[i] - 1]) {
			vis[a[i] - 1] = true;
			ans++;
			continue;
		}
		if (!vis[a[i]]) {
			vis[a[i]] = true;
			ans++;
			continue;
		}
		if (!vis[a[i] + 1]) {
			vis[a[i] + 1] = true;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

