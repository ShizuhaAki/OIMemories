#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int a[MAXN], n, Max = -0x3F3F3F3F, maxpos;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	    if (a[i] > Max)
	    {
	    	Max = a[i];
	    	maxpos = i;
		}
	} 
	for (int i = 2; i <= maxpos; i++)
		if (a[i] < a[i - 1])
		{
			cout << "NO" << endl;
			return 0;
		}
		
	for (int i = maxpos + 1; i <= n; i++) 
		if (a[i] > a[i - 1])
		{
		    cout << "NO" << endl;
		    return 0;
		}
	cout << "YES" << endl;
	
	return 0;
}

