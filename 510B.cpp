/*
ID: yzshang1
LANG: C++11
TASK: 
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
string grid[60];
int n, m;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0 , -1};
inline bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
int vis[60][60];
void dfs(int x, int y, int prevx, int prevy, char col) {
	if (!valid(x, y))return;
	if (grid[x][y] != col)return;
	if (vis[x][y]) {
		cout << "Yes" << endl;
		exit(0);
	}
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx != prevx || ny != prevy)dfs(nx, ny, x, y, grid[x][y]); 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n)cin >> grid[i];
	rep(i, n)rep(j, m)if (!vis[i][j])dfs(i, j, -1, -1, grid[i][j]);
	cout << "No" << endl;
	return 0;
}

