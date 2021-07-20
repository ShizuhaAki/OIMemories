#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 10000;
vector<int>factors;
void prework(unsigned long long n)
{
	for (unsigned long long i=1;i*i<=n;i++)
		if (n%i==0)
		{
			factors.push_back(i);
			if (i!=n/i)factors.push_back(n/i);
		}
}
int main()
{
	unsigned long long ans=1;
	int curr=0;
	ios::sync_with_stdio(false);
	vector <unsigned long long> answers ;
	unsigned long long n;cin>>n;prework(n);
	for (const auto k:factors)
	{
		ans=n*(k-1)/2+k;
		answers.push_back(ans);
		//ans=n*(n/k-1)/2+n/k;
		//answers.push_back(ans);
		ans=1;
	}
	sort(answers.begin(),answers.end());
	for (int i=0;i<answers.size();i++)cout<<answers[i]<<" ";
	cout<<endl;
	return 0;
}
