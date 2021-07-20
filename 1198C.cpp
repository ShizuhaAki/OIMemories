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
using LL = long long;
using ULL = unsigned long long;
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
const int MAXN = 300030;
int n, m;
vector < pair <int, int> > edges;
vector < int > matching;
#define from first
#define to second
bool cover[MAXN];
int main() {
	ios::sync_with_stdio(false);
	int T;cin >> T;
	while (T--) {
		matching.clear();
		edges.clear();
		for (int i = 1; i <= 3 * n; i++)cover[i] = false;
		cin >> n >> m;
		int u, v;
		for (int i = 1; i <= m; i++) {
			cin >> u >> v;
			edges.pb(mp(u, v));
		}
		int indset = 3 * n;
		for (int i = 0; i < edges.size(); i++) {
			if ((!cover[edges[i].from]) && (!cover[edges[i].to])) {
				matching.pb(i);
				if (matching.size() == n)break;
				cover[edges[i].from] = cover[edges[i].to] = true;
				indset -= 2;
			}
		}
		if (matching.size() == n) {
			cout << "Matching" << endl;
			for (auto i:matching)cout << i + 1 << ' ';
			cout << endl;
		}
		else if (indset >= n) {
			cout << "IndSet" << endl;
			for (int i = 1, j = 1; i <= 3 * n && j <= n; i++) {
				if (!cover[i]) {
					cout << i << ' ';
					j++;
				}
			}
			cout << endl;
		}
		else cout << "Impossible" << endl;
	}
	return 0;
}

