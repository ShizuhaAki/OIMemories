#include <bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=100010;
int cost[MAXN];
struct Dish
{
	int price,remain,no;
}dishes[MAXN];
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>dishes[i].remain,dishes[i].no=i;
	for (int i=1;i<=n;i++)
		cin>>dishes[i].price;
	sort(dishes+1,dishes+n+1,
	[](const Dish a, const Dish b)	
	{
		if (a.price!=b.price)
			return a.price<b.price;
		else
			return a.no<b.no;
	});
	for  (int i=1;i<=m;i++)
	{
		bool flag=false;
		int cost=0;
		int k,num;
		cin>>k>>num;
		if (dishes[k].remain)
		{
			num-=dishes[k].remain;
			cost+=dishes[k].remain*dishes[k].price;
			dishes[k].remain=0;
		} 
		for (int j=1;j<=n;j++)
		{
			if (num==0)break;
			if (dishes[j].remain>=num)
			{
				cost+=num*dishes[j].price;
				dishes[j].remain-=num;
				num=0;
			}
			else if (dishes[j].remain&&dishes[j].remain<num)
			{
				cost+=dishes[j].remain*dishes[j].price;
				num-=dishes[j].remain;
				dishes[j].remain=0;
			}
		}
		if (num)cost=0; 
		cout<<cost<<endl;
	}
	return 0;
}

