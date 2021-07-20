#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		if (k % 3 != 0)
		{
			if (n % 3 == 0)puts("Bob");
			else puts("Alice");
		}
		else
		{
			k++;
			if ((n % k) % 3 == 0 && (n % k) != k - 1)puts("Bob");
			else puts("Alice");
		}
	}
	return 0;
}

