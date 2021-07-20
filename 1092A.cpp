#include <iostream>
using namespace std;
int main()
{
	int q;
	cin>>q;
	while (q--)
	{
		int n,k,now=0;
		cin>>n>>k;
		for (int i = 1; i <= n; ++i)
    		putchar('a' + now), (++now) %= k;
    	cout << endl;
	}
	
}

