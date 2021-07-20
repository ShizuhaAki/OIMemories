#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!(x))
#define fail(s) assert(!(s))
#define ULL unsigned long long
#define FILEIO 1
#ifdef FILEIO
#define FILEOPEN(in, out) freopen(in, "r", stdin);freopen(out, "w", stdout);
#endif
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
int main()
{
#ifdef ONLINE_JUDGE
	FILEOPEN("input.txt", "output.txt");
#endif
	int n;
	cin >> n;
	vector <int> dp(n + 1);
	vector <int> a(n + 1);
	vector <int> path(n + 1);
	list <int> dq;
	rep(i, n) {
		int x;
		cin >> x;
		a[i] = x;
		dp[i] = 1;
		path[i] = -1;
		for (auto it = dq.begin(); it != dq.end(); ){
			int v = *it;
			int y = a[v];
			if (x == y)dq.erase(it++);
			else ++it;
			if (y != x + 1 && y != x - 1) {
				if (dp[v] + 1 > dp[i]) {
					dp[i] = dp[v] + 1;
					path[i] = v;
				}
			}
		}
		dq.push_back(i);
		if (dq.size() > 5) dq.pop_front();
	}
	int besti = -1, bestv = -1;
	rep(i, n) {
		if (dp[i] > bestv) {
			bestv = dp[i];
			besti = i;
		}
	} 
	cout << n - bestv << endl;
	stack <int> s;
	until(besti == -1) {
		s.push(besti);
		besti = path[besti];
	}
	until(s.empty()) {
		int u = s.top();s.pop();
		cout << a[u] << ' ';
	}
	cout << endl;
	return 0;
}

