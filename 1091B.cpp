#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int MAXN = 1010;
typedef pair<int,int> pii;
pii clue[MAXN], obelisk[MAXN];
int n,sumx[MAXN][MAXN],sumy[MAXN][MAXN];
bool vis[MAXN];
int ansx,ansy;
void dfs(int curr,int now)
{
	//cerr<<"curr="<<curr<<", now="<<now<<endl;
	if (curr==n+1&&sumx[n][now]==ansx&&sumy[n][now]==ansy)cout<<ansx<<" "<<ansy<<endl,exit(0);
	for (int i=1;i<=n;i++)
		if (!vis[i]&&sumx[curr][i]==ansx&&sumy[curr][i]==ansy)
		{
			vis[i]=true;
			dfs(curr+1,i);
			vis[i]=false;
		}
}
#define read_pii(p) cin>>p.first>>p.second
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)read_pii(obelisk[i]);
	for (int i=1;i<=n;i++)read_pii(clue[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			sumx[i][j]=obelisk[i].first+clue[j].first;
			sumy[i][j]=obelisk[i].second+clue[j].second;
		}
	for (int i=1;i<=n;i++)
	{
		ansx=sumx[1][i],ansy=sumy[1][i];
		vis[i]=true;
		//cout<<"dfs no "<<i<<endl;
		dfs(2,i);
		for (int i=1;i<=n;i++)vis[i]=false;
	}
}
