#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define pb push_back
#define mp make_pair
#ifdef GRAPH
typedef pair <int, int> Edge;
#define v first
#define w second
#endif
using LL = long long;
using ULL = unsigned long long;
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
#define until(x) while (!x)
#define fail(s) assert(!s)
const int INF = 0x3f3f3f3f;
const int EPS = 1e-6;
const int N = 2002;
int n, k;string grid[N];
#define IT set <node> :: iterator 
struct node
{
    int l,r;
    mutable LL v;
    node(int L, int R=-1, LL V=0):l(L), r(R), v(V) {}
    bool operator<(const node& o) const
    {
        return l < o.l;
    }
};
set<node> s[N * 2];
IT split(int i, int pos)
{
    IT it = s[i].lower_bound(node(pos));
    if (it != s[i].end() && it->l == pos) 
        return it;
    --it;
    int L = it->l, R = it->r;
    LL V = it->v;
    s[i].erase(it);
    s[i].insert(node(L, pos-1, V));
    return s[i].insert(node(pos, R, V)).first;
}
void assign_val(int i, int l, int r, LL val)
{
    IT itr = split(i, r+1),itl = split(i, l);
    s[i].erase(itl, itr);
    s[i].insert(node(l, r, val));
}
LL sum(int i, int l, int r)
{
    IT itr = split(i, r+1),itl = split(i, l);
    LL res = 0;
    for (; itl != itr; ++itl)
        res = (res + (LL)(itl->r - itl->l + 1));
    return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)cin >> grid[i];
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= n; j++) {
    		s[i].insert(node(j, j, grid[i][j] - '0'));
    		s[j].insert(node(i, i, grid[i][j] - '0'));
    	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int res = 0;
			assign_val(i, i, min(i + k, n), 0);
			assign_val(n + j, j, min(j + k, n), 0);
			for (int x = i; x <= min(i + k, n); x++)if (sum(i, 1, n) == 0)res++;
			for (int y = j; y <= min(j + k, n); y++)if (sum(n + j, 1, n) == 0)res++;
			ans = max(ans, res);
		}
	cout << ans << endl;
	return 0;
}

