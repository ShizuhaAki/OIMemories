#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,x,y,z;
	cin>>x>>y>>z>>a>>b>>c;
	if (a<x)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	 	a-=x;
	if (a+b<z)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		if (a>z)a-=z;
		else
		{
			z-=a;
			a=0;
			b-=z;
		}
	}
	 
	if (a+b+c>=y)cout<<"YES"<<endl;
	else cout<<"NO"<<endl; 
	return 0;
}

