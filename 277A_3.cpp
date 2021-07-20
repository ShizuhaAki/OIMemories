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
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
int n, m, vis[300];
vector <int> G[300];
void bfs(int st) {
	queue <int> q;
	q.push(st);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v:G[u]) {
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int flag = true;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		if (k)flag = false;
		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			G[i].pb(x + n);
			G[x + n].pb(i);
		}
	}
	if (flag) {
		cout << n << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			bfs(i);
			ans++;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}

