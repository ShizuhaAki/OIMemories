#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200020;
int a[MAXN];
long long prefix[MAXN];
vector <int> Div;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		Div.clear();
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)cin >> a[i];
		for (int i = 1; i <= n; i++)prefix[i] = prefix[i - 1] + a[i];
		if (n == 1)
		{
			if (a[1] % 2 == 1)cout << "YES" << endl << 1 << endl;
			else cout << "NO" << endl;
			continue; 
		}
		if (m == 1)
		{
			if (prefix[n] % 2 == 1)cout << "YES" << endl << n << endl;
			else cout << "NO" << endl;
			continue;
		}
		int i = 1;
		while (i <= n)
		{
			if ((prefix[i] % 2 == 1))
			{
				Div.push_back(i);
				break;
			}
			i++;
		}
		while (i <= n)
		{
			if ((prefix[i] - prefix[Div.back()]) % 2 == 1)Div.push_back(i);
			i++;
		}
		if (Div.size() < m)
		{
			cout << "NO" << endl;
			continue;
		}
		else
		{
			if ((prefix[n] - prefix[Div[m - 2]]) % 2 == 0)
			{
				cout << "NO" << endl;
				continue;
			}
			cout << "YES" << endl;
			for (int i = 0; i < m - 1; i++)
				cout << Div[i] << ' ';
			cout << n << endl;
		}
	}
	return 0;
}

