#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int p, q, pp;
int main()
{
	cin >> n;
	cin >> p;
	for (int i = 2; i <= n; i++)
	{
		cin >> q;
		if ((p == 1 && q == 2) || (p == 2 && q == 1))ans += 3;
		if ((p == 2 && q == 3) || (p == 3 && q == 2))
		{
			cout << "Infinite" << endl;
			return 0;
		}
		if ((p == 1 && q == 3) || (p == 3 && q == 1))ans += 4;
		if ((pp == 3 && p == 1 && q == 2))ans--;
		pp = p;
		p = q;
	}
	cout << "Finite" << endl << ans << endl; 
	return 0;
}

