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
using LL = long long;
using ULL = unsigned long long;
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 1010;
char buf[N], ans[N];
bool marked[N];
vector <int> pos; 
int sz[N];
bool vis[N];
int tot = 1, cnt;
typedef pair <int, int> PII;
char tbl[N];
int main() {
	scanf("%s", buf + 1);
//	printf("%s", buf + 1);
	int len = strlen(buf + 1);
//	cerr << len << endl;
	for (int i = 2; i <= len; i++) {
		if (!marked[i]) {
			marked[i] = true;
			if (len / i <= 1)continue;
			pos.pb(i); 
			for (int j = i; j <= len; j += i) {
//				cerr << "qwq" << endl;
				if (marked[j])continue;
				pos.pb(j);
				marked[j] = true;
			}
		}
	}
	sort(buf + 1, buf + len + 1);
	for (int i = 1; i <= len; i++) {
		if (buf[i] != buf[i - 1])cnt++;
		tbl[cnt] = buf[i];
		sz[cnt]++;
	}
	int besti = 0, bestv = -INF;
	for (int i = 1; i <= cnt; i++) {
		if (sz[i] > bestv) {
			bestv = sz[i];
			besti = i;
		}
	}	
	if (bestv < (int)pos.size()) {
		puts("NO");
	}
	else {
		puts("YES");
		for (int i:pos)ans[i] = tbl[besti], sz[besti]--;
		for (int i = 1; i <= cnt; i++)	
			for (int j = 1; j <= len; j++) {
				if (!sz[i])continue;
				if (ans[j])continue;
				sz[i]--;
				ans[j] = tbl[i];
			}
		printf("%s\n", ans + 1);
	}
	return 0;
}

