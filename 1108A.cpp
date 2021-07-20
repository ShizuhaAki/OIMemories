#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		int l=l1,r=r2;
		if (l == r)l++;
		cout<<l<<" " <<r<<endl;
	}
}
