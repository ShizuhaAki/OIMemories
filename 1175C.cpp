#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long sum = 0;
		int n, k;
		vector <int> a;
		a.push_back(0);
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			sum += x;
			a.push_back(x);
		}
		
	}
	return 0;
}

