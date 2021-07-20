/*
ID: yzshang1
LANG: C++11
TASK: coloring_edges 
*/
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
const int N = 5050;
vector <int> G[N];
int n, m;
int vis[N];
int ans[N][N];
bool hasCycle = false;
void dfs(int u) {
	vis[u] = 1;
	for (auto v:G[u]) {
		if (vis[v] == 1) {
			ans[u][v] = 2;
			hasCycle = true;
		}
		else if (vis[v] == 0){
			ans[u][v] = 1;
			dfs(v);
		}
		else if (vis[v] == 2) ans[u][v] = 1;
	}
	vis[u] = 2;
}
vector < pair <int, int> > Edges;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].pb(v);
		Edges.pb(mp(u, v));
	}
	rep(i, n)if (!vis[i])dfs(i); 
	if (!hasCycle)cout << 1 << endl;else cout << 2 << endl;
	for (auto i:Edges)cout << ans[i.first][i.second] << ' ';
	cout << endl; 
	return 0;
}

