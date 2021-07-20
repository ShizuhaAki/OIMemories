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
const int N = 1000010;
int a[N], n;
int pre[N], vis[N * 2];
vector <int> prime;
void make_prime(int n) {
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i <= n; i++) {
		vis[i] = true;
		prime.pb(i);
		for (int j = i; j <= n / i; j++)vis[i * j] = true;
	}
}
int main() {
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	make_prime(N); 
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		int now = a[i];
		if (now == 1)continue;
		for (auto j:prime) {
			if (j * j > now)break;
			if (now % j == 0) {
				ans += (n - i + 1) * (i - pre[j]);
				pre[j] = i; 
				while (now % j == 0)now /= j;
			}
		}
		if (now > 1) {
			ans += (n - i + 1) * (i - pre[now]);
			pre[now] = i; 
		}
	}
	cout << ans << endl;
	return 0;
}
