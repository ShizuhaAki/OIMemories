#include <bits/stdc++.h>
using namespace std;
long long ans;
bool flag;
int main()
{
	int T;cin >> T;
	while (T--)
	{
		ans = 0;
		flag = false;
		long long n;
		cin >> n;
		while (n != 1)
		{
			ans++;
//			cerr << n << " ";
			if (n % 2 == 0)n /= 2;
			else if (n % 3 == 0) n = n * 2 / 3;
			else if (n % 5 == 0) n = n * 4 / 5;
			else
			{
				cout << -1 << endl;
				flag = true;
				break;
			}	
		}
//		cerr << endl;
		if (flag)continue;
		else cout << ans << endl;
	}
	return 0;
}

