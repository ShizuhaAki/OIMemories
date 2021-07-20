#include <bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int a[MAXN];
int n,m,k;
double ans;
int main()
{
	cin>>n>>k>>m;
	for (int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if (m>=n-1)//can delete everyone except the most powerful
	{
		m=m-(n-1);
		ans=a[n-1]+min(m,k);
	}
	else
	{
		long long sum=0;
		int cnt=0;
		for (int i=m;i<n;i++)
		{
			sum+=a[i];
			cnt++;
		}
		ans=sum/(double)cnt;
	}
	cout<<fixed<<setprecision(12)<<ans<<endl;
	return 0;
}

