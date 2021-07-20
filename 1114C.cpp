#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector < pair<ll,ll> > factors;

void  factor(ll n)
{
	for (ll i=2;i*i<=n;i++)
	{
		ll cnt=0;
		while (n%i==0)
		{
			n/=i;
			cnt++;
		} 
		if (cnt)factors.push_back(make_pair(i,cnt));
	}
	if (n>1)factors.push_back(make_pair(n,1));
}
int main()
{
	ll n,k;
	cin>>n>>k;
	if (n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	factors.clear();
	factor(k);
	ll cnt=1LL<<60;//inf
	for (auto i:factors)
	{
		long long t=0,now=n;
        while(now)t+=now/=i.first;
        t/=i.second;
        cnt=min(cnt,t);
	}
	if (cnt==1LL<<60)cnt=0;
	cout<<cnt<<endl;
	return 0;
}

