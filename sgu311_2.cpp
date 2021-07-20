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
struct TreapNode {
    TreapNode *l, *r;
    LL aux, cnt, cost, sum_cost, sum_cnt;
    TreapNode(LL cnt = 0, LL cost = 0): 
        cnt(cnt), cost(cost), aux(rand()), 
        sum_cost(cnt * cost), sum_cnt(cnt),
        l(nullptr), r(nullptr) {}
};
void pushup(TreapNode* t) {
    cerr << "CALLING PUSHUP: " << t << endl;
    cerr << "PUSHUP: t -> l: " << t -> l << endl
         << "PUSHUP: t -> r: " << t -> r << endl;
    if (!(t -> l) || !(t -> r)) return; 
    t -> sum_cost = t -> l -> sum_cost +
                    (t -> cost) * (t -> cnt) +
                    t -> r -> sum_cost;
    t -> sum_cnt = t -> l -> sum_cnt +
                   t -> cnt +
                   t -> r -> sum_cnt;
}
TreapNode* merge(TreapNode* a, TreapNode* b) {
    cerr << "CALLING MERGE: " << a << " " << b << endl; 
    if (!a || !b) return a ? a : b;
    if (a -> aux > b -> aux) {
        a -> r = merge(a -> r, b);
        pushup(a);
        return a;
    } else {
        b -> l = merge(a, b -> l);
        pushup(b);
        return b;
    }
}
void split1(TreapNode* t, int k, TreapNode* &a, TreapNode* &b) {
    cerr << "CALLING SPLIT1: " << a << " " << b << endl; 
    if (!t) {
        a = b = nullptr;
        return;
    }
    if ((t -> l -> sum_cnt) + (t -> cnt) <= k) {    // full blocks
        a = t;
        split1(t -> r, k - (t -> l -> sum_cnt) - (t -> cnt) , a -> r, b);
        pushup(a);
    } else if (k <= t -> l -> sum_cnt) {    // cannot fill up even the lson block
        b = t;
        split1(t -> l, k, a, b -> l);
        pushup(b);
    } else {    //full blocks on lson, but not full on rson
        TreapNode 
        *x = new TreapNode(k - (t -> l -> sum_cnt), t -> cost), 
        *y = new TreapNode((t -> l -> sum_cnt) + t -> cnt - k, t -> cost);
        a = merge(t -> l, x);
        b = merge(y, t -> r);
    }
}
void split2(TreapNode* t, int v, TreapNode *&a, TreapNode *&b) {
    cerr << "CALLING SPLIT2: " << a << " " << b << endl; 
    if (!t) {
        a = b = nullptr;
        return;
    }
    if (t -> cost <= v) {
        a = t;
        split2(t -> r, v, a -> r, b);
        pushup(a);
    } else {
        b = t;
        split2(t -> l, v, a, b -> l);
        pushup(b);
    }
}
// begin the actual solver here
TreapNode *root = nullptr;
void add(int v, int c) {
    TreapNode *l = new TreapNode(), *r = new TreapNode();
    split2(root, c, l, r);
    TreapNode *x = new TreapNode(v, c);
    root = merge(merge(l, r), x);
    cerr << root << endl;
}
bool ask(int n, LL t) {
    TreapNode *l = new TreapNode(), *r = new TreapNode();
    split1(root, n, l, r);
    if (l -> sum_cnt < n //not enough ice cream
     || l -> sum_cost > t) {  //not enough money
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
