#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=100010;
const int INF=0x3f3f3f3f;
int a[MAXN];
int n,k,x,y;
long long ans;
inline int exist(int l,int r)
{
	int s,e;
	int beg=1,end=k;
	while (beg<=end)
	{
		int mid=(beg+end)>>1;
		if (a[mid]>r)end=mid-1;
		else beg=mid+1;
	}
	e=end;
	beg=1,end=k;
	while (beg<=end)
	{
		int mid=(beg+end)>>1;
		if (a[mid]>=l)end=mid-1;
		else beg=mid+1;
	}
	s=beg;
//	cerr<<s<<" "<<e<<endl; 
	return e-s+1;
}
long long solve(int l,int r)
{
//	cerr<<"solve("<<l<<","<<r<<")"<<endl;
	int cnt=exist(l,r);
	if (cnt)
	{
//		cerr<<"cnt="<<cnt<<endl;
		if (l==r)return cnt*y;
		int mid=(l+r)>>1;
		return solve(l,mid)+solve(mid+1,r);
	}
	return x;
}
main()
{
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	cin>>n>>k>>x>>y;
	for (int i=1;i<=k;i++)cin>>a[i];
	sort(a+1,a+1+k);
	cout<<solve(1,1<<n)<<endl;
	return 0;
}

