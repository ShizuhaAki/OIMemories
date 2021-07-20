#include <bits/stdc++.h>
using namespace std;
const int MAXN=200200;
int a[MAXN],b[MAXN];
unordered_map<int,int>todo;
#define make_pair mp
vector<int>sol;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1,[](const int aa,const int bb){return aa>bb;});
	for (int i=1;i<=m*k;i++)todo[b[i]]++;
	long long cnt=0,ans=0,seg=0;
	for (int i=1;i<=n;i++)
	{
		if (todo[a[i]])todo[a[i]]--,cnt++,ans+=a[i];
		if (cnt==m)
		{
			if (seg>=k-1)continue;
			else
			{
				sol.push_back(i);
				cnt=0;
				seg++;
			}
		}
	}
	cout<<ans<<endl;
	for (auto i:sol)cout<<i<<" ";cout<<endl; 
	return 0;
}

