#include <bits/stdc++.h>
using namespace std;
long long Stack[100010];
int top = 0;
const long long LIMIT = 4294967295LL;
long long total;
void debug()
{
	for (int i = 0; i < top; i++)cerr << Stack[i] << " ";
	cerr << endl;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string command;
		int times;
		cin >> command;
		if (command == "for")
		{
			cin >> times;
			Stack[top++] = times;
		}
		if (command == "add")
		{
			unsigned long long cnt = 1;
			for (int i = 0; i < top; i++)
			{
				cnt *= Stack[i];
				if (cnt > LIMIT)break;
			}
			if (cnt + total > LIMIT)
			{
				puts("OVERFLOW!!!");
				return 0;
			}
			total += cnt;
		} 
		if (command == "end")
		{
			top--;
			Stack[top] = 0;
		}
//		debug();
	}
	cout << total << endl; 
	return 0;
}

