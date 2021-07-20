#include <bits/stdc++.h>
using namespace std;
int matrix[5222][5222];
unordered_map<char,int> m = {{'0',0},{'1',1},{'2',2},{'3',3},
								   {'4',4},{'5',5},{'6',6},{'7',7},
								   {'8',8},{'9',9},{'A',10},{'B',11},
							       {'C',12},{'D',13},{'E',14},{'F',15}};
int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j += 4)	
		{
			char t;
			cin >> t;
			int dec = m[t];
			matrix[i][j+3] = dec & 1,dec >>= 1;
			matrix[i][j+2] = dec & 1,dec >>= 1;
			matrix[i][j+1] = dec & 1,dec >>= 1;
			matrix[i][j] = dec & 1;
		}
	int ans = 1;
	for (int x = 2; x <= n; x++)
	{
		if (n % x)continue;
		bool flag = true;
		for (int p = 1; p <= n; p += x)
			for (int q = 1; q <= n; q += x)
			{
				int s = matrix[p][q];
				for (int a = p; a < p+x; a++)
					for (int b = q; b < q+x; b++)
						if (matrix[a][b] != s)
						{
							flag = false;
							break; 
						} 
			}
		if (flag)
			ans = x;
	}
	cout << ans << endl;
}
