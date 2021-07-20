/*
ID: yzshang1
LANG: C++11
TASK: 1144F
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
const int N = 200020;
vector <int> G[N];
int n, m, col[N];
void dfs(int u, int nowcol) {
	col[u] = nowcol;
	for (auto v:G[u]) {
		if (col[v] == -1) {
			dfs(v, nowcol ^ 1);
		}
		else if (col[v] == nowcol) {
			cout << "NO" << endl;
			exit(0);
		}
	}
}
vector <pair <int, int> >Edges;
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].pb(v);
		G[v].pb(u);
		Edges.pb(mp(u, v));
	} 
	memset(col, -1, sizeof(col));
	dfs(0, 0);
	cout << "YES" << endl;
	for (auto i:Edges) {
		if (col[i.first] == 0)cout << 1;
		else cout << 0;
	} 
	return 0;
}

