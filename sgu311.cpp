#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define y2 y1919810
typedef pair <int, int> PII;
//#define int long long
#define all(x) (x.begin(),  x.end())
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
	char c = getchar();
	int neg = 1;
	long long val = 0;
	while (c != '-' && !isdigit(c)) c = getchar();
	if (c == '-') c = getchar(), neg = -1;
	while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
	return neg * val;
}
const int N = 100010;
LL cost[N], cnt[N], costsum[N], cntsum[N];
int l[N], r[N];
int aux[N];
int tot;
int node(int v, int c) {
    if (!v) return 0;
    ++tot;
    cost[tot] = c;
    cnt[tot] = v;
    l[tot] = r[tot] = 0;
    costsum[tot] = c * v;
    cntsum[tot] = v;
    return tot;
}
void pushup(int t) {
    costsum[t] = costsum[l[t]] + cost[t] * cnt[t] + costsum[r[t]];
    cntsum[t] = cntsum[l[t]] + cnt[t] + cntsum[r[t]];
}
int merge(int a, int b) {
    if (!a || !b) return a ? a : b;
    if (aux[a] > aux[b]) {
        r[a] = merge(r[a], b);
        pushup(a);
        return a;
    } else {
        l[b] = merge(a, l[b]);
        pushup(b);
        return b;
    }
}
void split1(int t, int k, int& a, int& b) {
    if (!t) {a = b = 0; return;}
    if (cntsum[l[t]] + cnt[t] <= k) {
        a = t;
        split1(r[t], k - cnt[t] - cntsum[l[t]], r[a], b);
        pushup(a);
    } else if (k <= cntsum[l[t]]) {
        b = t;
        split1(l[t], k, a, l[b]);
        pushup(b);
    } else {
        int x = node(cost[t], k - cntsum[l[t]]);
        int y = node(cost[t], cntsum[l[t]] + cnt[t] - k);
        a = merge(l[t], x); b = merge(r[t], y);
    }
}
void split2(int t, int v, int &a, int &b) {
    if (!t) { a = b = 0; return; }
    if (cost[t] <= v) {
        a = t;
        split2(r[t], v, r[a], b);
        pushup(a);
    } else {
        b = t;
        split2(l[t], v, a, l[b]);
        pushup(b);
    }
}
int root;
void add(int v, int c) {
    int l, r;
    split2(root, c, l, r);
    int x = node(v, c);
    root = merge(merge(l, r), x);
}
bool ask(int n, LL t) {
    int l, r;
    split1(root, n, l, r);
    if (cntsum[l] < n //not enough ice cream
     || costsum[l] > t) {  //not enough money
        root = merge(l, r); //merge it back
        return false;
    }
    else {
        root = r; // erase lson
        return true;
    }
}
int main() {
	srand(time(NULL));
	string s; 
	rep(i, N) aux[i] = rand();
	int query_id = 0;
	while (cin >> s) {
	    if (s == "ARRIVE") {
	        int n = qread(), c = qread();
	        add(n, c);
	    }
	    else {
	        int n = qread(), t = qread();
	        if (ask(n, t)) cout << "HAPPY" << endl;
	        else cout << "UNHAPPY" << endl;
	    }
	    cerr << "DONE ON QUERY " << ++query_id << endl;
	}
	return 0;
}