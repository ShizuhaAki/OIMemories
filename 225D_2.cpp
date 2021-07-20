#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int (i) = 1; (i) <= (int)n; (i)++)
#define rep(i, n) for (int (i) = 0; (i) < (int)n; (i)++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
const int N = 16;
const int M = 2000200;
const int MOD = 1e7 + 7, P = 239017;
vector <int> state[MOD + 10];
char grid[N][N], cur[N][N];
const int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int n, m;
int x[M][N], y[M][N], len;unsigned int h1[N], h[N]; int sol[N], tarX, tarY;
void getHash(int id) {
	unsigned int res = 0;
	rep(i, len) {
		res = (res * P + x[id][i]) * P + y[id][i];
	}
	h1[id] = res; h[id] = res % MOD;
	assert(h[id] <= MOD); 
}
bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
} 
int main() {
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%s", grid[i]);
	rep(i, n) rep(j, m) {
		char &c = grid[i][j];
		if (isdigit(c)) {
			x[1][c - '1'] = i;
			y[1][c - '1'] = j;
			len = max(len, c - '0');
			//change this point to '.', so that it will be treated as passable
			c = '.';
		}
		if (c == '@') tarX = i, tarY = j;
	}
	int head, tail; head = tail = 1;
	sol[1] = 0; getHash(1);
	state[h[1]].pb(1);
	while (head <= tail) {
		//copy the current state from the input
		rep(i, n) rep(j, m) cur[i][j] = grid[i][j];
		//set the currently occupied places to a (rather random) number
		//so that it will not be mixed up with a normal grid
		rep(i, len - 1) cur[x[head][i]][y[head][i]] = '7';
		//start trying to move to a new grid
		rep(ii, 4) {
			int nx = x[head][0] + dx[ii], ny = y[head][0] + dy[ii];
			if (inRange(nx, ny)) {
				if (nx == tarX && ny == tarY) {
					cout << sol[head] + 1 << endl;
					return 0;
				}
				if (cur[nx][ny] == '.') {
					//copy current head state to a new state
					repn(i, len - 1)
						x[tail + 1][i] = x[head][i - 1],
						y[tail + 1][i] = y[head][i - 1];
					//add the head to the front of the state
					x[tail + 1][0] = nx;
					y[tail + 1][0] = ny;
					//get the hash code for this state
					getHash(tail + 1);
					bool ok = true;
					//check availability
					if (!state[h[tail + 1]].empty()) {
				    	rep(i, state[h[tail + 1]].size()) {
				    		if (h1[state[h[tail + 1]][i]] == h1[tail + 1]) {
				    			ok = false;
			    				break;
			    			}
				    	}
					}
					//move to the next stage
					if (ok) {
						//push the current state into the queue
						tail++;
						//update the best answer
						sol[tail] = sol[head] + 1;
						//push current state to the corresponding vector
						state[h[tail + 1]].pb(tail + 1);
					}
				}
			}			
		}
		//pop the head from the queue
		head++;
	}
	cout << -1 << endl;
	return 0;
}

