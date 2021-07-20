#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100020;
int n;
int a[MAXN];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		if (n - 2 >= a[n - 1] - 1)cout << a[n - 1] - 1 << endl;
		else if (n - 2 < a[n - 1] - 1)cout << n - 2 << endl;
		else cout << 0 << endl;
	} 
	return 0;
}

