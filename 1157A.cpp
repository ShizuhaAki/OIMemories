#include <bits/stdc++.h>
using namespace std;
int f(int x)
{
	x++;
	while (x % 10 == 0)x /= 10;
	return x;
}
//unordered_set<int> hashtable;
long long ans = 0;
int main()
{
	int x;
	cin >> x; 
//	hashtable.insert(x);
	while (x >= 10)
	{
		x = f(x);
//	    if (!hashtable.count(x))hashtable.insert(x);
//      else break;
//		cout << x << endl;
		ans++;
	}
	cout << ans + 9 << endl;
	return 0;
}

