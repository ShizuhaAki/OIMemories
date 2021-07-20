#include <bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int a[MAXN],m,n,k;
bool vis[MAXN];
bool check(int mid)
{
	int curr=1,dist=1,tot=1,cnt=0;
	for (int i=0;i<n-1;i++)
	{
		if (dist+a[i+1]-a[i]>mid-tot)
		{
			//use a new segment
			if (curr==1)tot++;
			dist=1;
			cnt++;
			curr=1;
			vis[i]=true;
		}
		else
		{
			dist+=(a[i+1]-a[i]);
			tot+=(a[i+1]-a[i]);
			vis[i+1]=true;
			curr++;
		}
	//	if (tot>mid)return false;
	}
	if (!vis[n-1])cnt++,tot++;
//	cerr<<mid<<" "<<cnt<<" "<<tot<<endl;
	return cnt<=k&&tot<=mid;
}
int main()
{
	cin>>n>>m>>k;
	for (int i=0;i<n;i++)cin>>a[i];
	int l=1,r=m;
	if (k>=n)
	{
		cout<<n<<endl;
		return 0;
	}
	if (k==1)
	{
		cout<<a[n-1]-a[0]+1<<endl;
		return 0;
	}
	while (l<=r)
	{
//\		cerr<<l<<" "<<r<<endl;
		memset(vis,0,sizeof(vis));
		int mid=(l+r)>>1;
//		cerr<<mid<<endl;                          
		if (check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}

