#include <bits/stdc++.h>
using namespace std;
vector <int> a;
int divisors[10050];
void get_divisors(int n)
{
	for (int i = 1;i * i <= n;i++)
	{
		if (n % i == 0)
		{
			divisors[i]++;
			if (i != n / i)divisors[n/i]++;
		}
	}
}
int main()
{
	int n,Max = -0x3f3f3f3f;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
		Max = max(x,Max);
	}
	get_divisors(Max);
	int m=-0x3f3f3f3f;
	for (auto p:a)
	{
		if (divisors[p])
		{
			divisors[p]--;
			continue;
		}
		else 
		m = max(m,p);
	}
	cout << Max << " " << m << endl;
	
}
