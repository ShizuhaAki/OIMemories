#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int C = 4, N = 6e5 + 10;
struct trieNode {
	int son[4];
	bool terminate;
}trie[C * N];
const int root = 0;int cnt = 0, n, m;
void trieInsert(string s) {
	int x = root;
	rep(i, (int)s.length()) {
		int c = s[i] - 'a';
		if (!trie[x].son[c]) trie[x].son[c] = ++cnt;
		x = trie[x].son[c];
	}
	trie[x].terminate = true;
}
bool trieFind(string s) {
	int x = root;
	rep(i, (int)s.length()) {
		int c = s[i] - 'a';
		if (!trie[x].son[c]) return false;
		else x = trie[x].son[c];
	}
	return trie[x].terminate;
}
bool dfs(int u, int p, bool c, string pre, string req) {
	cerr << pre << ' ' << req << endl;
	if (trie[u].terminate && p == req.size() && pre == req) return true;
	rep(i, 3) {
		if (!trie[u].son[i]) continue;
		if (req[p + 1] != i + 'a' && !c) req[p + 1] = dfs(trie[u].son[i], p + 1, 1, pre + (char)(i + 'a'), req);
		else if (req[p + 1] == i + 'a') dfs(trie[u].son[i], p + 1, c, pre + (char)(i + 'a'), req);
		else return false;
	}
	return false;
}
int main() {
	cin >> n >> m;
	repn(i, n) {
		string s;
		cin >> s;
		trieInsert(s);
	}
	while (m--) {
		string q;
		cin >> q;
		bool ok = false;
		if (dfs(0, 0, 0, "", q)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

