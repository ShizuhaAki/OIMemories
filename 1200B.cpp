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
#define int long long
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
const int MAXN = 110;
int a[MAXN], n, m, k;
signed main()
{
	int T;
	cin >> T;
	while (T--){
		memset(a, 0, sizeof(a));
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++)cin >> a[i];
		if (n == 1) {
			cout << "YES" << endl;
			continue;
		}
		bool solved = true;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i + 1]) {
				m += a[i] - a[i + 1];
				if (a[i + 1] - k >= 0)m += k;
				else m += a[i + 1];
			}
			else {
				if (a[i + 1] - a[i] <= k) {
					if (a[i + 1] >= k)m += min(a[i], a[i] - (a[i + 1] - k));
					else m += min(a[i], a[i + 1]);
					continue;
				}
				else if (m >= (a[i + 1] - a[i] - k)) {
					m -= (a[i + 1] - a[i] - k);
				}
				else {
					solved = false;
					break;
				}
			}
		}
		if (solved)puts("YES");
		else puts("NO");
	}
	return 0;
}

