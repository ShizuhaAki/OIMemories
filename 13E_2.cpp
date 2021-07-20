#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define y2 y1919810
typedef pair <int, int> PII;
//#define int long long
#define all(x) x.begin(),  x.end()
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
int a[N], n, m;    
int BL;    // block length
int nxt[N], c[N];    // next stop and number of jumps
int st[N], ed[N];    // block start/block end
int which[N];
int ans_last, ans_tot;    // ans1 <- last landpoint, ans2 <- total number of jumps made
void init() {    // init blocks
    repn(i, BL) {
        st[i] = (n / BL) * (i - 1) + 1;
        ed[i] = (n / BL) * i;
    }
    ed[BL] = n;
    repn(i, BL) range(j, st[i], ed[i]) which[j] = i;
    repn(i, BL)
        for (int j = ed[i]; j >= st[i]; j--) {
            if (a[j] + j > ed[i]) {
                c[j] = 1;
                nxt[j] = a[j] + j;
            } else {    // we are still in our block
                c[j] = 1 + c[a[j] + j];
                nxt[j] = nxt[j + a[j]];
            }
        }
}
void query(int pos) {
    int d = 0;
    // jump till the end
    for (int i = pos; i <= n; i = nxt[i]) {
//       fprintf(stderr, "Moved to %d\n", i);
        d += c[i];
        ans_last = i;
    }
//    fprintf(stderr, "Starting second-phase movements\n");
    for (int i = ans_last; i <= n; i += a[i]) {
//        fprintf(stderr, "Moved to %d\n", i);
        if (i + a[i] > n) ans_last = i;
    }
    ans_tot = d;
}
void modify(int pos, int v) {
    a[pos] = v;
    int i = which[pos];
    for (int j = pos; j >= st[i]; j--) {
        if (a[j] + j > ed[i]) {
            c[j] = 1;
            nxt[j] = a[j] + j;
        } else {    // we are still in our block
            c[j] = 1 + c[a[j] + j];
            nxt[j] = nxt[j + a[j]];
        }
    }
}
void solve() {
    n = qread(); BL = sqrt(n);
    m = qread();
    repn(i, n) a[i] = qread();
    init();
    while (m--) {
        int op = qread();
        if (op == 1) {
            int pos = qread();
            query(pos);
            printf("%d %d\n", ans_last, ans_tot);
        } else {
            int pos = qread(), v = qread();
            modify(pos, v);
        }
    }
}
int main() {
    int T = 1;
    //T = qread();
    while (T--) solve();
    return 0;
}
