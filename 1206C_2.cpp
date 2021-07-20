#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <list>
#include <cassert>
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
#if __cplusplus >= 201103L
using LL = long long;
using ULL = unsigned long long;
#else
#define LL long long
#define ULL unsigned long long
#endif
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
#define int long long
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
int n, ans[300030], lim, vis[300030], used[300030];
vector <int> ok;
signed main() {
	ios::sync_with_stdio(false);
	cin >> n;
	lim = n * (2 * n + 1) / 2;
	int sum = 0;
	for (int i = 1, j = 1; i <= n - 1; i++) {
		while (used[j] || j % 4 >= 2)j++;
	//	cerr << j << endl;
		used[j] = true;
		ans[i] = j;
		sum += j;
		vis[j] = true;
	}
	for (int i = n; i <= 2 * n; i++) {
		int val = lim - (sum - ans[i - n]);
	//	cerr << val << endl;
		if (!vis[val]) {
			vis[val] = true;
			ans[i] = val;
			sum -= ans[i - n];
			sum += val;
		}
		else if (!vis[val + 1]) {
			vis[val + 1] = true;
			ans[i] = val + 1;
			sum -= ans[i - n];
			sum += val + 1;
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
//	cerr << sum << endl;
	for (int i = 1; i <= n - 2; i++) {
		if (sum - ans[n + i] + ans[i] != lim && sum - ans[n + i] + ans[i] != lim + 1) {
			cout << "NO" << endl;
			return 0;
		}
		else {
			sum -= ans[n + i];
			sum += ans[i];
		}
	}
	cout << "YES" << endl;
	for (int i = 1;i <= n * 2; i++)cout << ans[i] << ' ';cout << endl;
	return 0;
}

