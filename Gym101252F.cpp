#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
typedef pair <int, int> PII;
int n;
const int MAXN = 100010;
vector <int> dp, a;
vector < vector <int> > ans;
__gnu_pbds::priority_queue<PII, less<PII>, __gnu_pbds::pairing_heap_tag> pq;
int main() 
{
#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin >> n;
	dp.resize(n + 1);
	a.resize(n + 1);
	ans.resize(n + 1); 
	for (int i = 1; i <= n; i++)cin >> a[i];
	a[0] = INF;
	pq.push(make_pair(dp[0], 0));
	vector <PII> vec;
	for (int i = 1; i <= n; i++){
		vec.clear();
		while (!pq.empty()) {
			auto it = pq.top(); pq.pop();
			vec.push_back(it);
			vec.shrink_to_fit();
			if (abs(a[it.second] - a[i]) == 1)continue;
			int anspos = 0;
			if (it.first + 1 >= dp[i]) {
				dp[i] = it.first + 1;
				anspos = it.second;
				ans[i] = ans[anspos];
				ans[i].push_back(a[i]);
				pq.push(make_pair(dp[i], i));
				break;
			}
		} 
		for (auto i:vec)pq.push(i); 
	}
	int bestv = -1, besti = -1; 
	for (int i = 1; i <= n; i++) {
		if (dp[i] > bestv) {
			bestv = dp[i];
			besti = i;
		}
	}
	cout << n - bestv << endl;
	for (int i:ans[besti])cout << i << ' ';
	cout << endl;
	return 0;
}

