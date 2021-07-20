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
int n;
int a[500];
int main() {
	ios::sync_with_stdio(false);
	int Q; cin >> Q;
	while (Q--) {
		unordered_set <int> s;
		cin >> n;
		n *= 4;
		for (int i = 1; i <= n; i++)cin >> a[i];
		sort(a + 1, a + n + 1);
		bool flag = true;
		for (int i = 1, j = n; i <= n;) {
			if (a[i] != a[i + 1] || a[j] != a[j - 1]) {
				flag = false;
				break;
			}
			if (!s.count(a[i] * a[j]))s.insert(a[i] * a[j]);
			if (s.size() >= 2) {
				flag = false;
				break;
			}
			i += 2;
			j -= 2;
		} 
		if (flag)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

