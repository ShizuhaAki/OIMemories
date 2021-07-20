#include <bits/stdc++.h>
using namespace std;

int main()
{
	for (int i=2;i<=10;i++)
	{
		int ans=10000000,opt;
		for (int j=1;j<i;j++)
		{
			int curr=__gcd(i^j,i&j);
			if (curr<ans)opt=j,ans=curr;
		}
		cout<<ans<<" "<<opt<<endl;
	}
	return 0;
}

