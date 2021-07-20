#include <bits/stdc++.h>
using namespace std;
struct Board
{
	char a[4][4];
	~Board(){}
	Board()
	{
		memset(a, 0, sizeof(a));
	}
	Board(string s)
	{
		assert(s.length() == 9);
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				a[i][j] = s[3 * (i - 1) + j - 1];
	}
	string unfold()const
	{
		string res;
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				res += a[i][j];
		return res;
	}
	bool operator < (const Board b)const
	{
		return (*this).unfold() < b.unfold();
	} 
	int win()
	{
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				if (a[i][j] == '.')return -1;
		for (int i = 1; i <= 3; i++)
		{
			if (a[i][1] == 'X' && a[i][2] == 'X' && a[i][3] == 'X')return 1;
			if (a[i][1] == '0' && a[i][2] == '0' && a[i][3] == '0')return 2;
			if (a[1][i] == 'X' && a[2][i] == 'X' && a[3][i] == 'X')return 1;
			if (a[1][i] == '0' && a[2][i] == '0' && a[3][i] == '0')return 2;
		}
		if (a[1][1] == 'X' && a[2][2] == 'X' && a[3][3] == 'X')return 1;
		if (a[1][3] == 'X' && a[2][2] == 'X' && a[3][1] == 'X')return 1;
		if (a[1][1] == '0' && a[2][2] == '0' && a[3][3] == '0')return 2;
		if (a[1][3] == '0' && a[2][2] == '0' && a[3][1] == '0')return 2;
		return 0;
	}
};
map <Board, string> found;
void dfs(int dep, Board curr, string verdict)
{
	if (!found.count(curr))
		found.insert(make_pair(curr, verdict));
	if (verdict == "draw" || verdict == "the first player won" || verdict == "the second player won")
		return;
	if (dep == 9)return;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			if (curr.a[i][j] != '.')continue;
			if (verdict == "second")
			{
				curr.a[i][j] = '0';
				assert(curr.win() != 1);
				if (curr.win() == 2)dfs(dep + 1, curr, "the second player won");
				if (curr.win() == 0)dfs(dep + 1, curr, "draw");
				if (curr.win() == -1)dfs(dep + 1, curr, "first");
				curr.a[i][j] = '.';
			}
			else if (verdict == "first")
			{
				curr.a[i][j] = 'X';
				assert(curr.win() != 2);
				if (curr.win() == -1)dfs(dep + 1, curr, "second");
				if (curr.win() == 0)dfs(dep + 1, curr, "draw");
				if (curr.win() == 1)dfs(dep + 1, curr, "the first player won");
				curr.a[i][j] = '.';
			}
		}
}
int main()
{
	dfs(1, Board("........."), "first");
	Board input;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> input.a[i][j];
	if (found.count(input))cout << found[input] << endl;
	else cout << "illegal" << endl;
	return 0;
}

