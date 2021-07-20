
// Problem: E. Holes
// Contest: Codeforces - Codeforces Beta Round #13
// URL: https://codeforces.com/contest/13/problem/E
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define VPII vector <PII>
#define y2 y1919810
typedef pair <int, int> PII;
typedef vector <int> VI;
//#define int long long
#define all(x) x.begin(),  x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
#define il inline
#define vo void
#define I int
#define RESET(x) memset((x), 0, sizeof(x))
#define au auto

const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
LL qread() {
    char c = getchar();
    int neg = 1;
    LL val = 0;
    while (c != '-' && !isdigit(c)) c = getchar();
    if (c == '-') {
        c = getchar(); 
        neg = -1;
    }
    while (isdigit(c)) {
        val = (val << 3) + (val << 1) + c - '0';
        c = getchar();
    }
    return neg * val;
}
const I N = 100010;
I BL;
I n, m, a[N], bl[N], which[N], blockStart[N], blockEnd[N], cnt[N], nxt[N];
vo init() {
    repn(i, n) {
        blockStart[i] = (n / BL) * (i - 1) + 1;
        blockEnd[i] = (n / BL) * i;
    }
    blockEnd[BL] = n;
    repn(i, BL) range(j, blockStart[i], blockEnd[i]) which[j] = i;
    repn(i, BL)
        for (int j = blockEnd[i]; j >= blockStart[i]; j--) {
            if (a[j] + j > blockEnd[i]) {
                // We are starting a new block
                nxt[j] = a[j] + j;    
 //               fprintf(stderr, "nxt[%d] = %d\n", j, nxt[j]);
                cnt[j] = 1;
            } else {
                // We are still in the current block
                nxt[j] = nxt[a[j] + j];
//                fprintf(stderr, "nxt[%d] = %d\n", j, nxt[j]);
                cnt[j] = 1 + cnt[a[j] + j];
            }
        }
}
vo query(int pos, I& last, I& moves) {
    for (int i = pos; i <= n; i = nxt[i]) {
//        fprintf(stderr, "Moved to %d\n", i);
        moves += cnt[i];
        last = i;
    }
//    fprintf(stderr, "2nd Phase starting\n");
    for (int i = last; i <= n; i += a[i]) {
//        fprintf(stderr, "Moved to %d\n", i);
        if (i + a[i] > n) last = i;
    }
}
vo modify(I pos, I x) {
    a[pos] = x;
    for (int j = pos; j >= blockStart[which[pos]]; j--) {
        if (a[j] + j > blockEnd[which[pos]]) {
            // We are starting a new block
            nxt[j] = a[j] + j;    
            cnt[j] = 1;
        } else {
                // We are still in the current bloc
            nxt[j] = nxt[a[j] + j];
            cnt[j] = 1 + cnt[a[j] + j];
        }
    }
}
vo solve() {
    n = qread(); m = qread();
    repn(i, n) a[i] = qread();
    BL = sqrt(n);
    init();
    while (m--) {
        I op = qread();
        if (op == 0) {
            I pos = qread(), v = qread();
            modify(pos, v);
        } else {
            I pos = qread(), a1, a2; a1 = a2 = 0;
            query(pos, a1, a2);
            printf("%d %d\n", a1, a2);
        }
    }
}
signed main() {
    int T = 1;
    //T = qread();
    while (T--) 
        solve();
    return 0;
}
