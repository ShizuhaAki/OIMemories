#include <bits/stdc++.h>
using namespace std;
bool win(const string& s, const char c)
{
	for (int i = 0; i < 3; i++)if (s[i * 3] == c and s[i * 3 + 1]== c and s[i * 3 + 2] == c)return true;
	for (int i = 0; i < 3; i++)if (s[i] == c and s[i + 3] == c and s[i + 6] == c)return true;
	if (s[0] == c and s[4] == c and s[8] == c)return true;
	if (s[2] == c and s[4] == c and s[6] == c)return true;
	return false; 
}
string grid = ".........";
unordered_map <string, string> ans;
void dfs(int dep)
{
	if (win(grid, 'X'))
	{
		ans[grid] = "the first player won";
		return;
	}
	else if (win(grid, '0'))
	{
		ans[grid] = "the second player won";
		return;
	}
	else if (dep == 9)
	{
		ans[grid] = "draw";
		return;
	}
	if (dep % 2)ans[grid] = "second";
	else ans[grid] = "first";
	for (int i =  0; i < 9; i++)
	{
		if (grid[i] != '.')continue;
		grid[i] = (dep % 2) ? '0' : 'X';
		dfs(dep + 1);
		grid[i]= '.'; 
	}
}
int main()
{
	dfs(0);
	string s;
	string t;
	for (int i = 1; i <= 3; i++)
	{
		cin >> t;
		s += t;
	}
	if (!ans.count(s))puts("illegal");else puts(ans[s].c_str()); 
	return 0;
}

