#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans;
int n, k;
const int MAXN = 300030;
int a[MAXN];
vector <LL> b; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cin >> a[1];
	for (int i = 2; i <= n; i++)
	{
		cin >> a[i];
		b.push_back(a[i - 1] - a[i]);
	}
	ans += (a[n] - a[1]);
	sort(b.begin(), b.end());
	for (int i = 0; i < k - 1; i++)ans += b[i];
	cout << ans << endl;
	return 0;
}

