#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100010;
vector <int> g[MAXN]; 
int n,m;
vector <int> ans;
bool vis[MAXN];
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	priority_queue<int,vector<int>,greater<int> >q;
	q.push(1);vis[1]=true;
	while (!q.empty()) 
	{
		int u=q.top();q.pop();
		for (auto it:g[u])
			if(!vis[it])
			{ 
				vis[it]=true;
				q.push(it);
			}
		ans.push_back(u);
		if (ans.size()==n)break;
	}
	for (auto i:ans)cout<<i<<" ";
	cout<<endl;
} 
