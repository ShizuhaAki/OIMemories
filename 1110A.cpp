#include <bits/stdc++.h>
using namespace std;

int main()
{
	int b,k;
	cin>>b>>k;
	int ans=0;
	for (int i=k-1;i>0;i--)
	{
		int x;
		cin>>x;
		ans=(ans+(x%2)*(b%2))%2;
	}
	int x;
	cin>>x; 
	ans=(ans+(x%2))%2;
	if (ans)cout<<"odd"<<endl;
	else cout<<"even"<<endl;
	return 0;
}

