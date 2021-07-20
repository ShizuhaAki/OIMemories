#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		long long k,x;
		cin >> k >> x;
	    cout << (k - 1) * 9  + x << endl;
	}
}
