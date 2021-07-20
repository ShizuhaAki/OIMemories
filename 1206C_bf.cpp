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
const int N = 300030;
vector <int> ans;
unordered_set <int> exist;
int n;
bool check() {
	exist.clear();
	for (int i = 0; i < n; i++) {
		int sm = 0;
		int k = 0, j = i;
		for (; k < n / 2; k++) {
			sm += ans[j];
			j = (1 + j) % n;
		}
		for (auto jl:exist) {
			if (abs(sm - jl) > 1)return false;
		}
		if (!exist.count(sm))exist.insert(sm);
	}
	return true;
}
bool vis[N];
void dfs(int dep, int sum) {
	if (dep + n / 2 == n) {
		if (check()) {
			cout << "YES" << endl;
			for (auto i:ans) {
				cout << i << ' ';
			}
			cout << endl;
			exit(0);
		}
		return 0;
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	
	dfs(0);
	cout << "NO" << endl;
	return 0;
}

