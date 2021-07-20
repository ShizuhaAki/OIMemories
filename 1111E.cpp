#include <bits/stdc++.h>
using namespace std;
int used,cnt;
bool vis[1000010];
bool query(int x)
{
	used++;
	cout<<">"<<" "<<x<<endl;
	fflush(stdout);
	int res;
	cin>>res;
	return res; 
}
int get(int x)
{
	used++;
	cout<<"? "<<x<<endl;
	fflush(stdout);
	int res;
	cin>>res;
	return res;
} 
int gcd(int a,int b)
{
	if (a%b==0)return b;
	else return gcd(b,a%b);
}
int random(int n)
{
	int res;
	do{
		res=rand()*rand()%n+1;
	}while (vis[res]);
	vis[res]=1;cnt++;
	return res;
}
int main()
{
	int n;
	srand(time(0));
	cin>>n;
	int l=0,r=1000000000;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (query(mid))l=mid+1;
		else r=mid-1;
	}
	int mm=l;
	int d,x,y;
	x=get(random(n));
	y=x;
	x=get(random(n));
	d=abs(y-x);
	while (used<60)
	{
		if(cnt>=n)break; 
		y=x;
		x=get(random(n));
		d=gcd(d,abs(y-x));
	}
	int minn=mm-(n-1)*d;
	cout<<"! "<<minn<<" "<<d<<endl;
	return 0;
}

